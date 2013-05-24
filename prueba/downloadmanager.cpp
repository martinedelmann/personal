#include "downloadmanager.h"

#include <QStringList>

DownloadManager::DownloadManager(QObject *parent) :
    QObject(parent)
{
    started = false;
}

void DownloadManager::startDownload()
{
    started = true;
    updateDownloads();
}

void DownloadManager::addPageDownload(QString url, int page)
{
    addDownload(url,Download::pageType,page);
}

void DownloadManager::addFileInfoDownload(QString url)
{
    addDownload(url,Download::fileInfoType,-1);
}

void DownloadManager::addFileDownload(QString url, QString fileName)
{
    addDownload(url,Download::fileType,-1,fileName);
}

void DownloadManager::addDownload(QString url, int type, int page, QString fileName)
{
    Download *newDownload = new Download();
    newDownload->setType(type);
    newDownload->setFileName(fileName);
    newDownload->setUrl(url);
    newDownload->setPage(page);
    queue.enqueue(newDownload);
    updateDownloads();
}

void DownloadManager::updateDownloads()
{
    if (started)
    {
        while (downloadsManagerMap.count() <= MAXSIMULTANEUSDOWNLOADS && !queue.empty())
        {
            Download *newDownload = queue.dequeue();
            QNetworkAccessManager *manager = new QNetworkAccessManager();
            connect(manager,
                    SIGNAL(finished(QNetworkReply*)),
                    this,
                    SLOT(downloadFinish(QNetworkReply*)));
            downloadsManagerMap.insert(newDownload->getUrlString(),manager);
            downloadsMap.insert(newDownload->getUrlString(),newDownload);
            manager->get(QNetworkRequest(newDownload->getUrl()));
        }
    }
}

void DownloadManager::downloadFinish(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    reply->deleteLater();
    if (downloadsMap.contains(reply->request().url().toString()))
    {
        Download *download = downloadsMap.value(reply->request().url().toString());
        int downloadType = download->getType();

        if (downloadType == Download::pageType)
        {
            QString dataString(data);
            emit downloadPageFinish(download->getUrlString(), dataString, download->getPage());
        }
        else if (downloadType == Download::fileInfoType)
        {
            QString location = reply->rawHeader(QByteArray("Location"));
            QString fileName = location.split("/").last();
            addFileDownload(location,fileName);
        }
        else if (downloadType == Download::fileType)
        {
            emit downloadFileFinish(download->getUrlString(),
                                    data,
                                    download->getFileName());
        }

        downloadsManagerMap.remove(download->getUrlString());
        downloadsMap.remove(reply->request().url().toString());
        updateDownloads();
    }
}

#include "downloadmanager.h"

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

void DownloadManager::addDownload(QString url, int page)
{
    Download *newDownload = new Download();
    newDownload->setUrl(url);
    newDownload->setPage(page);
    queue.enqueue(newDownload);
    updateDownloads();
}

void DownloadManager::downloadFinish(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    reply->deleteLater();
    QString dataString(data);

    Download *download = downloadsMap.value(reply->request().url().toString());

    emit downloadFinish(download->getUrlString(), dataString, download->getPage());
    downloadsManagerMap.remove(download->getUrlString());
    downloadsMap.remove(reply->request().url().toString());
    updateDownloads();
}

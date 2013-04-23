#include "downloadmanager.h"

DownloadManager::DownloadManager(QObject *parent) :
    QObject(parent)
{
    started = false;
}

void DownloadManager::startDownload()
{
//    qDebug("DownloadManager::startDownload()");
    started = true;
    updateDownloads();
}

void DownloadManager::updateDownloads()
{
//    qDebug("DownloadManager::updateDownloads()");
    if (started)
    {
        while (downloadsMap.count() <= MAXSIMULTANEUSDOWNLOADS && !queue.empty())
        {
            Download *newDownload = queue.dequeue();
            QNetworkAccessManager *manager = new QNetworkAccessManager();
            connect(manager,
                    SIGNAL(finished(QNetworkReply*)),
                    this,
                    SLOT(downloadFinish(QNetworkReply*)));
            downloadsMap.insert(newDownload->getUrlString(),manager);
//            qDebug("get:%s",newDownload->getUrlString().toStdString().c_str());
            manager->get(QNetworkRequest(newDownload->getUrl()));
        }
    }
}

void DownloadManager::addDownload(QString url)
{
//    qDebug("DownloadManager::addDownload:%s",url.toStdString().c_str());
    Download *newDownload = new Download();
    newDownload->setUrl(url);
    queue.enqueue(newDownload);
    updateDownloads();
}

void DownloadManager::downloadFinish(QNetworkReply *reply)
{
//    qDebug("DownloadManager::downloadFinish:%s",reply->request().url().toString().toStdString().c_str());

    QByteArray data = reply->readAll();
    reply->deleteLater();
    QString dataString(data);

    emit downloadFinish(reply->request().url().toString(),dataString);
    downloadsMap.remove(reply->request().url().toString());
}

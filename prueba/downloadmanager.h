#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>
#include <QQueue>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMap>

#include "download.h"

#define MAXSIMULTANEUSDOWNLOADS 10

class DownloadManager : public QObject
{
    Q_OBJECT
public:
    explicit DownloadManager(QObject *parent = 0);

    void startDownload();
    void addDownload(QString url, int page);

private:
    QQueue<Download*> queue;
    QMap<QString,QNetworkAccessManager*> downloadsManagerMap;
    QMap<QString,Download*> downloadsMap;

    bool started;

    void updateDownloads();

signals:
    void downloadPageFinish(QString url, QString data, int page);
    void downloadFileFinish(QString url, QByteArray data, QString fileName);

public slots:
private slots:
    void downloadFinish(QNetworkReply* reply);
};

#endif // DOWNLOADMANAGER_H

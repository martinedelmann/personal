#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QString>
#include <QUrl>

class Download
{
public:
    Download();

    void setUrl(QString url);
    QString getUrlString();
    QUrl getUrl();

private:
    QString url;
};

#endif // DOWNLOAD_H

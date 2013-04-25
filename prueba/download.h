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

    void setPage(int param);
    int getPage();
private:
    QString url;
    int page;
};

#endif // DOWNLOAD_H

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

    void setType(int type);
    int getType();

    void setFileName(QString fileName);
    QString getFileName();

    enum type {
        pageType,
        fileInfoType,
        fileType,
    };

private:
    QString url;
    QString fileName;
    int page;
    int type;
};

#endif // DOWNLOAD_H

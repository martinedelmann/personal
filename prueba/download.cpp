#include "download.h"

Download::Download()
{
}

void Download::setUrl(QString url)
{
    this->url = url;
}

QString Download::getUrlString()
{
    return url;
}

QUrl Download::getUrl()
{
    return QUrl(url);
}

void Download::setPage(int param)
{
    page = param;
}

int Download::getPage()
{
    return page;
}

void Download::setType(int type)
{
    this->type = type;
}

int Download::getType()
{
    return type;
}

void Download::setFileName(QString fileName)
{
    this->fileName = fileName;
}

QString Download::getFileName()
{
    return fileName;
}

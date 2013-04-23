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

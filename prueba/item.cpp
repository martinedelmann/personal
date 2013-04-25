#include "item.h"

Item::Item()
{
}

void Item::setTittle(QString param)
{
    title = param;
}

void Item::setId(int param)
{
    id = param;
}

void Item::setDownloadUrl(QString param)
{
    downloadURL = param;
}

int Item::getId()
{
    return id;
}

QString Item::getTittle()
{
    return title;
}

QString Item::getDownloadUrl()
{
    return downloadURL;
}

#include "parser.h"

Parser::Parser(QString url, QString rawData) :
    QThread()
{
    this->url = url;
    this->rawData = rawData;
}

void Parser::parse()
{
    qDebug("Parser::parse()");

    QString tempData;

    int startIndex;
    int endIndex;

    startIndex = rawData.indexOf("<div class=\"pagination\">");

    tempData = rawData.right(startIndex);
    endIndex = tempData.indexOf("</div>");
    tempData = tempData.left(endIndex);

    qDebug("tempData:%s",tempData.toStdString().c_str());

    emit parseDone(url);
}

QString Parser::getUrl()
{
    return url;
}

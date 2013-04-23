#include "parsermanager.h"

ParserManager::ParserManager(QObject *parent) :
    QObject(parent)
{
    started = false;
}

void ParserManager::startParse()
{
//    qDebug("ParserManager::startParse()");
    started = true;
    updateParser();
}

void ParserManager::updateParser()
{
//    qDebug("ParserManager::updateParser()");
    if (started)
    {
//        qDebug("- is started ");
        while (parsersMap.count() <= MAX_SIMULTANEUS_PARSERS && !queue.empty())
        {
//            qDebug("- parse executed");
            Parser *newParser = queue.dequeue();
            connect(newParser,
                    SIGNAL(parseDone(QString)),
                    this,
                    SLOT(parsFinish(QString)));
//            qDebug("- newParser url:%s",newParser->getUrl().toStdString().c_str());
            parsersMap.insert(newParser->getUrl(),newParser);
            newParser->parse();
        }
    }
}

void ParserManager::addParse(QString url, QString rawData)
{
//    qDebug("ParserManager::addParse(QString rawData)");

    Parser *newParser = new Parser(url,rawData);

    queue.enqueue(newParser);
    updateParser();
}

void ParserManager::parsFinish(QString url)
{
//    qDebug("ParserManager::parsFinish(QString url)");
    parsersMap.remove(url);
    updateParser();
}

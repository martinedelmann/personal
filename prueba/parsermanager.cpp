#include "parsermanager.h"

ParserManager::ParserManager(QObject *parent) :
    QObject(parent)
{
    started = false;
}

void ParserManager::startParse()
{
    started = true;
    updateParser();
}

void ParserManager::updateParser()
{
    if (started)
    {
        while (parsersMap.count() <= MAX_SIMULTANEUS_PARSERS && !queue.empty())
        {
            Parser *newParser = queue.dequeue();
            connect(newParser,
                    SIGNAL(parseDone(QString)),
                    this,
                    SLOT(onParsFinish(QString)));
            parsersMap.insert(newParser->getUrl(),newParser);
            newParser->parse();
        }
    }
}

void ParserManager::addParse(QString url, QString rawData, int page)
{
    Parser *newParser = new Parser(url,rawData,page);

    queue.enqueue(newParser);
    updateParser();
}

void ParserManager::onParsFinish(QString url)
{
    Parser *newParser = parsersMap.value(url);
    emit parseFinish(url, newParser->getPage(), newParser->getItems(), newParser->getNumberOfPages());
    parsersMap.remove(url);
    updateParser();
}

#ifndef PARSERMANAGER_H
#define PARSERMANAGER_H

#include <QObject>
#include <QQueue>
#include <QMap>

#include "parser.h"

#define MAX_SIMULTANEUS_PARSERS 10

class ParserManager : public QObject
{
    Q_OBJECT
public:
    explicit ParserManager(QObject *parent = 0);
    
    void startParse();
    void addParse(QString url, QString rawData, int page);

private:
    QQueue<Parser*> queue;
    QMap<QString,Parser*> parsersMap;

    bool started;

    void updateParser();

public slots:
    void onParsFinish(QString url);

signals:
    void parseFinish(QString url, int page, QVector<Item> items, int numberOfPages);
signals:
};

#endif // PARSERMANAGER_H

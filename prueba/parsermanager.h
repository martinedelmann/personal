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
    void addParse(QString url, QString rawData);

private:
    QQueue<Parser*> queue;
    QMap<QString,Parser*> parsersMap;

    bool started;

    void updateParser();

public slots:
    void parsFinish(QString url);

signals:
};

#endif // PARSERMANAGER_H

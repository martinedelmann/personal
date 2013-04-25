#ifndef PARSER_H
#define PARSER_H

#include <QThread>
#include <QVector>

#include "item.h"

class Parser : public QThread
{
    Q_OBJECT
public:
    explicit Parser(QString url, QString rawData, int page);
    
    QString getUrl();
    int getPage();

    int getNumberOfPages();
    QVector<Item> getItems();

    void parse();
private:
    QString url;
    QString rawData;
    int page;

    int numberOfPages;
    QVector<Item> items;

    void parseItems();
    Item getItem(QString param);
signals:
    void parseDone(QString url);

public slots:
    
};

#endif // PARSER_H

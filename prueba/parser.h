#ifndef PARSER_H
#define PARSER_H

#include <QThread>

#include "subitem.h"

class Parser : public QThread
{
    Q_OBJECT
public:
    explicit Parser(QString url, QString rawData);
    
    QString getUrl();

    void parse();
private:
    QString url;
    QString rawData;

signals:
    void parseDone(QString url);

public slots:
    
};

#endif // PARSER_H

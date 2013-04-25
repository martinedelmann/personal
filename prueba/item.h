#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QString>

class Item
{
public:
    Item();

    void setTittle(QString param);
    void setId(int param);
    void setDownloadUrl(QString param);

    int getId();
    QString getTittle();
    QString getDownloadUrl();

private:
    QString title;
    int id;
    QString downloadURL;
};

#endif // ITEM_H

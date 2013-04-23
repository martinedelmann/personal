#ifndef FILE_H
#define FILE_H

#include <QString>

#include "ArchivoBufr.h"

class File
{
public:
    File();

private:
    QString name;

    ArchivoBufr *datosBufr;
};

#endif // FILE_H

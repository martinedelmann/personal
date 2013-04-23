#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QMap>

#include <file.h>
#include <QString>

class FileManager
{
public:
    FileManager();

    bool addFileWithName(QString fileName);
    File getFileWithName(QString fileName);

private:

    QMap<QString,File> fileMap;
};

#endif // FILEMANAGER_H

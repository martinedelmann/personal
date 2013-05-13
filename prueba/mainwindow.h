#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QStandardItemModel>

#include "downloadmanager.h"
#include "parsermanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    DownloadManager *downloadManager;
    ParserManager *parserManager;

    QString urlFirstPart;
    QString urlSecondPart;

    QMap<int,Item> resultItems;

    QStandardItemModel *model;

    int downloadsWaiting;
public slots:
    void onDownloadFinish(QString url, QString data, int page);
    void onParseFinish(QString url, int page, QVector<Item> items, int numberOfPages);

private slots:
    void on_pushButton_clicked();


};

#endif // MAINWINDOW_H

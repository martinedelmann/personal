#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

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
    QSortFilterProxyModel *proxyModel;

    int downloadsWaiting;

public slots:
    void onDownloadPageFinish(QString url, QString data, int page);
    void onDownloadfileFinish(QString url, QByteArray data, QString fileName_p);
    void onParseFinish(QString url, int page, QVector<Item> items, int numberOfPages);

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);
    void on_pushButtonSelectAll_clicked();
    void on_pushButtonSearch_clicked();
    void on_pushButtonUnselectAll_clicked();
    void on_pushButtonDownload_clicked();
    void on_pushButton_clicked();

signals:
    void selectAll();
};

#endif // MAINWINDOW_H

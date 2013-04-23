#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

public slots:
    void downloadFinish(QString url, QString data);

private slots:
    void on_pushButton_clicked();


};

#endif // MAINWINDOW_H

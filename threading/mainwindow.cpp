#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThreadPool>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Work work;
    work.setAutoDelete(false);
    QThreadPool *threadPool = QThreadPool::globalInstance();
    threadPool->start(&work);
    qDebug() << "hello from GUI thread " << QThread::currentThread();
    threadPool->waitForDone();
}

MainWindow::~MainWindow()
{
    delete ui;
}

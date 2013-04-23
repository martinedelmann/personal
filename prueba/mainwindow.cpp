#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    downloadManager = new DownloadManager();
    parserManager = new ParserManager();

    connect(downloadManager,
            SIGNAL(downloadFinish(QString,QString)),
            this,
            SLOT(downloadFinish(QString,QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    downloadManager->addDownload("http://subdivx.com/index.php?buscar=terminator&accion=5&masdesc=&subtitulos=1&realiza_b=1");
    downloadManager->startDownload();
}

void MainWindow::downloadFinish(QString url, QString data)
{
    qDebug("void MainWindow::downloadFinish(QString url, QString data):%s",data.toStdString().c_str());

    ui->plainTextEdit->setPlainText(data);

    parserManager->addParse(url,data);

    parserManager->startParse();
}

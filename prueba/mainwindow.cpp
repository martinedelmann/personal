#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditFolder->setText(QDir::homePath());

    connect(ui->lineEditToken,
            SIGNAL(returnPressed()),
            this,
            SLOT(on_pushButtonSearch_clicked()));

    downloadManager = new DownloadManager();
    parserManager = new ParserManager();

    urlFirstPart = QString("http://subdivx.com/index.php?accion=5&buscar=");
    urlSecondPart = QString("&masdesc=&idusuario=&nick=&oxfecha=&oxcd=&oxdown=&pg=");

    model = new QStandardItemModel();
    proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(model);

    ui->listView->setModel(proxyModel);

    downloadsWaiting = 0;

    connect(downloadManager,
            SIGNAL(downloadPageFinish(QString,QString,int)),
            this,
            SLOT(onDownloadPageFinish(QString,QString,int)));
    connect(downloadManager,
            SIGNAL(downloadFileFinish(QString,QByteArray,QString)),
            this,
            SLOT(onDownloadfileFinish(QString,QByteArray,QString)));
    connect(parserManager,
            SIGNAL(parseFinish(QString, int, QVector<Item>, int)),
            this,
            SLOT(onParseFinish(QString, int, QVector<Item>, int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSearch_clicked()
{
    QString url;

    model->clear();

    QString token = ui->lineEditToken->text();
    token.replace(" ","+");

    url.append(urlFirstPart);
    url.append(token);
    url.append(urlSecondPart);
    url.append(QString::number(1));

    downloadManager->addDownload(url,1);
    downloadManager->startDownload();

    ui->pushButtonSearch->setEnabled(false);
}

void MainWindow::onDownloadPageFinish(QString url, QString data, int page)
{
    parserManager->addParse(url,data,page);

    parserManager->startParse();
}

void MainWindow::onDownloadfileFinish(QString url, QByteArray data, QString fileName_p)
{
    qDebug("bajo:%s",fileName_p.toStdString().c_str());
    QString fileName = fileName_p.split("/").last();
    qDebug("fileName:%s",fileName.toStdString().c_str());
}

void MainWindow::onParseFinish(QString url, int page, QVector<Item> items, int numberOfPages)
{
    QVectorIterator<Item> itr(items);
    while(itr.hasNext())
    {
        Item item = itr.next();
        resultItems.insert(item.getId(),item);

        QStandardItem *modelItem;
        modelItem = new QStandardItem();

        modelItem->setData( item.getTittle(), Qt::DisplayRole );
        modelItem->setData( item.getId(), Qt::UserRole );
        modelItem->setData( item.getDownloadUrl(), Qt::UserRole + 1 );
        modelItem->setEditable( false );
        modelItem->setCheckable(true);
        modelItem->setCheckState(Qt::Unchecked);

        model->appendRow( modelItem );
    }

    if (page == 1)
    {
        if (numberOfPages > 1)
        {
            for (int i = 2; i <= numberOfPages; i++)
            {
                QString url;

                QString token = ui->lineEditToken->text();
                token.replace(" ","+");

                url.append(urlFirstPart);
                url.append(token);
                url.append(urlSecondPart);
                url.append(QString::number(i));

                downloadManager->addDownload(url,i);
                downloadManager->startDownload();
                downloadsWaiting++;
            }
        }
    }
    else
    {
        downloadsWaiting--;
    }

    if (downloadsWaiting <=0)
    {
        ui->pushButtonSearch->setEnabled(true);
    }
}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    QStandardItem *modelItem = model->item(index.row());
}

void MainWindow::on_pushButtonSelectAll_clicked()
{
    for (int i = 0; i < model->rowCount(); i++)
    {
        QStandardItem *modelItem = model->item(i);
        modelItem->setCheckState(Qt::Checked);
    }
}

void MainWindow::on_pushButtonUnselectAll_clicked()
{
    for (int i = 0; i < model->rowCount(); i++)
    {
        QStandardItem *modelItem = model->item(i);
        modelItem->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_pushButtonDownload_clicked()
{
    for (int i = 0; i < model->rowCount(); i++)
    {
        QStandardItem *modelItem = model->item(i);
        if (modelItem->checkState() == Qt::Checked)
        {
            QString url = modelItem->data(Qt::UserRole+1).toString();
            downloadManager->addDownload(url,-1);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString pathName = QFileDialog::getOpenFileName(this,
                                                    tr("Select Folder"),
                                                    ui->lineEditFolder->text(),
                                                    tr("folder (*.)"));
    ui->lineEditFolder->setText(pathName);
}

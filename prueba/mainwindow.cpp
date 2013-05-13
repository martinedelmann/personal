#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    downloadManager = new DownloadManager();
    parserManager = new ParserManager();

    urlFirstPart = QString("http://subdivx.com/index.php?accion=5&buscar=");
    urlSecondPart = QString("&masdesc=&idusuario=&nick=&oxfecha=&oxcd=&oxdown=&pg=");

    model = new QStandardItemModel();

    ui->listView->setModel(model);

    downloadsWaiting = 0;

    connect(downloadManager,
            SIGNAL(downloadFinish(QString,QString,int)),
            this,
            SLOT(onDownloadFinish(QString,QString,int)));
    connect(parserManager,
            SIGNAL(parseFinish(QString, int, QVector<Item>, int)),
            this,
            SLOT(onParseFinish(QString, int, QVector<Item>, int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString url;

    QString token = ui->tokenEditLine->text();
    token.replace(" ","+");

    url.append(urlFirstPart);
    url.append(token);
    url.append(urlSecondPart);
    url.append(QString::number(1));

    downloadManager->addDownload(url,1);
    downloadManager->startDownload();
}

void MainWindow::onDownloadFinish(QString url, QString data, int page)
{
    parserManager->addParse(url,data,page);

    parserManager->startParse();
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
        modelItem->setEditable( false );

        model->appendRow( modelItem );
    }

    if (page == 1)
    {
        if (numberOfPages > 1)
        {
            for (int i = 2; i <= numberOfPages; i++)
            {
                QString url;

                QString token = ui->tokenEditLine->text();
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
//        if (downloadsWaiting == 0)
//        {
//            QMapIterator<int,Item> itr(resultItems);
//            while(itr.hasNext())
//            {
//                Item item = itr.next().value();
//                qDebug("id:%d titl:%s url:%s",item.getId(),
//                       item.getTittle().toStdString().c_str(),
//                       item.getDownloadUrl().toStdString().c_str());
//            }
//        }
    }
}

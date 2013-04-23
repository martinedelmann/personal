#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVector>
#include <QSet>
#include <QDateTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_combineButton_clicked()
{
    QVector<QString> lista;

    lista.append("01");
    lista.append("02");
    lista.append("03");
    lista.append("04");
    lista.append("05");
//    lista.append("06");
//    lista.append("07");
//    lista.append("08");
//    lista.append("09");
//    lista.append("10");
//    lista.append("11");
//    lista.append("12");

    Combiner combinerObj(lista.count());

    QDateTime now = QDateTime::currentDateTime();
    QSet<QString> combinedSetA = combinerObj.combine(lista);
    QDateTime other = QDateTime::currentDateTime();
    qint64 time = now.msecsTo(other);
    qDebug("lista de %d con %d combinations in %d msec",lista.count(), combinedSetA.count(), time);
    qDebug("ncombinations %d count %d",combinerObj.getNCombinatios(),combinerObj.getCount());


    QSetIterator<QString> itr(combinedSetA);
    while (itr.hasNext()) {
        qDebug("%s",itr.next().toStdString().c_str());
    }
}

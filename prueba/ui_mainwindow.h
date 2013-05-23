/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu May 23 16:27:52 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListView *listView;
    QPushButton *pushButtonDownload;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QPushButton *pushButtonSelectAll;
    QPushButton *pushButtonUnselectAll;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_2;
    QLineEdit *lineEditFilter;
    QLineEdit *lineEditToken;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_3;
    QPushButton *pushButtonSearch;
    QPushButton *pushButtonFilter;
    QLineEdit *lineEditFolder;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(531, 512);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 70, 511, 311));
        pushButtonDownload = new QPushButton(centralWidget);
        pushButtonDownload->setObjectName(QString::fromUtf8("pushButtonDownload"));
        pushButtonDownload->setGeometry(QRect(435, 385, 85, 31));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 385, 194, 33));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonSelectAll = new QPushButton(layoutWidget);
        pushButtonSelectAll->setObjectName(QString::fromUtf8("pushButtonSelectAll"));

        formLayout->setWidget(0, QFormLayout::LabelRole, pushButtonSelectAll);

        pushButtonUnselectAll = new QPushButton(layoutWidget);
        pushButtonUnselectAll->setObjectName(QString::fromUtf8("pushButtonUnselectAll"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButtonUnselectAll);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 401, 70));
        formLayout_2 = new QFormLayout(layoutWidget1);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEditFilter = new QLineEdit(layoutWidget1);
        lineEditFilter->setObjectName(QString::fromUtf8("lineEditFilter"));

        formLayout_2->setWidget(1, QFormLayout::SpanningRole, lineEditFilter);

        lineEditToken = new QLineEdit(layoutWidget1);
        lineEditToken->setObjectName(QString::fromUtf8("lineEditToken"));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, lineEditToken);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(420, 0, 101, 70));
        formLayout_3 = new QFormLayout(layoutWidget2);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonSearch = new QPushButton(layoutWidget2);
        pushButtonSearch->setObjectName(QString::fromUtf8("pushButtonSearch"));

        formLayout_3->setWidget(0, QFormLayout::SpanningRole, pushButtonSearch);

        pushButtonFilter = new QPushButton(layoutWidget2);
        pushButtonFilter->setObjectName(QString::fromUtf8("pushButtonFilter"));

        formLayout_3->setWidget(1, QFormLayout::SpanningRole, pushButtonFilter);

        lineEditFolder = new QLineEdit(centralWidget);
        lineEditFolder->setObjectName(QString::fromUtf8("lineEditFolder"));
        lineEditFolder->setGeometry(QRect(210, 385, 171, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 385, 36, 31));
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        listView->raise();
        pushButtonDownload->raise();
        lineEditFolder->raise();
        pushButton->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 531, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButtonDownload->setText(QApplication::translate("MainWindow", "Download", 0, QApplication::UnicodeUTF8));
        pushButtonSelectAll->setText(QApplication::translate("MainWindow", "Select All", 0, QApplication::UnicodeUTF8));
        pushButtonUnselectAll->setText(QApplication::translate("MainWindow", "Unselect All", 0, QApplication::UnicodeUTF8));
        pushButtonSearch->setText(QApplication::translate("MainWindow", "Search", 0, QApplication::UnicodeUTF8));
        pushButtonFilter->setText(QApplication::translate("MainWindow", "Filter", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jul 11 18:01:26 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tabBackup;
    QComboBox *comboBox_backup_plan;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_backup;
    QTextBrowser *textBrowserError;
    QWidget *tab_restore;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(559, 435);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 600, 500));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(20);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tabBackup = new QWidget();
        tabBackup->setObjectName(QString::fromUtf8("tabBackup"));
        comboBox_backup_plan = new QComboBox(tabBackup);
        comboBox_backup_plan->setObjectName(QString::fromUtf8("comboBox_backup_plan"));
        comboBox_backup_plan->setGeometry(QRect(20, 10, 91, 22));
        QFont font1;
        font1.setPointSize(10);
        comboBox_backup_plan->setFont(font1);
        textBrowser = new QTextBrowser(tabBackup);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 40, 551, 161));
        pushButton_backup = new QPushButton(tabBackup);
        pushButton_backup->setObjectName(QString::fromUtf8("pushButton_backup"));
        pushButton_backup->setGeometry(QRect(170, 10, 75, 23));
        pushButton_backup->setFont(font1);
        textBrowserError = new QTextBrowser(tabBackup);
        textBrowserError->setObjectName(QString::fromUtf8("textBrowserError"));
        textBrowserError->setGeometry(QRect(0, 210, 551, 161));
        tabWidget->addTab(tabBackup, QString());
        tab_restore = new QWidget();
        tab_restore->setObjectName(QString::fromUtf8("tab_restore"));
        tabWidget->addTab(tab_restore, QString());
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\351\255\224\345\256\242\347\240\226\345\244\264--\344\273\205\351\231\220\345\206\205\351\203\250\344\275\277\347\224\250", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\350\275\257\344\273\266\345\256\211\350\243\205", 0, QApplication::UnicodeUTF8));
        pushButton_backup->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\244\207\344\273\275", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabBackup), QApplication::translate("MainWindow", "\345\244\207\344\273\275\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_restore), QApplication::translate("MainWindow", "\346\201\242\345\244\215\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

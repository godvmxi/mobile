/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Aug 6 15:27:26 2012
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
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
    QGroupBox *groupBox;
    QComboBox *comboBox_bs_plan_1;
    QLineEdit *lineEdit_start_plan_1;
    QLineEdit *lineEdit_stop_plan_1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_filesize_1;
    QLabel *label_14;
    QComboBox *comboBox_device_1;
    QLabel *label_17;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_bs_plan_2;
    QLineEdit *lineEdit_start_plan_2;
    QLineEdit *lineEdit_stop_plan_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_15;
    QComboBox *comboBox_filesize_2;
    QLabel *label_18;
    QComboBox *comboBox_device_2;
    QGroupBox *groupBox_3;
    QComboBox *comboBox_bs_plan_3;
    QLineEdit *lineEdit_start_plan_3;
    QLineEdit *lineEdit_stop_plan_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_16;
    QComboBox *comboBox_filesize_3;
    QLabel *label_19;
    QComboBox *comboBox_device_3;
    QPushButton *pushButton_build_xml;
    QComboBox *comboBox_encrypt;
    QLineEdit *lineEdit_memory;
    QLabel *label_10;
    QLineEdit *lineEdit_brand;
    QLineEdit *lineEdit_model;
    QLabel *label_11;
    QLabel *label_12;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QLabel *label_13;
    QPushButton *pushButton_para_check;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(831, 509);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 801, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        groupBox->setFont(font);
        comboBox_bs_plan_1 = new QComboBox(groupBox);
        comboBox_bs_plan_1->setObjectName(QString::fromUtf8("comboBox_bs_plan_1"));
        comboBox_bs_plan_1->setGeometry(QRect(420, 40, 61, 22));
        lineEdit_start_plan_1 = new QLineEdit(groupBox);
        lineEdit_start_plan_1->setObjectName(QString::fromUtf8("lineEdit_start_plan_1"));
        lineEdit_start_plan_1->setGeometry(QRect(80, 40, 91, 20));
        lineEdit_stop_plan_1 = new QLineEdit(groupBox);
        lineEdit_stop_plan_1->setObjectName(QString::fromUtf8("lineEdit_stop_plan_1"));
        lineEdit_stop_plan_1->setGeometry(QRect(240, 40, 91, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 61, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(10);
        label->setFont(font1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 40, 61, 16));
        label_2->setFont(font1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 40, 71, 16));
        label_3->setFont(font1);
        comboBox_filesize_1 = new QComboBox(groupBox);
        comboBox_filesize_1->setObjectName(QString::fromUtf8("comboBox_filesize_1"));
        comboBox_filesize_1->setGeometry(QRect(560, 40, 69, 22));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(500, 40, 61, 16));
        label_14->setFont(font1);
        comboBox_device_1 = new QComboBox(groupBox);
        comboBox_device_1->setObjectName(QString::fromUtf8("comboBox_device_1"));
        comboBox_device_1->setGeometry(QRect(680, 40, 111, 22));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(650, 40, 61, 16));
        label_17->setFont(font1);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 180, 801, 81));
        groupBox_2->setFont(font);
        comboBox_bs_plan_2 = new QComboBox(groupBox_2);
        comboBox_bs_plan_2->setObjectName(QString::fromUtf8("comboBox_bs_plan_2"));
        comboBox_bs_plan_2->setGeometry(QRect(420, 40, 61, 22));
        lineEdit_start_plan_2 = new QLineEdit(groupBox_2);
        lineEdit_start_plan_2->setObjectName(QString::fromUtf8("lineEdit_start_plan_2"));
        lineEdit_start_plan_2->setGeometry(QRect(80, 40, 91, 20));
        lineEdit_stop_plan_2 = new QLineEdit(groupBox_2);
        lineEdit_stop_plan_2->setObjectName(QString::fromUtf8("lineEdit_stop_plan_2"));
        lineEdit_stop_plan_2->setGeometry(QRect(240, 40, 91, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 40, 61, 16));
        label_4->setFont(font1);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 40, 61, 16));
        label_5->setFont(font1);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(340, 40, 71, 16));
        label_6->setFont(font1);
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(500, 40, 61, 16));
        label_15->setFont(font1);
        comboBox_filesize_2 = new QComboBox(groupBox_2);
        comboBox_filesize_2->setObjectName(QString::fromUtf8("comboBox_filesize_2"));
        comboBox_filesize_2->setGeometry(QRect(560, 40, 69, 22));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(650, 40, 61, 16));
        label_18->setFont(font1);
        comboBox_device_2 = new QComboBox(groupBox_2);
        comboBox_device_2->setObjectName(QString::fromUtf8("comboBox_device_2"));
        comboBox_device_2->setGeometry(QRect(680, 40, 111, 22));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 290, 801, 81));
        groupBox_3->setFont(font);
        comboBox_bs_plan_3 = new QComboBox(groupBox_3);
        comboBox_bs_plan_3->setObjectName(QString::fromUtf8("comboBox_bs_plan_3"));
        comboBox_bs_plan_3->setGeometry(QRect(420, 40, 61, 22));
        lineEdit_start_plan_3 = new QLineEdit(groupBox_3);
        lineEdit_start_plan_3->setObjectName(QString::fromUtf8("lineEdit_start_plan_3"));
        lineEdit_start_plan_3->setGeometry(QRect(80, 40, 91, 20));
        lineEdit_stop_plan_3 = new QLineEdit(groupBox_3);
        lineEdit_stop_plan_3->setObjectName(QString::fromUtf8("lineEdit_stop_plan_3"));
        lineEdit_stop_plan_3->setGeometry(QRect(240, 40, 91, 20));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 40, 61, 16));
        label_7->setFont(font1);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(180, 40, 61, 16));
        label_8->setFont(font1);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(340, 40, 71, 16));
        label_9->setFont(font1);
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(500, 40, 61, 16));
        label_16->setFont(font1);
        comboBox_filesize_3 = new QComboBox(groupBox_3);
        comboBox_filesize_3->setObjectName(QString::fromUtf8("comboBox_filesize_3"));
        comboBox_filesize_3->setGeometry(QRect(560, 40, 69, 22));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(650, 40, 61, 16));
        label_19->setFont(font1);
        comboBox_device_3 = new QComboBox(groupBox_3);
        comboBox_device_3->setObjectName(QString::fromUtf8("comboBox_device_3"));
        comboBox_device_3->setGeometry(QRect(680, 40, 111, 22));
        pushButton_build_xml = new QPushButton(centralWidget);
        pushButton_build_xml->setObjectName(QString::fromUtf8("pushButton_build_xml"));
        pushButton_build_xml->setGeometry(QRect(510, 410, 91, 31));
        comboBox_encrypt = new QComboBox(centralWidget);
        comboBox_encrypt->setObjectName(QString::fromUtf8("comboBox_encrypt"));
        comboBox_encrypt->setGeometry(QRect(120, 410, 91, 31));
        comboBox_encrypt->setFont(font1);
        lineEdit_memory = new QLineEdit(centralWidget);
        lineEdit_memory->setObjectName(QString::fromUtf8("lineEdit_memory"));
        lineEdit_memory->setGeometry(QRect(230, 40, 81, 20));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(230, 10, 111, 16));
        label_10->setFont(font1);
        lineEdit_brand = new QLineEdit(centralWidget);
        lineEdit_brand->setObjectName(QString::fromUtf8("lineEdit_brand"));
        lineEdit_brand->setGeometry(QRect(10, 40, 71, 20));
        lineEdit_model = new QLineEdit(centralWidget);
        lineEdit_model->setObjectName(QString::fromUtf8("lineEdit_model"));
        lineEdit_model->setGeometry(QRect(120, 40, 81, 20));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(130, 10, 61, 16));
        label_11->setFont(font1);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 10, 81, 16));
        label_12->setFont(font1);
        checkBox_1 = new QCheckBox(centralWidget);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setGeometry(QRect(360, 40, 91, 17));
        checkBox_1->setFont(font1);
        checkBox_1->setChecked(true);
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(480, 40, 81, 17));
        checkBox_2->setFont(font1);
        checkBox_2->setChecked(true);
        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(590, 40, 81, 17));
        checkBox_3->setFont(font1);
        checkBox_3->setChecked(true);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(450, 10, 81, 16));
        label_13->setFont(font1);
        pushButton_para_check = new QPushButton(centralWidget);
        pushButton_para_check->setObjectName(QString::fromUtf8("pushButton_para_check"));
        pushButton_para_check->setGeometry(QRect(310, 410, 91, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 831, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        comboBox_bs_plan_1->setCurrentIndex(4);
        comboBox_filesize_1->setCurrentIndex(2);
        comboBox_device_1->setCurrentIndex(2);
        comboBox_bs_plan_2->setCurrentIndex(4);
        comboBox_filesize_2->setCurrentIndex(2);
        comboBox_device_2->setCurrentIndex(2);
        comboBox_bs_plan_3->setCurrentIndex(4);
        comboBox_filesize_3->setCurrentIndex(2);
        comboBox_device_3->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\351\255\224\345\256\242\345\244\207\344\273\275\347\274\226\350\276\221\345\231\250---\344\273\205\351\231\220\345\206\205\351\203\250\344\275\277\347\224\250", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\244\207\344\273\275\346\226\271\346\241\210\344\270\200", 0, QApplication::UnicodeUTF8));
        comboBox_bs_plan_1->clear();
        comboBox_bs_plan_1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0.5K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100M", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_bs_plan_1->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\345\244\207\344\273\275\345\215\225\344\275\215\357\274\214\346\257\217\344\270\252BLOCK\347\232\204\345\244\247\345\260\217</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineEdit_start_plan_1->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        lineEdit_stop_plan_1->setText(QApplication::translate("MainWindow", "2048", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "block\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        comboBox_filesize_1->clear();
        comboBox_filesize_1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\215\351\231\220", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "64M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "128M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "256M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "512M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1024M", 0, QApplication::UnicodeUTF8)
        );
        label_14->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        comboBox_device_1->clear();
        comboBox_device_1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\206\205\345\255\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\206\205\347\275\256SD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\244\226\347\275\256SD", 0, QApplication::UnicodeUTF8)
        );
        label_17->setText(QApplication::translate("MainWindow", "\344\270\255\350\275\254", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\244\207\344\273\275\346\226\271\346\241\210\344\272\214", 0, QApplication::UnicodeUTF8));
        comboBox_bs_plan_2->clear();
        comboBox_bs_plan_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0.5K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100M", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_bs_plan_2->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\345\244\207\344\273\275\345\215\225\344\275\215\357\274\214\346\257\217\344\270\252BLOCK\347\232\204\345\244\247\345\260\217</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineEdit_start_plan_2->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        lineEdit_stop_plan_2->setText(QApplication::translate("MainWindow", "2048", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "block\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        comboBox_filesize_2->clear();
        comboBox_filesize_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\215\351\231\220", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "64M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "128M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "256M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "512M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1024M", 0, QApplication::UnicodeUTF8)
        );
        label_18->setText(QApplication::translate("MainWindow", "\344\270\255\350\275\254", 0, QApplication::UnicodeUTF8));
        comboBox_device_2->clear();
        comboBox_device_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\206\205\345\255\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\206\205\347\275\256SD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\244\226\347\275\256SD", 0, QApplication::UnicodeUTF8)
        );
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\244\207\344\273\275\346\226\271\346\241\210\344\270\211", 0, QApplication::UnicodeUTF8));
        comboBox_bs_plan_3->clear();
        comboBox_bs_plan_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0.5K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100M", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_bs_plan_3->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\345\244\207\344\273\275\345\215\225\344\275\215\357\274\214\346\257\217\344\270\252BLOCK\347\232\204\345\244\247\345\260\217</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineEdit_start_plan_3->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        lineEdit_stop_plan_3->setText(QApplication::translate("MainWindow", "2048", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "block\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        comboBox_filesize_3->clear();
        comboBox_filesize_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\215\351\231\220", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "64M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "128M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "256M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "512M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1024M", 0, QApplication::UnicodeUTF8)
        );
        label_19->setText(QApplication::translate("MainWindow", "\344\270\255\350\275\254", 0, QApplication::UnicodeUTF8));
        comboBox_device_3->clear();
        comboBox_device_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\206\205\345\255\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\206\205\347\275\256SD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\244\226\347\275\256SD", 0, QApplication::UnicodeUTF8)
        );
        pushButton_build_xml->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220XML", 0, QApplication::UnicodeUTF8));
        comboBox_encrypt->clear();
        comboBox_encrypt->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\212\240\345\257\206\346\226\271\346\241\210\344\270\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\212\240\345\257\206\346\226\271\346\241\210\344\272\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\345\212\240\345\257\206\346\226\271\346\241\210\344\270\211", 0, QApplication::UnicodeUTF8)
        );
        lineEdit_memory->setText(QApplication::translate("MainWindow", "2048", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\206\205\345\255\230(MB)", 0, QApplication::UnicodeUTF8));
        lineEdit_brand->setText(QApplication::translate("MainWindow", "LG", 0, QApplication::UnicodeUTF8));
        lineEdit_model->setText(QApplication::translate("MainWindow", "LU6200", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\223\201\347\211\214", 0, QApplication::UnicodeUTF8));
        checkBox_1->setText(QApplication::translate("MainWindow", "\345\244\207\344\273\275\346\226\271\346\241\210\344\270\200", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindow", "\345\244\207\344\273\275\346\226\271\346\241\210\344\272\214", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("MainWindow", "\345\244\207\344\273\275\346\226\271\346\241\210\344\270\211", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "\345\244\207\344\273\275\346\226\271\346\241\210\344\275\277\350\203\275", 0, QApplication::UnicodeUTF8));
        pushButton_para_check->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\346\243\200\346\237\245", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

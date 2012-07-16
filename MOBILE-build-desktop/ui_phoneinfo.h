/********************************************************************************
** Form generated from reading UI file 'phoneinfo.ui'
**
** Created: Tue Jul 10 17:26:47 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONEINFO_H
#define UI_PHONEINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_phoneInfo
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_show_gif;
    QLabel *label_show_info;

    void setupUi(QDialog *phoneInfo)
    {
        if (phoneInfo->objectName().isEmpty())
            phoneInfo->setObjectName(QString::fromUtf8("phoneInfo"));
        phoneInfo->resize(500, 400);
        phoneInfo->setStyleSheet(QString::fromUtf8("background-image: url(:/wizard/pic/res/backgroudwhite.png);"));
        pushButton = new QPushButton(phoneInfo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 340, 75, 23));
        pushButton_2 = new QPushButton(phoneInfo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 340, 75, 23));
        pushButton_3 = new QPushButton(phoneInfo);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 340, 75, 23));
        pushButton_4 = new QPushButton(phoneInfo);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(380, 340, 75, 23));
        label_show_gif = new QLabel(phoneInfo);
        label_show_gif->setObjectName(QString::fromUtf8("label_show_gif"));
        label_show_gif->setGeometry(QRect(190, 70, 131, 121));
        label_show_info = new QLabel(phoneInfo);
        label_show_info->setObjectName(QString::fromUtf8("label_show_info"));
        label_show_info->setGeometry(QRect(40, 60, 391, 211));

        retranslateUi(phoneInfo);

        QMetaObject::connectSlotsByName(phoneInfo);
    } // setupUi

    void retranslateUi(QDialog *phoneInfo)
    {
        phoneInfo->setWindowTitle(QApplication::translate("phoneInfo", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("phoneInfo", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("phoneInfo", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("phoneInfo", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("phoneInfo", "PushButton", 0, QApplication::UnicodeUTF8));
        label_show_gif->setText(QString());
        label_show_info->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class phoneInfo: public Ui_phoneInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONEINFO_H

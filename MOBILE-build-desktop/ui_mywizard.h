/********************************************************************************
** Form generated from reading UI file 'mywizard.ui'
**
** Created: Wed Jul 11 11:34:12 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIZARD_H
#define UI_MYWIZARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_myWizard
{
public:
    QLineEdit *lineEdit_user;
    QLineEdit *lineEdit_pass;
    QLineEdit *lineEdit_pass_confirm;
    QPushButton *pushButton_register;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_login;
    QLabel *label_show_info;
    QLabel *label_show_gif;
    QPushButton *pushButton_complete;
    QPushButton *pushButton_set_phone;
    QComboBox *comboBox_phone_brife;
    QComboBox *comboBox_phone_detail;
    QLineEdit *lineEdit_other_phone;
    QLineEdit *lineEdit_mail;

    void setupUi(QDialog *myWizard)
    {
        if (myWizard->objectName().isEmpty())
            myWizard->setObjectName(QString::fromUtf8("myWizard"));
        myWizard->resize(500, 400);
        myWizard->setStyleSheet(QString::fromUtf8("background-image: url(:/wizard/pic/res/wizardBackGroud.png);"));
        lineEdit_user = new QLineEdit(myWizard);
        lineEdit_user->setObjectName(QString::fromUtf8("lineEdit_user"));
        lineEdit_user->setGeometry(QRect(50, 90, 141, 31));
        lineEdit_user->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));
        lineEdit_pass = new QLineEdit(myWizard);
        lineEdit_pass->setObjectName(QString::fromUtf8("lineEdit_pass"));
        lineEdit_pass->setGeometry(QRect(260, 90, 141, 31));
        lineEdit_pass->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));
        lineEdit_pass->setEchoMode(QLineEdit::Password);
        lineEdit_pass_confirm = new QLineEdit(myWizard);
        lineEdit_pass_confirm->setObjectName(QString::fromUtf8("lineEdit_pass_confirm"));
        lineEdit_pass_confirm->setGeometry(QRect(260, 150, 141, 31));
        lineEdit_pass_confirm->setEchoMode(QLineEdit::Password);
        pushButton_register = new QPushButton(myWizard);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setGeometry(QRect(50, 330, 91, 31));
        pushButton_exit = new QPushButton(myWizard);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(360, 330, 91, 31));
        pushButton_login = new QPushButton(myWizard);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(200, 330, 91, 31));
        label_show_info = new QLabel(myWizard);
        label_show_info->setObjectName(QString::fromUtf8("label_show_info"));
        label_show_info->setGeometry(QRect(110, 20, 251, 231));
        label_show_gif = new QLabel(myWizard);
        label_show_gif->setObjectName(QString::fromUtf8("label_show_gif"));
        label_show_gif->setGeometry(QRect(370, 10, 131, 121));
        pushButton_complete = new QPushButton(myWizard);
        pushButton_complete->setObjectName(QString::fromUtf8("pushButton_complete"));
        pushButton_complete->setGeometry(QRect(390, 150, 75, 23));
        pushButton_set_phone = new QPushButton(myWizard);
        pushButton_set_phone->setObjectName(QString::fromUtf8("pushButton_set_phone"));
        pushButton_set_phone->setGeometry(QRect(390, 190, 75, 23));
        comboBox_phone_brife = new QComboBox(myWizard);
        comboBox_phone_brife->setObjectName(QString::fromUtf8("comboBox_phone_brife"));
        comboBox_phone_brife->setGeometry(QRect(30, 260, 111, 22));
        comboBox_phone_detail = new QComboBox(myWizard);
        comboBox_phone_detail->setObjectName(QString::fromUtf8("comboBox_phone_detail"));
        comboBox_phone_detail->setGeometry(QRect(190, 260, 111, 22));
        lineEdit_other_phone = new QLineEdit(myWizard);
        lineEdit_other_phone->setObjectName(QString::fromUtf8("lineEdit_other_phone"));
        lineEdit_other_phone->setGeometry(QRect(350, 260, 121, 21));
        lineEdit_mail = new QLineEdit(myWizard);
        lineEdit_mail->setObjectName(QString::fromUtf8("lineEdit_mail"));
        lineEdit_mail->setGeometry(QRect(50, 150, 141, 31));

        retranslateUi(myWizard);

        QMetaObject::connectSlotsByName(myWizard);
    } // setupUi

    void retranslateUi(QDialog *myWizard)
    {
        myWizard->setWindowTitle(QApplication::translate("myWizard", "Dialog", 0, QApplication::UnicodeUTF8));
        lineEdit_user->setText(QApplication::translate("myWizard", "username", 0, QApplication::UnicodeUTF8));
        lineEdit_pass->setText(QApplication::translate("myWizard", "fuck you", 0, QApplication::UnicodeUTF8));
        lineEdit_pass_confirm->setText(QApplication::translate("myWizard", "\347\231\273\351\231\206\347\225\231\347\251\272", 0, QApplication::UnicodeUTF8));
        pushButton_register->setText(QApplication::translate("myWizard", "\345\277\253\351\200\237\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        pushButton_exit->setText(QApplication::translate("myWizard", "\351\200\200        \345\207\272", 0, QApplication::UnicodeUTF8));
        pushButton_login->setText(QApplication::translate("myWizard", "\347\231\273       \351\231\206", 0, QApplication::UnicodeUTF8));
        label_show_info->setText(QString());
        label_show_gif->setText(QString());
        pushButton_complete->setText(QApplication::translate("myWizard", "\345\274\200\345\247\213\344\275\223\351\252\214", 0, QApplication::UnicodeUTF8));
        pushButton_set_phone->setText(QApplication::translate("myWizard", "\350\256\276\347\275\256\346\211\213\346\234\272", 0, QApplication::UnicodeUTF8));
        comboBox_phone_brife->clear();
        comboBox_phone_brife->insertItems(0, QStringList()
         << QString()
        );
#ifndef QT_NO_TOOLTIP
        comboBox_phone_brife->setToolTip(QApplication::translate("myWizard", "\346\211\213\346\234\272\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        comboBox_phone_brife->setWhatsThis(QApplication::translate("myWizard", "\350\277\231\351\207\214\350\276\223\345\205\245\346\211\213\346\234\272\345\236\213\345\217\267", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        comboBox_phone_detail->setToolTip(QApplication::translate("myWizard", "\346\211\213\346\234\272\345\223\201\347\211\214", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineEdit_other_phone->setText(QApplication::translate("myWizard", "\346\262\241\346\234\211\346\211\276\345\210\260\346\210\221\347\232\204\346\211\213\346\234\272", 0, QApplication::UnicodeUTF8));
        lineEdit_mail->setText(QApplication::translate("myWizard", "xxx@xxx.com", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class myWizard: public Ui_myWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIZARD_H

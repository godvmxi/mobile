#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>
#include "mywizard.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
//    phoneInfo info;
//    info.exec();
//    myWizard wizard;
//    if(wizard.exec()==QDialog::Rejected)
//        exit(1);


    MainWindow w;
    w.show();

    return a.exec();
}

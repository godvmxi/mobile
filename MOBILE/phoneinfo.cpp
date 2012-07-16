#include "phoneinfo.h"
#include "ui_phoneinfo.h"
#include <QMovie>
#include <QDebug>

phoneInfo::phoneInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::phoneInfo)
{
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setWindowOpacity(1);

    ui->setupUi(this);
    ui->label_show_gif->setHidden(true);
    ui->label_show_info->setHidden(true);
    QMovie *movie = new QMovie(":/wizard/pic/res/loading1.gif");
    ui->label_show_gif->setMovie(movie);
    qDebug()<<movie->isValid();
//    ui->label->setMinimumSize();
    movie->start();
 //   ui->label->setHidden(true);
}

phoneInfo::~phoneInfo()
{
    delete ui;
}

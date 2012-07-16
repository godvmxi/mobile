#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    if(checkUserProfile("./userProfile.xml") < 0)
//    {

//    }
    ui->setupUi(this);
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowMaximizeButtonHint;
    setWindowFlags(flags); // 设置禁止最大化
    setFixedSize(600,500); // 禁止改变窗口大小。
    pointer = new QProcess(this->parent());
    QString cmd("adb shell su -c \"dd if=/dev/block/mmcblk0 of=/sdcard/001.img bs=1024000 count=2 skip=0\"");
    QStringList par;
    par<<"";



//    connect(this->pointer,SIGNAL(readyReadStandardOutput()),this,SLOT(display()));
//    connect(this->pointer,SIGNAL(readyReadStandardError()),this,SLOT(displayError()));

 //   this->pointer->start(cmd);

    statusBarLabel = new QLabel("hello");
    statusBarLabel->setMinimumSize(100,20);
    ui->statusBar->addWidget(statusBarLabel);
    initPara();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display()
{

    ui->textBrowser->append(QString(pointer->readAllStandardOutput()));

}
void MainWindow::displayError()
{

     ui->textBrowserError->append(QString(pointer->readAllStandardError()));
}


void MainWindow::initPara(void)
{
    QFile file("./cmdlist.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"XML文件打开失败";
        this->statusBarLabel->setText("can't find xml file");
        QMessageBox::critical(NULL,"致命错误", "找不到启动配置文件", QMessageBox::Yes, QMessageBox::Yes);
        //goto ask for new config file,other exit

    }
    qDebug()<<"file open";
 //   QDomDocument doc;
    QString errStr;
    int errLine, errCol;
    // setContent 是将指定的内容指定给QDomDocument 解析，第一参数可以是QByteArray或者是文件名等。
    if(!backupDoc.setContent(&file, false, &errStr, &errLine, &errCol))
    {
        qDebug()<<tr("指定XML内容失败 原因： ") << errStr;
    }
    file.close();
    int default_plan_index = 0;
    QDomElement root = backupDoc.documentElement();

    qDebug()<<"current index :"<<root.attributeNode("default_plan_index").nodeValue();
    default_plan_index = root.attributeNode("default_plan_index").nodeValue().toInt() -1;
    QDomElement child = root.firstChildElement();
    QStringList backupPlan;

    qDebug()<<child.tagName()<<child.attributeNode("name").nodeValue();
    backupPlan << child.attributeNode("name").nodeValue();
    child=child.nextSiblingElement();

    qDebug()<<child.tagName()<<child.attributeNode("name").nodeValue();
    backupPlan << child.attributeNode("name").nodeValue();
    child=child.nextSiblingElement();

    qDebug()<<child.tagName()<<child.attributeNode("name").nodeValue();
    backupPlan << child.attributeNode("name").nodeValue();

    ui->comboBox_backup_plan->insertItems(0,backupPlan);
    qDebug()<<default_plan_index;
    ui->comboBox_backup_plan->setCurrentIndex(default_plan_index);
}
int MainWindow::checkUserProfile(QString profile)
{
    QFile file(profile);
    qDebug()<<"本地profile文件检查";
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"XML文件打开失败";
        this->statusBarLabel->setText("can't find xml file");
        QMessageBox::critical(NULL,"错误", "找不到启动配置文件,进入登陆认证", QMessageBox::Yes, QMessageBox::Yes);
        //goto ask for new config file,other exit
        return -1;
    }
    qDebug()<<profile<< "file open";
 //   QDomDocument doc;
    QString errStr;
    int errLine, errCol;
    // setContent 是将指定的内容指定给QDomDocument 解析，第一参数可以是QByteArray或者是文件名等。
    if(!userProfile.setContent(&file, false, &errStr, &errLine, &errCol))
    {
        qDebug()<<tr("指定XML内容失败 原因： ") << errStr;
    }
    file.close();
    QDomElement node = userProfile.documentElement();
    qDebug()<<node.tagName();
    node = node.firstChildElement();
    int userInfo = 0;

    while(!node.isNull())
    {
        if(node.tagName() == tr("userInfo")){
            qDebug()<<node.attributeNode("userName").nodeValue();
            qDebug()<<node.attributeNode("password").nodeValue();
            qDebug()<<node.attributeNode("email").nodeValue();
            userInfo++;

        }
        if(node.tagName() == tr("phoneInfo")){
            qDebug()<<node.attributeNode("brand").nodeValue();
            qDebug()<<node.attributeNode("model").nodeValue();
            qDebug()<<node.attributeNode("rom").nodeValue();
            userInfo++;
        }
        node = node.nextSiblingElement();
    }
    if(userInfo > 1){
        QMessageBox info;
        info.addButton(QMessageBox::Ok);
        info.setText(tr("请重新输入密码、邮箱,选择对应的手机型号，如果找不到您的手机型号，请选择其他，并且你的其他中表示出的你的手机型号，功能加紧研发中，如果有特殊需求，请邮件联系godvmxi@gmail.com"));
        info.exec();
        return 1;
    }
    else{
        qDebug()<<"user info error";
        return -1;
    }

}



void MainWindow::on_pushButton_backup_clicked()
{
    QDomElement node = backupDoc.documentElement();
    qDebug()<<node.tagName();
    node = node.firstChildElement();
    qDebug()<<node.tagName();
    while(!node.isNull()){
        if(node.attributeNode("name").nodeValue() == ui->comboBox_backup_plan->currentText()){
            qDebug()<<node.attributeNode("name").nodeValue() << node.tagName();
            break;
        }
        node=node.nextSiblingElement();
    }
    if(node.isNull()){
        QMessageBox info;
        info.addButton(QMessageBox::Ok);
        info.setText(tr("找不到备份方案，请升级后尝试"));
        info.exec();
        return ;
    }
    execCmdList(node.firstChildElement());

}
int MainWindow::execCmdList(QDomElement node)
{
    QMessageBox info;
    info.addButton(QMessageBox::Ok);
    info.setText(("开始进行系统备份，请按照提示执行"));
    info.exec();
    QString cmd,errorString;
    int cmdType = 0,errorCheckType=0,timeOut=0;
//    QStringList par;
//    par<<"";
    int checkValue;
    while(!node.isNull()){
        cmd = node.attributeNode("cmd").nodeValue();
        errorString = node.attributeNode("errorString").nodeValue();
        cmdType = node.attributeNode("type").nodeValue().toInt();
        errorCheckType = node.attributeNode("errorCheckType").nodeValue().toInt();
        timeOut = node.attributeNode("timeOut").nodeValue().toInt();
        node = node.nextSiblingElement();
        qDebug()<<cmd <<errorString<<cmdType<<errorCheckType<<timeOut;
        switch(cmdType){
        case 1:
            qDebug()<<"cmd-->" << cmd;
 //           this->pointer->waitForFinished(timeOut*1000);
            this->pointer->start(cmd);
            this->pointer->waitForFinished(timeOut*1000);
            checkValue = this->checkError(errorCheckType,&errorString);
            if(checkValue < 0){
                return checkValue;
            }
            break;
        case 2:
            qDebug()<<"status :"<<cmd;
            break;
        case 3:
            info.setText((cmd));
            info.exec();
            break;
        case 4:

            break;
        default:
            break;
        }
    }
    return 1;
}
int MainWindow::checkError(int type,QString *check)
{
    QMessageBox info;
    QString right,error;
    right = this->pointer->readAllStandardOutput();
    error = this->pointer->readAllStandardError();
    qDebug()<<"std out: "<<right;
    qDebug()<<"err out: "<<error;
    switch(type){
    case 0:
        return 1;
    case 1:
        if(right.contains(*check) == true || error.contains(*check) == true){
            info.setText(("备份命令执行错误，请检查手机连接，重新尝试或者更新备份脚本"));
            info.exec();
            return -1;
        }
        else
            return 1;
    case 2:
        if(right.contains(*check) == false || error.contains(*check) == false){
            info.setText(("备份命令执行错误，请检查手机连接，重新尝试或者更新备份脚本"));
            info.exec();
            return -1;
        }
        else
            return 1;
     default:
        info.setText(("XML脚本错误，请检查脚本参数"));
        info.exec();
        return -1;

    }
}

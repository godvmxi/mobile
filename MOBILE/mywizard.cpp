#include "mywizard.h"
#include "ui_mywizard.h"

myWizard::myWizard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myWizard)
{
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(1);
    ui->setupUi(this);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    ui->label_show_gif->setHidden(true);
    ui->label_show_info->setHidden(true);
    ui->comboBox_phone_brife->setHidden(true);
    ui->comboBox_phone_detail->setHidden(true);
    ui->pushButton_complete->setHidden(true);
    ui->pushButton_set_phone->setHidden(true);
    ui->lineEdit_pass_confirm->setHidden(true);
    ui->lineEdit_other_phone->setHidden(true);
    ui->lineEdit_mail->setHidden(true);
    initSystem();
}

myWizard::~myWizard()
{
    delete ui;
}



void myWizard::on_pushButton_exit_clicked()
{
    this->reject();
}

void myWizard::on_pushButton_register_clicked()
{
    static int passwd = 0;
    if(passwd == 0){
        ui->lineEdit_pass_confirm->setHidden(false);
        ui->lineEdit_mail->setHidden(false);

        ui->pushButton_register->setText(tr("继续注册"));
        ui->pushButton_login->setDisabled(true);
        ui->comboBox_phone_brife->setHidden(false);
        ui->comboBox_phone_detail->setHidden(false);
        ui->lineEdit_other_phone->setHidden(false);


        QMessageBox info;
        info.addButton(QMessageBox::Ok);
        info.setText(tr("请重新输入密码、邮箱,选择对应的手机型号，如果找不到您的手机型号，请选择其他，并且你的其他中表示出的你的手机型号，功能加紧研发中，如果有特殊需求，请邮件联系godvmxi@gmail.com"));
        info.exec();
        passwd = 1;

    }
    else{
        if(ui->lineEdit_user->text() == tr("username")){
            QMessageBox info;
            info.addButton(QMessageBox::Ok);
            info.setText(tr("请输入有效用户名"));
            info.exec();
            return;
        }
        if(ui->lineEdit_pass->text() != ui->lineEdit_pass_confirm->text())
        {
            //wait and register
            qDebug()<<"user :"<<ui->lineEdit_user->text()<<"passwd :"<<ui->lineEdit_pass->text();
            //add register func
            QMessageBox info;
            info.addButton(QMessageBox::Ok);
            info.setText(tr("密码前后不一致"));
            info.exec();
            return;
        }
        if(ui->lineEdit_mail->text() == tr("xxx@xxx.com")){
            QMessageBox info;
            info.addButton(QMessageBox::Ok);
            info.setText(tr("请输入有效邮箱，这关系到今后你享受的服务质量"));
            info.exec();
            return;
        }
        //register func




    }
}


void myWizard::on_pushButton_login_clicked()
{

    this->accept();
}

void myWizard::initSystem(void){
    QFile file("./phone.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"XML文件打开失败";
        QMessageBox::critical(NULL,"致命错误", "找不到启动配置文件", QMessageBox::Yes, QMessageBox::Yes);
        //goto ask for new config file,other exit

    }
    qDebug()<<"file open";
 //   QDomDocument doc;
    QString errStr;
    int errLine, errCol;
    // setContent 是将指定的内容指定给QDomDocument 解析，第一参数可以是QByteArray或者是文件名等。
    if(!phoneDoc.setContent(&file, false, &errStr, &errLine, &errCol))
    {
        qDebug()<<tr("指定XML内容失败 原因： ") << errStr;
    }
    file.close();

    QDomElement root = phoneDoc.documentElement();
    QDomElement child = root;
    qDebug()<<child.tagName();
    child = child.firstChildElement();
    qDebug()<<child.tagName();
    QStringList brand;
    while(!child.isNull()){
        brand << child.attributeNode("brandName").nodeValue();
        qDebug()<<child.attributeNode("brandName").nodeValue() << child.tagName();
        child = child.nextSiblingElement();
    }
    ui->comboBox_phone_brife->addItems(brand);
    connect(ui->comboBox_phone_brife,SIGNAL(currentIndexChanged(int)),this,SLOT(getPhoneModel(int)));


}
void myWizard::getPhoneModel(int index)
{
    qDebug()<<"state change";
    QDomElement child = phoneDoc.documentElement().firstChildElement();
    while(!child.isNull()){
        if(ui->comboBox_phone_brife->currentText() == child.attributeNode("brandName").nodeValue())
            break;
        child = child.nextSiblingElement();
    }
    ui->comboBox_phone_detail->clear();
    if(child.isNull()){
        qDebug()<<"can find the index :"<<ui->comboBox_phone_brife->currentText();
        return ;
    }
    child = child.firstChildElement();
    QStringList brand;
    while(!child.isNull()){
        brand << child.attributeNode("modelName").nodeValue();
        qDebug()<<child.attributeNode("modelName").nodeValue() << child.tagName();
        child = child.nextSiblingElement();
    }
    ui->comboBox_phone_detail->addItems(brand);
}
void myWizard::loginInUser(void){
    qDebug()<<"login in";
}
void myWizard::registerUser(void){

}
void registerUser(void){
    qDebug()<<"register user";

}
void myWizard::registerFunc(void){
    QString username = ui->lineEdit_user->text();
    QString pass = ui->lineEdit_pass->text();
    QString mail = ui->lineEdit_mail->text();
}

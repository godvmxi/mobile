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

        ui->pushButton_register->setText(tr("����ע��"));
        ui->pushButton_login->setDisabled(true);
        ui->comboBox_phone_brife->setHidden(false);
        ui->comboBox_phone_detail->setHidden(false);
        ui->lineEdit_other_phone->setHidden(false);


        QMessageBox info;
        info.addButton(QMessageBox::Ok);
        info.setText(tr("�������������롢����,ѡ���Ӧ���ֻ��ͺţ�����Ҳ��������ֻ��ͺţ���ѡ��������������������б�ʾ��������ֻ��ͺţ����ܼӽ��з��У�����������������ʼ���ϵgodvmxi@gmail.com"));
        info.exec();
        passwd = 1;

    }
    else{
        if(ui->lineEdit_user->text() == tr("username")){
            QMessageBox info;
            info.addButton(QMessageBox::Ok);
            info.setText(tr("��������Ч�û���"));
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
            info.setText(tr("����ǰ��һ��"));
            info.exec();
            return;
        }
        if(ui->lineEdit_mail->text() == tr("xxx@xxx.com")){
            QMessageBox info;
            info.addButton(QMessageBox::Ok);
            info.setText(tr("��������Ч���䣬���ϵ����������ܵķ�������"));
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
        qDebug()<<"XML�ļ���ʧ��";
        QMessageBox::critical(NULL,"��������", "�Ҳ������������ļ�", QMessageBox::Yes, QMessageBox::Yes);
        //goto ask for new config file,other exit

    }
    qDebug()<<"file open";
 //   QDomDocument doc;
    QString errStr;
    int errLine, errCol;
    // setContent �ǽ�ָ��������ָ����QDomDocument ��������һ����������QByteArray�������ļ����ȡ�
    if(!phoneDoc.setContent(&file, false, &errStr, &errLine, &errCol))
    {
        qDebug()<<tr("ָ��XML����ʧ�� ԭ�� ") << errStr;
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

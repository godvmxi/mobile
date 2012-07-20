#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_build_xml->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_build_xml_clicked()
{


    QDomElement root = this->xml.createElement("rootNode");
    this->xml.appendChild(root);
    QDomElement child = xml.createElement("bk_1");
    root.appendChild(child);
    QDomText text = xml.createTextNode("你好\\></\\/，kugou");

    QDomElement element = xml.createElement("cmd");
    child.appendChild(element);

    QDomAttr attr =xml.createAttribute("attr1");
    attr.setNodeValue("attrValue1");
    element.setAttributeNodeNS(attr);
    attr =xml.createAttribute("attr2");
    attr.setNodeValue("attrValue2");
    element.setAttributeNodeNS(attr);
    attr =xml.createAttribute("attr3");
    attr.setNodeValue("attrValue3");
    element.setAttributeNodeNS(attr);


    child = xml.createElement("bk_2");
    root.appendChild(child);


    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "./",
                                                    tr("XML files (*.xml);;all files (*.*)"));
    qDebug()<<fileName;
    QFile *file = new QFile(fileName);
    if(!file->open(QIODevice::ReadWrite)){
        qDebug()<<"文件打开错误";
    }

    QTextStream out(file);
    xml.save(out,4);
    file->close();

}

void MainWindow::on_pushButton_para_check_clicked()
{
    static int state = 0;
    if(state == 0){
        ui->pushButton_build_xml->setEnabled(true);
        ui->pushButton_para_check->setText(tr("解锁参数"));
        if(getParaInfo()  == false )
            return;
        state = 1;
        enableALL(false);


    }
    else{
        ui->pushButton_build_xml->setEnabled(false);
        ui->pushButton_para_check->setText(tr("参数检查"));
        state = 0;
        enableALL(true);

    }
}
void MainWindow::enableALL(bool type){
    ui->checkBox_1->setEnabled(type);
    ui->checkBox_2->setEnabled(type);
    ui->checkBox_3->setEnabled(type);
    ui->comboBox_bs_plan_1->setEnabled(type);
    ui->comboBox_bs_plan_2->setEnabled(type);
    ui->comboBox_bs_plan_3->setEnabled(type);
    ui->comboBox_filesize_1->setEnabled(type);
    ui->comboBox_filesize_2->setEnabled(type);
    ui->comboBox_filesize_3->setEnabled(type);
    ui->lineEdit_start_plan_1->setEnabled(type);
    ui->lineEdit_start_plan_2->setEnabled(type);
    ui->lineEdit_start_plan_3->setEnabled(type);
    ui->lineEdit_stop_plan_1->setEnabled(type);
    ui->lineEdit_stop_plan_2->setEnabled(type);
    ui->lineEdit_stop_plan_3->setEnabled(type);
    ui->lineEdit_brand->setEnabled(type);
    ui->lineEdit_memory->setEnabled(type);
    ui->lineEdit_model->setEnabled(type);
}

bool MainWindow::getParaInfo(void){
    this->mobile.brand = ui->lineEdit_brand->text();
    this->mobile.model = ui->lineEdit_model->text();
    this->mobile.flashSize = ui->lineEdit_memory->text().toInt(0,10)*1024*1024;
    this->mobile.plan1 = ui->checkBox_1->checkState() == Qt::Checked ? true :false;
    this->mobile.plan2 = ui->checkBox_2->checkState() == Qt::Checked ? true :false;
    this->mobile.plan3 = ui->checkBox_3->checkState() == Qt::Checked ? true :false;

    if(this->mobile.plan1){
        this->plan1.start   =   ui->lineEdit_start_plan_1->text().toInt(0,10);
        this->plan1.end     =   ui->lineEdit_stop_plan_1->text().toInt(0,10);
        switch(ui->comboBox_bs_plan_1->currentIndex()){
        case 0:
            this->plan1.block = 512;//0.5K
            break;
        case 1:
            this->plan1.block = 1024;//1k
            break;
        case 2:
            this->plan1.block = 10240;//10k
            break;
        case 3:
            this->plan1.block = 102400;//100k
            break;
        case 4:
            this->plan1.block = 1024000;//1M
            break;
        case 5:
            this->plan1.block = 10240000;//10M
            break;
        case 6:
            this->plan1.block = 102400000;//100M
            break;
        default :
            this->plan1.block = 1024;
        }
        switch(ui->comboBox_filesize_1->currentIndex()){
        case 0:
            this->plan1.fileSize = 1024000*1024000;//无限制
            break;
        case 1:
            this->plan1.fileSize = 1024000*64;//64M
            break;
        case 2:
            this->plan1.fileSize = 1024000*128;//128M
            break;
        case 3:
            this->plan1.fileSize = 1024000*256;//256M
            break;
        case 4:
            this->plan1.fileSize = 1024000*512;//
            break;
        case 5:
            this->plan1.fileSize = 1024000*1024;//
            break;

        default :
            this->plan1.fileSize = 1024000*256;//
            break;
        }
        if(!calPlanData(1))
            return false;
    }

    if(this->mobile.plan2){
        this->plan2.start   =   ui->lineEdit_start_plan_2->text().toInt(0,10);
        this->plan2.end     =   ui->lineEdit_stop_plan_2->text().toInt(0,10);
        switch(ui->comboBox_bs_plan_2->currentIndex()){
        case 0:
            this->plan2.block = 512;//0.5K
            break;
        case 1:
            this->plan2.block = 1024;//1k
            break;
        case 2:
            this->plan2.block = 10240;//10k
            break;
        case 3:
            this->plan2.block = 102400;//100k
            break;
        case 4:
            this->plan2.block = 1024000;//1M
            break;
        case 5:
            this->plan2.block = 10240000;//10M
            break;
        case 6:
            this->plan2.block = 102400000;//100M
            break;
        default :
            this->plan2.block = 1024;
        }
        switch(ui->comboBox_filesize_2->currentIndex()){
        case 0:
            this->plan2.fileSize = 1024000*1024000;//无限制
            break;
        case 1:
            this->plan2.fileSize = 1024000*64;//64M
            break;
        case 2:
            this->plan2.fileSize = 1024000*128;//128M
            break;
        case 3:
            this->plan2.fileSize = 1024000*256;//256M
            break;
        case 4:
            this->plan2.fileSize = 1024000*512;//
            break;
        case 5:
            this->plan2.fileSize = 1024000*1024;//
            break;

        default :
            this->plan2.fileSize = 1024000*256;//
            break;
        }
        if(!calPlanData(2))
            return false;

    }

    if(this->mobile.plan3){
        this->plan3.start = ui->lineEdit_start_plan_3->text().toInt(0,10);
        this->plan3.end     =   ui->lineEdit_stop_plan_3->text().toInt(0,10);
        switch(ui->comboBox_bs_plan_3->currentIndex()){
        case 0:
            this->plan3.block = 512;//0.5K
            break;
        case 1:
            this->plan3.block = 1024;//1k
            break;
        case 2:
            this->plan3.block = 10240;//10k
            break;
        case 3:
            this->plan3.block = 102400;//100k
            break;
        case 4:
            this->plan3.block = 1024000;//1M
            break;
        case 5:
            this->plan3.block = 10240000;//10M
            break;
        case 6:
            this->plan3.block = 102400000;//100M
            break;
        default :
            this->plan3.block = 1024;
        }
        switch(ui->comboBox_filesize_3->currentIndex()){
        case 0:
            this->plan3.fileSize = 1024000*1024000;//无限制
            break;
        case 1:
            this->plan3.fileSize = 1024000*64;//64M
            break;
        case 2:
            this->plan3.fileSize = 1024000*128;//128M
            break;
        case 3:
            this->plan3.fileSize = 1024000*256;//256M
            break;
        case 4:
            this->plan3.fileSize = 1024000*512;//
            break;
        case 5:
            this->plan3.fileSize = 1024000*1024;//
            break;

        default :
            this->plan3.fileSize = 1024000*256;//
            break;
        }
        if(!calPlanData(3))
            return false;
    }
    return true;
}

bool MainWindow::calPlanData(int plan)
{
    FLASH_INFO *des;
    switch(plan){
    case 1:
        des = &this->plan1;
        break;
    case 2:
        des = &this->plan2;
        break;
    case 3:
        des = &this->plan3;
    default:
        return false;
    }
    QMessageBox info;
    info.addButton(QMessageBox::Ok);
    info.setIcon(QMessageBox::Critical);
    info.setWindowTitle("错误");

//    info.addButton(QMessageBox::Ok|QMessageBox::Abort);
    //info.setText(tr("请重新输入密码、邮箱,选择对应的手机型号，如果找不到您的手机型号，请选择其他，并且你的其他中表示出的你的手机型号，功能加紧研发中，如果有特殊需求，请邮件联系godvmxi@gmail.com"));
//    info.exec();
    quint64 tmp;
    if((this->plan1.start * this->plan1.block) > this->mobile.flashSize);
    {

        info.setText("备份开始区域大于总flash大小，请重新设置");
        info.exec();
        return false;
    }
    if(this->plan1.end < this->plan1.start){
        info.setText("开始地址小于结束地址，请重新设置");
        info.exec();
    }
}

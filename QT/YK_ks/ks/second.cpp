#include "second.h"
#include "ui_second.h"
#include <QMessageBox>
#include "third.h"
second::second(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::second)
{
    ui->setupUi(this);
    ui->pushButton_3->setStyleSheet("border-image:url('D:/wd/c++/7.webp')");
    n=0;
    //给登录界面设置标题
    this->setWindowTitle("登录界面");
}

second::~second()
{
    delete ui;
}
//登录按钮对应的槽函数
void second::on_pushButton_clicked()
{
    //获取输入的用户名和密码
    QString name=ui->lineEdit->text();
    QString passwd=ui->lineEdit_2->text();

    //判断用户名和密码
    if(name=="gec" && passwd=="123456")
    {
        //跳到主界面
        third *win=new third;
        win->show();
        this->close();
    }
    else
       //弹出警告盒子
        QMessageBox::warning(this,"错误","你输入的账号密码有误");
}

void second::on_pushButton_3_clicked()
{
    n++;
    if(n%2==1){
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
        ui->pushButton_3->setStyleSheet("border-image:url('D:/wd/c++/7.webp')");
    }
    else{
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
        ui->pushButton_3->setStyleSheet("border-image:url('D:/wd/c++/6.webp')");
    }
}

#include "picture.h"
#include "ui_picture.h"
#include "QDebug"
#include "third.h"
picture::picture(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::picture)
{
    ui->setupUi(this);
    str<<"5.webp"<<"6.webp"<<"7.webp"<<"1.jpeg"<<"1.jpg"<<"1.webp"
      <<"2.jpg"<<"2.webp"<<"3.webp";
    i=0;
    s="border-image:url('D:/wd/c++/";
    n="')";
}

picture::~picture()
{
    delete ui;
}

void picture::on_pushButton_clicked()
{
    i--;
    if(i==-1){
        i=str.length()-1;
    }
    ui->label->setStyleSheet(s+str[i]+n);
}

void picture::on_pushButton_2_clicked()
{
    i++;
    if(i==str.length()){
        i=0;
    }
    ui->label->setStyleSheet(s+str[i]+n);
}



#include "third.h"
#include "ui_third.h"
#include "QDate"
#include "picture.h"


third::third(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::third)
{
    ui->setupUi(this);
    QDate mydate=QDate::currentDate();
    QString str1=mydate.toString();
    ui->lcdNumber->display(str1);
    //设置主界面的标题
    this->setWindowTitle("主界面");
}

third::~third()
{
    delete ui;
}

void third::on_pushButton_clicked()
{
    picture *p=new picture;
    p->show();
    this->close();
}

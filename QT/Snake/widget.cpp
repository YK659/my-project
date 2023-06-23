#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer=new QTimer();
    //定时器timeout信号
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
    resize(this->width(),this->height());
    //初始化蛇
    QRect rect(300,180,nodeWidth,nodeWidth);
    snake.append(rect);
    addTop();
    addTop();
    //初始化蛇
    addNewReward();

}

Widget::~Widget()
{
    delete ui;
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Up:
        if(moveFlag!=DIR_DOWN){
            moveFlag=DIR_UP;
        }
        break;
    case Qt::Key_Down:
        if(moveFlag!=DIR_UP){
            moveFlag=DIR_DOWN;
        }
        break;
    case Qt::Key_Left:
        if(moveFlag!=DIR_RIGHT){
            moveFlag=DIR_LEFT;
        }
        break;
    case Qt::Key_Right:
        if(moveFlag!=DIR_LEFT){
            moveFlag=DIR_RIGHT;
        }
        break;
    case Qt::Key_Space:
        if(gameStrat==false){
            gameStrat=true;
            timer->start(time);
        }else{
            gameStrat=false;
            timer->stop();
        }
        break;
    default:
        break;
    }
}
void Widget::timeout()
{
    //判断重合
    int count=1;
    if(snake[0].intersects(rewardNode)){
        count++;
        addNewReward();
    }
    while(count--){
        switch(moveFlag){
        case DIR_UP:
            addTop();
            break;
        case DIR_LEFT:
            addLeft();
            break;
        case DIR_DOWN:
            addDown();
            break;
        case DIR_RIGHT:
            addRight();
            break;
        default:
            break;
        }
    }
    deleteLast();
    update();
}
void Widget::addTop()
{
    QPointF leftTop;
    QPointF rightBottom;

    if(snake[0].y()-nodeHeight<0){
        leftTop=QPoint(snake[0].x(),this->height() - nodeHeight);
        rightBottom=QPointF(snake[0].x()+nodeWidth,this->height());
    }else{
        leftTop=QPointF(snake[0].x(),snake[0].y()-nodeHeight);
        rightBottom=snake[0].topRight();
    }
    snake.insert(0,QRectF(leftTop,rightBottom));
}
void Widget::addDown()
{
    QPointF leftTop;
    QPointF rightBottom;
    if(snake[0].y()+nodeHeight*2>this->height()){
        leftTop=QPointF(snake[0].x(),0);
        rightBottom=QPointF(snake[0].x()+nodeWidth,nodeHeight);
    }else{
        leftTop=snake[0].bottomLeft();
        rightBottom=snake[0].bottomRight()+QPointF(0,nodeHeight);
    }
    snake.insert(0,QRectF(leftTop,rightBottom));

}
void Widget::addLeft()
{
    QPointF leftTop;
    QPointF rightBottom;
    if(snake[0].x()-nodeWidth<0){
        leftTop=QPointF(this->width()-nodeWidth,snake[0].y());
        rightBottom=leftTop+QPointF(nodeWidth,nodeHeight);
    }else{
        leftTop=snake[0].topLeft()-QPointF(nodeWidth,0);
        rightBottom=leftTop+QPointF(nodeWidth,nodeHeight);
    }

    snake.insert(0,QRectF(leftTop,rightBottom));
}
void Widget::addRight()
{
    QPointF leftTop;
    QPointF rightBottom;
    if(snake[0].x()+nodeWidth*2>this->width()){
        leftTop=QPointF(0,snake[0].y());
    }else{
        leftTop=snake[0].topRight();
    }
    rightBottom=leftTop+QPointF(nodeWidth,nodeHeight);
    snake.insert(0,QRectF(leftTop,rightBottom));
}
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QBrush brush;
    //背景
    QPixmap pix;
    pix.load(":/images/images/9.webp");
    painter.drawPixmap(0,0,600,368,pix);
    //画蛇
    pen.setColor(Qt::black);
    brush.setColor(Qt::darkMagenta);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    for(int i=0;i<snake.length();i++){
        painter.drawRect(snake[i]);
    }

    //画奖品
    pen.setColor(Qt::red);
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(rewardNode);

    if(checkContact()){
        QFont font("宋体",30,QFont::ExtraLight,false);
        painter.setFont(font);
        painter.drawText((this->width()-300)/2,
                         (this->height()-30/2),
                         QString("game voer"));
        timer->stop();
    }



    QWidget::paintEvent(event);


}
void Widget::deleteLast()
{
    snake.removeLast();
}
void Widget::addNewReward()
{
    rewardNode=QRectF(qrand()%(this->width()/20)*20,
                      qrand()%(this->height()/20)*20,
                      nodeWidth,nodeHeight);
}
bool Widget::checkContact()
{
    for(int i=0;i<snake.length();i++)
        for(int j=i+1;j<snake.length();j++)
        {
            if(snake[i]==snake[j]){
                return true;
            }
        }
    return false;
}

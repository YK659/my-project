#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtEvents>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

typedef enum Direct{
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP,
    DIR_DOWN
} dir_t;

//0.表示蛇
//  0.1
//1.按键处理
//2.定时器
//  2.1关联信号槽
//  2.2启动定时器
//  2.3实现槽函数
//3.渲染
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:

    //绘图
    void paintEvent(QPaintEvent *event);
    bool checkContact();
    void addTop();

    void addDown();

    void addLeft();

    void addRight();

    //添加奖品
    void addNewReward();

    void deleteLast();

    void keyPressEvent(QKeyEvent *event);


private:
    Ui::Widget *ui;
    int moveFlag=DIR_UP;
    bool gameStrat=false;
    QTimer *timer;
    int time=50;//超时时间间隔，毫秒

    QList <QRectF> snake;
    QRectF rewardNode;

    int nodeWidth=20;
    int nodeHeight=20;

protected slots:
    void timeout();
};
#endif // WIDGET_H

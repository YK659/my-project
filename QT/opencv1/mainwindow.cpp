#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Mat image=imread("D:/wd/cxcy4.jpg",1);//一定要使用绝对路径，其他可以回报错
    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow("Display window", image );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tt()
{

}


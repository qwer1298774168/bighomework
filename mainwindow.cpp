#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<Qpainter>
#include "button1.h"
#include"button2.h"
#include<QDebug>
#include<QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1200,800);
    //开始按钮的设置
    Button1 * start = new Button1(":/mode/play1.png",":/mode/play2.png");
    start ->setParent(this);
    //开始按钮的位置
    start ->move(800,250);
    choose= new Choose;
    //延时进入到下一个场景
    connect(start,&Button1::clicked,[=](){

          //进入下一个场景
          QTimer::singleShot(500,this,[=](){
              this->hide();
              choose ->show();
          });
    });
    //设置进入规则界面的按钮
    Button2 * rule1 = new Button2(":/mode/rule1.png",":/mode/rule2.png");
    rule1->setParent(this);
    rule1->move(800,400);
    rule=new Rule;
    //进入规则界面
    connect(rule1,&Button2::clicked,[=](){
        QTimer::singleShot(500,this,[=](){
            this->hide();
            rule->show();
        });
    });

}
//背景图片的设置
void MainWindow::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QPixmap back;
   //加载图片
   back.load(":/mode/start.jpg");
   //绘制图片
   painter.drawPixmap(0,0,this->width(),this->height(),back);
}



MainWindow::~MainWindow()
{
    delete ui;
}

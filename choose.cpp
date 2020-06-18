#include "choose.h"
#include<QPainter>
#include"button1.h"
#include<QTimer>
#include<QDebug>
Choose::Choose(QWidget *parent) : QMainWindow(parent)
{
    //选择关卡
    this->setFixedSize(1200,800);
    //设置选择关卡的图标
    Button1 * hard= new Button1(":/mode/hard2.png");
    hard->setParent(this);
    hard->move(775,250);
    Button1 *easy=new Button1(":/mode/easy.png");
    easy->setParent(this);
    easy->move(0,250);
    easylevel=new Easylevel;
    connect(easy,&Button1::clicked,[=](){
          easy->tiao();
          easy->jiang();
          //进入下一个场景
          QTimer::singleShot(500,this,[=](){

              this->hide();
              easylevel->show();
          });
    });
    hardlevel=new Hardlevel;
    connect(hard,&Button1::clicked,[=](){
          hard->tiao();
          hard->jiang();
          //进入下一个场景
          QTimer::singleShot(500,this,[=](){

              this->hide();
              hardlevel ->show();
          });
    });

}
void Choose::paintEvent(QPaintEvent *){
    //进入关卡选择页面
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/mode/start2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}

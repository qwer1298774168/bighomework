#include "choose.h"
#include<QPainter>
#include"button1.h"
#include<QTimer>
#include<QDebug>
Choose::Choose(QWidget *parent) : QMainWindow(parent)
{
    //ѡ��ؿ�
    this->setFixedSize(1200,800);
    //����ѡ��ؿ���ͼ��
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
          //������һ������
          QTimer::singleShot(500,this,[=](){

              this->hide();
              easylevel->show();
          });
    });

}
void Choose::paintEvent(QPaintEvent *){
    //����ؿ�ѡ��ҳ��
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/mode/start2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}

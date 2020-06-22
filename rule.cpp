#include "rule.h"
#include"button3.h"
#include<QTimer>
#include<QMouseEvent>
Rule::Rule(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1200,800);
    Button3* back= new Button3(":/mode/back1.png",":/mode/back2.png");
    back->setParent(this);
    back->move(750,490);

    connect(back,&Button3::clicked,[=](){
        QTimer::singleShot(500,this,[=](){
            emit this->ruleback();

        });
    });
}

void Rule::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap back;
    back.load(":/mode/rule.png");
    painter.drawPixmap(0,0,this->width(),this->height(),back);
    painter.drawPixmap(200,600,100,100,QPixmap(":/mode/huajitower.png"));
    painter.drawPixmap(550,600,100,100,QPixmap(":/mode/dogetower.png"));
    painter.drawPixmap(850,600,100,100,QPixmap(":/mode/dogetower2.png"));
}

#include "hardlevel.h"
#include<QPainter>
Hardlevel::Hardlevel(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1200,800);
}
void Hardlevel::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/mode/map3.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

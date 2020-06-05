#include "button2.h"
#include<QPropertyAnimation>
Button2::Button2(QWidget *parent) : QPushButton(parent)
{

}
Button2::Button2(QString normal, QString press)

{
    this->normal1=normal;
    this->press1=press;
    QPixmap pix;
    pix.load(normal);
    //��ť�ľ������������
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    //���ð�ť��С
    this->setIconSize(QSize(pix.width(),pix.height()));

}
void Button2::mousePressEvent(QMouseEvent *e)
{
    if(this->press1!=""){
        QPixmap pix;
        pix.load(":/mode/rule2.png");
        //��ť�ľ������������
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        //���ð�ť��С
        this->setIconSize(QSize(pix.width(),pix.height()));

    }
    return QPushButton::mousePressEvent(e);
}
void Button2::mouseReleaseEvent(QMouseEvent *e){
    if(this->press1!=""){
        QPixmap pix;
        pix.load(":/mode/rule1.png");
        //��ť�ľ������������
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        //���ð�ť��С
        this->setIconSize(QSize(pix.width(),pix.height()));

    }
    return QPushButton::mouseReleaseEvent(e);
}

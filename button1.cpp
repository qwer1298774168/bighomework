#include "button1.h"
#include<QPropertyAnimation>
Button1::Button1(QWidget *parent) : QPushButton(parent)
{

}
Button1::Button1(QString normal, QString press)

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
    this->setIconSize(QSize(500,500));

}
void Button1::mousePressEvent(QMouseEvent *e)
{
    if(this->press1!=""){
        QPixmap pix;
        pix.load(":/mode/play2.png");
        //��ť�ľ������������
        this->setFixedSize(start2.width(),start2.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(start2);
        //���ð�ť��С
        this->setIconSize(QSize(start2.width(),start2.height()));

    }
    return QPushButton::mousePressEvent(e);
}
void Button1::mouseReleaseEvent(QMouseEvent *e){
    if(this->press1!=""){
        QPixmap pix;
        pix.load(":/mode/play1.png");
        //��ť�ľ������������
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        //���ð�ť��С
        this->setIconSize(QSize(pix.width(),pix.height()));

    }
    return QPushButton::mouseReleaseEvent(e);
}
//������Ч
void Button1::tiao(){
    //������������
    QPropertyAnimation * animation =new QPropertyAnimation(this,"geometry");
    //���ö���ʱ����
    animation->setDuration(200);
    //��ʼλ��
    animation->setStartValue (QRect(this->x(),this->y(),this->width(),this->height()));
    //����λ��
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //��������
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //��ʼ����
    animation->start();
}
//�ָ�����
void Button1::jiang(){
    //������������
    QPropertyAnimation * animation =new QPropertyAnimation(this,"geometry");
    //���ö���ʱ����
    animation->setDuration(200);
    //��ʼλ��
    animation->setStartValue (QRect(this->x(),this->y(),this->width(),this->height()));
    //����λ��
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    //��������
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //��ʼ����
    animation->start();
}

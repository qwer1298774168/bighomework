#include "button3.h"

#include<QPropertyAnimation>
Button3::Button3(QWidget *parent) : QPushButton(parent)
{

}
Button3::Button3(QString normal, QString press)

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
void Button3::mousePressEvent(QMouseEvent *e)
{
    if(this->press1!=""){
        QPixmap pix;
        pix.load(":/mode/back2.png");
        //��ť�ľ������������
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        //���ð�ť��С
        this->setIconSize(QSize(pix.width(),pix.height()));

    }
    return QPushButton::mousePressEvent(e);
}
void Button3::mouseReleaseEvent(QMouseEvent *e){
    if(this->press1!=""){
        QPixmap pix;
        pix.load(":/mode/back1.png");
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
void Button3::tiao(){
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
void Button3::jiang(){
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

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
    //按钮的具体情况的设置
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    //设置按钮大小
    this->setIconSize(QSize(500,500));

}
void Button1::mousePressEvent(QMouseEvent *e)
{
    if(this->press1!=""){
        QPixmap pix;
        pix.load(":/mode/play2.png");
        //按钮的具体情况的设置
        this->setFixedSize(start2.width(),start2.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(start2);
        //设置按钮大小
        this->setIconSize(QSize(start2.width(),start2.height()));

    }
    return QPushButton::mousePressEvent(e);
}
void Button1::mouseReleaseEvent(QMouseEvent *e){
    if(this->press1!=""){
        QPixmap pix;
        pix.load(":/mode/play1.png");
        //按钮的具体情况的设置
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        //设置按钮大小
        this->setIconSize(QSize(pix.width(),pix.height()));

    }
    return QPushButton::mouseReleaseEvent(e);
}
//弹起特效
void Button1::tiao(){
    //创建动画对象
    QPropertyAnimation * animation =new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue (QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //开始弹跳
    animation->start();
}
//恢复设置
void Button1::jiang(){
    //创建动画对象
    QPropertyAnimation * animation =new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue (QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    //弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //开始弹跳
    animation->start();
}

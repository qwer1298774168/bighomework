#include "enemy.h"
#include<QtMath>
#include<QDebug>
#include"turnpoint.h"
#include<QVector2D>
#include<time.h>
//Enemy::Enemy(QObject *parent) : QObject(parent)
//Enemy的构造函数
Enemy::Enemy(TurnPoint *startpos):QObject(0){
    this->_pos=startpos->pos();
    this->_pos1=startpos->pos();
    this->_pos2=startpos->nextPoint();
    _active=false;
    _lv=1;
    speed=0.8;
    HP=40;
}
int Enemy::random(){

    return rand()%(3)+0;
}
//判断怪物是否到达转折点
bool Enemy::judge(QPoint point1,int a,QPoint point2,int b){

    int x=point1.x()-point2.x();
    int y=point1.y()-point2.y();
    int distance=qSqrt(x*x+y*y);
    if(distance<=a+b){

        return true;
    }
    return false;
}
//移动
void Enemy::move(){
   if(judge(_pos,1,_pos2->pos(),1)){
        if(_pos2->nextPoint()){
            _pos1=_pos2->pos();
            _pos2=_pos2->nextPoint();
        }
        else{
            setdead();
        }
   }
   QPoint targetpoint = _pos2->pos();
   QVector2D vector(targetpoint-_pos1);
   vector.normalize();
   _pos=_pos+vector.toPoint()*speed;

}
//怪物的绘制
void Enemy::draw0(QPainter*painter){


    if(_lv==1){
    painter->drawPixmap(_pos.x()-25,_pos.y()-50,50,100, QPixmap(":/mode/enemya.png"));}
    if(_lv==2){
    painter->drawPixmap(_pos.x()-75,_pos.y()-75,150,150,QPixmap(":/mode/enemyc.png"));
    }
    if(_lv==3){
    painter->drawPixmap(_pos.x()-75,_pos.y()-75,150,150,QPixmap(":/mode/enemyb.png"));
    }

}
int Enemy::level(){
    return _lv;
}
void Enemy::draw1(QPainter*painter){
    painter->drawPixmap(_pos.x()-25,_pos.y()-50,50,100,QPixmap(":/mode/play1.png"));
}
void Enemy::draw2(QPainter*painter){
    painter->drawPixmap(_pos.x()-25,_pos.y()-50,50,100,QPixmap(":/mode/play2.png"));
}
void Enemy::update(){
    _lv=_lv+1;
    HP=HP+40;
}
void Enemy::judgedeath(){
    if(HP<=0){
        _active=false;
    }
}
void Enemy::setactive(){
    _active=true;
}
void Enemy::setdead(){
    _active=false;
}
bool Enemy::returnlife(){
    return _active;
}
//返回当前坐标
QPoint Enemy::returnCurrentpoint(){
    return this->_pos;
}
//设置当前坐标
void Enemy::setPoint(QPoint pos){
    this->_pos=pos;
}

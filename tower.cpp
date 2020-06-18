#include "tower.h"
#include"enemy.h"
#include<QPoint>
#include<QPixmap>
#include<QPainter>
#include<QDebug>
#include<stdlib.h>
#include<QtMath>
#include"easylevel.h"
#include"fire.h"
Tower::Tower(QPoint pos, Easylevel *easy, QPixmap sprite1,  QPixmap sprite2) : QObject(0),_pos(pos),_sprite(sprite1),target(NULL)
{
     lv=0;
     firerate=200;
     _istower=false;
     _range=240;
     _damage=1;
     _sprite2=sprite2;
     easylevel= easy;
     rate= new QTimer(this);
     connect(rate,SIGNAL(timeout()),this,SLOT(weapon()));
}
Tower::~Tower(){
    delete rate;
    rate=NULL;
}
void Tower::draw2(QPainter *painter){
    painter->drawPixmap(_pos.x()-130,_pos.y()-130,260,260,_sprite2);
    painter->drawEllipse(_pos,_range,_range);
}
void Tower::draw(QPainter *painter){
    painter->setPen(Qt::black);
    if(lv==1){
        painter->save();
        painter->drawPixmap(_pos.x()-55,_pos.y()-55,110,110,_sprite);
        painter->restore();
    }
    else if(lv==2){
        painter->save();
        painter->drawPixmap(_pos.x()-130,_pos.y()-130,260,260,_sprite2);
        painter->restore();
    }
    painter->drawEllipse(_pos,_range,_range);
}
int Tower::Returndamage(){
    return _damage;
}

void Tower::weapon()
{
    Fire * bullet= new Fire(_pos,target->returnCurrentpoint(),target,easylevel);
    bullet->move();
    easylevel->addfire(bullet);
}

void Tower::chooseenemy(Enemy *enemy)
{
    target=enemy;
    attackenemy();
    target->beenattacked(this);
}

bool Tower::judge(QPoint point1, int a, QPoint point2, int b)
{
    int x=abs(point1.x()-point2.x());
    int y=abs(point1.y()-point2.y());
    int distance=qSqrt(x*x+y*y);
    if(distance<=a+b){
        return true;
    }
    return false;
}

void Tower::judgeenemtinrange()
{
    if(target){
        if(!judge(_pos,_range,target->returnCurrentpoint(),1)){
            outofrange();
        }
    }
    else{
    QList<Enemy*>enemylist=easylevel->enemyList();
    foreach(Enemy*enemy,enemylist){
        if(judge(_pos,_range,enemy->returnCurrentpoint(),1)){
             chooseenemy(enemy);
             break;
         }
       }
    }
}

void Tower::attackenemy()
{
    rate->start(firerate);
}

void Tower::enemykilled()
{
    if(target){
        target=NULL;
    }
    rate->stop();
}

void Tower::outofrange()
{
    target->runoutofrange(this);
    if(target){
        target=NULL;
    }
    rate->stop();
}

QPoint Tower::returnpoint()
{
    return _pos;
}
int Tower::range(){
    return _range;
}
int Tower::level(){
    return lv;
}
bool Tower::hasTower(){
    return _istower;
}
void Tower::placeTower(){
    lv=1;
    _istower=true;
}
void Tower::removeTower(){
    lv=0;
    _istower=false;
}
void Tower::upload(){
    lv=2;
    _range=300;
    _damage=40;
}

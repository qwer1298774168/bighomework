#include "tower.h"
#include<QPoint>
#include<QPixmap>
#include<QPainter>
#include<QDebug>
Tower::Tower(QPoint pos,  QPixmap sprite1,  QPixmap sprite2) : QObject(0),_pos(pos),_sprite(sprite1)
{
     lv=0;
     _istower=false;
     _range=240;
     _damage=10;
     _sprite2=sprite2;
}
void Tower::draw2(QPainter *painter){
    painter->drawPixmap(_pos.x()-130,_pos.y()-130,260,260,_sprite2);
    painter->drawEllipse(_pos,_range,_range);
}
void Tower::draw(QPainter *painter){
    painter->setPen(Qt::black);
    if(lv==1){
        qDebug()<<"draw level1 tower";
        painter->save();
        painter->drawPixmap(_pos.x()-55,_pos.y()-55,110,110,_sprite);
        painter->restore();
    }
    else if(lv==2){
        qDebug()<<"draw level2 tower";
        painter->save();
        painter->drawPixmap(_pos.x()-130,_pos.y()-130,260,260,_sprite2);
        painter->restore();
    }
    painter->drawEllipse(_pos,_range,_range);
}
int Tower::Returndamage(){
    return _damage;
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

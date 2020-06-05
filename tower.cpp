#include "tower.h"
#include<QPoint>
#include<QPixmap>
#include<QPainter>
Tower::Tower(QPoint pos,  QPixmap sprite1,  QPixmap sprite2) : QObject(0),_pos(pos),_sprite(sprite1)
{
     lv=false;
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
    painter->setPen(Qt::white);
    painter->drawPixmap(_pos.x()-55,_pos.y()-55,110,110,_sprite);
    painter->drawEllipse(_pos,_range,_range);
}
int Tower::range(){
    return _range;
}
bool Tower::level(){
    return lv;
}
bool Tower::hasTower(){
    return _istower;
}
void Tower::placeTower(){
    lv=false;
    _istower=true;
}
void Tower::removeTower(){
    lv=false;
    _istower=false;
}
void Tower::upload(){
    lv=true;
    _range=300;
    _damage=40;

}

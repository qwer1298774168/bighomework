#include "towerposition.h"
const QSize Towerposition::_fixedsize(90,90);
//构造函数对tower position进行初始化
Towerposition::Towerposition(QPoint pos,const QPixmap &sprite)
    :_pos(pos)
    ,_hastower(false)
    ,_sprite(sprite)
    ,level(0)
{}
const QPoint Towerposition::centerPos()const
{
    QPoint centerpoint(_fixedsize.width()/2,_fixedsize.height()/2);
    return _pos+centerpoint;
}
bool Towerposition::containPoint(const QPoint &pos) const
{
    bool X=_pos.x()<pos.x()&&pos.x()<(_pos.x()+_fixedsize.width());
    bool Y=_pos.y()<pos.y()&&pos.y()<(_pos.y()+_fixedsize.height());
    return X&&Y;
}
bool Towerposition::hastower()const
{
    return _hastower;
}
void Towerposition::addtower(bool hastower){
    _hastower=hastower;
    level=1;
}
int Towerposition::ReturnTowerlevel(){
    return level;
}
void Towerposition::upthistower(){
    level=2;
}
void Towerposition::removethistower(){
    level=0;
    _hastower=false;
}
void Towerposition::draw(QPainter *paniter) const
{
    paniter->drawPixmap(_pos.x(),_pos.y(),90,90,_sprite);
}
QPoint Towerposition::position(){
    return _pos;

}

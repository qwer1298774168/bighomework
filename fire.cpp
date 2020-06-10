#include "fire.h"

Fire::Fire(QPoint startpos, QPoint endpos, Enemy * target) :
    _startpos(startpos)
  , _endpos(endpos)
  , _target(target)
{
    damage=10;
}
QPoint Fire::currentPos(){
    return _currentpos;
}
void Fire::setCurrentpos(QPoint pos){
    _currentpos=pos;
}
void Fire::draw(QPainter *paniter){
    paniter->drawPixmap(_currentpos.x(),_currentpos.y(),":/mode/icon_gold.png");
}
void Fire::move(){
    QPropertyAnimation *animation = new QPropertyAnimation(this, "_currentpos");
    animation->setDuration(1000);
    animation->setStartValue(_startpos);
    animation->setEndValue(_endpos);

    animation->start();
}

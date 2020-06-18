#include "fire.h"
#include"enemy.h"
Fire::Fire(QPoint startpos, QPoint endpos, Enemy * target, Easylevel *easy) :
    _startpos(startpos)
  , _endpos(endpos)
  , _target(target)
{
    damage=2;
    this->easy=easy;
}
QPoint Fire::currentPos(){
    return _currentpos;
}
void Fire::setCurrentpos(QPoint pos){
    _currentpos=pos;
}
void Fire::draw(QPainter *paniter){
    paniter->drawPixmap(_currentpos.x(),_currentpos.y(),60,60,QPixmap(":/mode/huajitower.png"));
}
void Fire::move(){
    QPropertyAnimation *animation = new QPropertyAnimation(this, "_currentpos");
    animation->setDuration(200);
    animation->setStartValue(_startpos);
    animation->setEndValue(_endpos);
    connect(animation,SIGNAL(finished()),this,SLOT(hittarget()));
    animation->start();
}

void Fire::hittarget()
{
    if(easy->enemyList().indexOf(_target)!=-1){
        _target->hpdown(damage);
    }
    easy->removefire(this);
}

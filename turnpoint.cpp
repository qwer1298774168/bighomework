#include "turnpoint.h"
#include<QPainter>
#include<QColor>
TurnPoint::TurnPoint(QPoint pos):_pos(pos),_nextPoint(NULL)
{

}
//设置怪物的下一个转折点
void TurnPoint::next(TurnPoint *nextPoint){
    _nextPoint=nextPoint;
}
//返回下一个转折点
TurnPoint* TurnPoint::nextPoint()const{
    return _nextPoint;
}
//返回该点坐标
const QPoint TurnPoint::pos()const{
    return _pos;
}
//绘制怪物行走的路线
void TurnPoint::draw(QPainter *painter) const{
    //此处学习csdn上面的代码
    painter->save();
    painter->setPen(Qt::white);
    painter->drawEllipse(_pos,10,10);

    if(_nextPoint)
        painter->drawLine(_pos,_nextPoint->_pos);
    painter->restore();
}

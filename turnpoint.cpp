#include "turnpoint.h"
#include<QPainter>
#include<QColor>
TurnPoint::TurnPoint(QPoint pos):_pos(pos),_nextPoint(NULL)
{

}
//���ù������һ��ת�۵�
void TurnPoint::next(TurnPoint *nextPoint){
    _nextPoint=nextPoint;
}
//������һ��ת�۵�
TurnPoint* TurnPoint::nextPoint()const{
    return _nextPoint;
}
//���ظõ�����
 const QPoint TurnPoint::pos() const{
    return _pos;
}
//���ƹ������ߵ�·��
void TurnPoint::draw(QPainter *painter) const{
    //�˴�ѧϰcsdn����Ĵ���
    painter->save();
    painter->setPen(Qt::black  );
    painter->drawEllipse(_pos,10,10);

    if(_nextPoint)
        painter->drawLine(_pos,_nextPoint->_pos);
    painter->restore();
}

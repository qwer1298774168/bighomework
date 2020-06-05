#ifndef TURNPOINT_H
#define TURNPOINT_H
#include<QPoint>
#include<QPainter>
class TurnPoint
{
public:
    TurnPoint(QPoint pos);
    void next(TurnPoint *nextpoint);
    TurnPoint*nextPoint()const;
    const QPoint pos()const;
    void draw(QPainter *painter)const;
private:
    const QPoint _pos;
    TurnPoint *_nextPoint;
};

#endif // TURNPOINT_H

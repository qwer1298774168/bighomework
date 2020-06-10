#ifndef FIRE_H
#define FIRE_H

#include <QObject>
#include"enemy.h"
#include<QPoint>
#include<QPropertyAnimation>
#include<QPainter>
#include<QPixmap>
class Fire : public QObject
{
    Q_OBJECT
public:
    Fire(QPoint startpos, QPoint endpos , Enemy * target);
    void setCurrentpos(QPoint pos);
    QPoint currentPos();
    void draw(QPainter*paniter);
    void move();
private:
    QPoint _startpos;
    QPoint _endpos;
    QPoint _currentpos;
    int damage;
    Enemy * _target;
signals:

public slots:
};

#endif // FIRE_H

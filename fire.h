#ifndef FIRE_H
#define FIRE_H

#include <QObject>
#include"enemy.h"
#include<QPoint>
#include<QPropertyAnimation>
#include<QPainter>
#include<QPixmap>
#include<QDebug>
class Enemy;
class Easylevel;
class Fire : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint _currentpos READ currentPos WRITE setCurrentpos)
public:
    Fire(QPoint startpos, QPoint endpos , Enemy * target,Easylevel*easy);
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
    Easylevel * easy;
private slots:
    void hittarget();
signals:

public slots:
};

#endif // FIRE_H

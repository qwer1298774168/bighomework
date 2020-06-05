#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include<QPoint>
#include<QPropertyAnimation>
#include<QPixmap>
#include<QPainter>
#include"tower.h"
class Enemy : public QObject
{
    Q_OBJECT
public:
    Enemy(QPoint pos,int lv);
    void move();
private:
    QPoint _pos;
    int _lv;

signals:

public slots:
};

#endif // ENEMY_H

#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include<QPoint>
#include<QPropertyAnimation>
#include<QPixmap>
#include<QPainter>
#include"tower.h"
#include<QList>
#include<random>
class TurnPoint;
class Tower;
class Easylevel;
class Enemy : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QPoint _pos READ returnCurrentpoint WRITE setPoint)
public:
    Enemy(TurnPoint *startpos,Easylevel * easy);
     ~Enemy();
    void move();
    void draw0(QPainter*painter);
    void draw1(QPainter*painter);
    void draw2(QPainter*painter);
    void update();//怪物等级提升
    int level();//返回怪物等级
    void setdead();//设置怪物去世
    bool returnlife();//返回怪物的存活情况
    QPoint returnCurrentpoint();
    void setPoint(QPoint pos);//设定当前位置
    bool judge(QPoint point1,int a,QPoint point2,int b);//判断是否到达转折点
    int random();
    void judgedeath();//判断怪物是否去世
    void beenattacked(Tower * tower);
    void runoutofrange(Tower * tower);
    void removeenemy();
    void hpdown(int damage);
    int ReturnHP();
private:
    double speed;//怪物移动的速度
    Easylevel * easy;
    QPoint _pos;//怪物当前的位置
    QPoint _pos1;//怪物每次设置的起始位置
    TurnPoint* _pos2;//怪物每次设置的目标位置
    int _lv;//怪物的等级
    bool _active;
    qreal HP;
    QList<Tower*>attackenemy_list;
signals:

public slots:
    void setactive();//设置怪物活
};

#endif // ENEMY_H

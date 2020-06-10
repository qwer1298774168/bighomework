#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include<QPoint>
#include<QPixmap>
#include<QPainter>
class Easylevel;

class Tower : public QObject
{
    Q_OBJECT
public:
    Tower(QPoint pos,  QPixmap sprite1=QPixmap(":/mode/towera1.png"), QPixmap sprite2=QPixmap(":/mode/towera2.png"));
    void draw(QPainter *painter);
    void draw2(QPainter *painter) ;
    int range();//·µ»Ø·ÀÓùËş·¶Î§
    int level();//·µ»Ø·ÀÓùËşµÈ¼¶
    bool hasTower();
    void placeTower();
    void removeTower();
    void upload();
    int Returndamage();//·µ»Ø·ÀÓùËşµÄÉËº¦
private:
    QPoint _pos;
    QPixmap _sprite;
    QPixmap _sprite2;
    int lv;
    bool _istower;
    int _range;
    int _damage;
signals:

public slots:
};

#endif // TOWER_H

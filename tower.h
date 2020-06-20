#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include<QPoint>
#include<QTimer>
#include<QPixmap>
#include<QPainter>
#include"fire.h"
#include"easylevel.h"
class Easylevel;
class Enemy;
class Tower : public QObject
{
    Q_OBJECT
public:
    Tower(QPoint pos, Easylevel *easy, QPixmap sprite1=QPixmap(":/mode/huajitower.png"), QPixmap sprite2=QPixmap(":/mode/towera2.png"));
    ~Tower();
    void draw(QPainter *painter);
    void draw2(QPainter *painter) ;
    int range();//·µ»Ø·ÀÓùËş·¶Î§
    int level();//·µ»Ø·ÀÓùËşµÈ¼¶
    bool hasTower();
    void placeTower();
    void removeTower();
    void upload();
    int Returndamage();//·µ»Ø·ÀÓùËşµÄÉËº¦
    void chooseenemy(Enemy*enemy);
    bool judge(QPoint point1,int a,QPoint point2,int b);//ÅĞ¶ÏÊÇ·ñÓĞµĞÈË
    void judgeenemtinrange();
    void attackenemy();
    void enemykilled();
    void outofrange();
    void settype(int m);
    QPoint returnpoint();
    int returntype();
private:
    Enemy * target;
    int type;
    QTimer* rate;
    Easylevel * easylevel;
    QPoint _pos;
    QPixmap _sprite;
    QPixmap _sprite2;
    int lv;
    bool _istower;
    int _range;
    int _damage;
    int firerate;
private slots:
    void weapon();
signals:

public slots:
};

#endif // TOWER_H

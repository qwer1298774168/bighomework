  #ifndef EASYLEVEL_H
#define EASYLEVEL_H

#include <QMainWindow>
#include"towerposition.h"
#include"tower.h"
#include"turnpoint.h"
#include"enemy.h"
#include<QList>
#include<QTime>
class Enemy;
class Easylevel : public QMainWindow
{
    Q_OBJECT
public:
    explicit Easylevel(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void addEnemy();
    void gengxin();
    QList<Enemy *> enemyList();
private:
    int counter;
    QList<Towerposition> towerposition_list;
    QList<Tower*>tower_list;
    QList<TurnPoint*>turnpoint_list;
    QList<Enemy*>enemy_list;
    void wayPoint();//添加怪物行走的节点
    void loadTowerposition();//添加放置防御塔的塔台
signals:

public slots:
};

#endif // EASYLEVEL_H

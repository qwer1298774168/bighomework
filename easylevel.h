  #ifndef EASYLEVEL_H
#define EASYLEVEL_H

#include <QMainWindow>
#include"towerposition.h"
#include"tower.h"
#include"turnpoint.h"
#include"enemy.h"
#include"fire.h"
#include<QList>
#include<QTime>
class Enemy;
class Tower;
class Towerposition;
class Fire;
class Easylevel : public QMainWindow
{
    Q_OBJECT
public:
    explicit Easylevel(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

    bool loadWave();
    QList<Enemy *> enemyList()const;
    void addfire(Fire * fire);
    void removefire(Fire * fire);
    void removeoneenemy(Enemy * enemy2);
    QList<Enemy*>          enemy_list;
    bool canbuytower();
    void drawgold(QPainter * painter);
private slots:
    void addEnemy();
    void gengxin();
private:
    int gold;
    int i;
    int reward;
    int cost;
    int counter;
    int counter2;
    QList<Towerposition>   towerposition_list;
    QList<Tower*>          tower_list;
    QList<TurnPoint*>      turnpoint_list;

    QList<Fire*>           fire_list;
    void wayPoint();//添加怪物行走的节点
    void loadTowerposition();//添加放置防御塔的塔台
signals:

public slots:
};

#endif // EASYLEVEL_H

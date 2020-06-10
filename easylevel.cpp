#include "easylevel.h"
#include<QPainter>
#include<QMouseEvent>
#include<QDebug>
#include<QTimer>
#include<time.h>
#include<windows.h>
#include"turnpoint.h"
#include"button1.h"
#include"enemy.h"
#include<cstdlib>
Easylevel::Easylevel(QWidget *parent) : QMainWindow(parent)
{
    counter=0;
    this->setFixedSize(1200,800);
    loadTowerposition();
    wayPoint();
    Button1 * add1 = new Button1(":/mode/play1.png");
    add1->setParent(this);
    add1->move(0,0);
    connect(add1 ,&Button1::clicked,this,[=](){
        //每过多少时间间隔更新一次界面
        add1->move(1600,1600);
           QTimer::singleShot(10,this,[=]{
            QTimer * timer = new QTimer(this);
            connect(timer,&QTimer::timeout,this,&Easylevel::gengxin);
            timer->start(8);
            QTimer * timer2 = new QTimer(this);
            connect(timer2,&QTimer::timeout,this,&Easylevel::addEnemy);
            timer2->start(2000);

        });
    });
}

//添加怪兽
void Easylevel::addEnemy(){
    counter++;
    TurnPoint *startpos = turnpoint_list.back();
    if(counter<=6){
    Enemy *enemy1 = new Enemy(startpos);
    enemy1->setactive();
    enemy_list.push_back(enemy1);
    }
    if(counter>6&&counter<=12){
    qDebug()<<"update";
    Enemy *enemy2 = new Enemy(startpos);
    enemy2->update();
    enemy2->setactive();
    enemy_list.push_back(enemy2);
    qDebug()<<enemy2->level();
    }
    if(counter>12&&counter<=18){
        Enemy *enemy3 = new Enemy(startpos);
        enemy3->update();
        enemy3->update();
        enemy3->setactive();
        qDebug()<<enemy3->returnlife();
        enemy_list.push_back(enemy3);
        qDebug()<<enemy3->level();
    }

}
//返回怪兽的list
QList<Enemy *> Easylevel::enemyList(){
    return enemy_list;
}
//定时更行界面
void Easylevel::gengxin(){
    foreach(Enemy*enemy1,enemy_list){
        enemy1->move();
    }
    update();
}
//将怪物行走的位置储存在qlist中
void Easylevel::wayPoint(){

    qDebug()<<"store";
    TurnPoint *turnpoint1=new TurnPoint(QPoint(1100,290));
    turnpoint_list.push_back(turnpoint1);

    TurnPoint*turnpoint2 = new TurnPoint(QPoint(960,290));
    turnpoint_list.push_back(turnpoint2);
    turnpoint2->next(turnpoint1);

    TurnPoint*turnpoint3 = new TurnPoint(QPoint(960,450));
    turnpoint_list.push_back(turnpoint3);
    turnpoint3->next(turnpoint2);

    TurnPoint*turnpoint4 = new TurnPoint(QPoint(630,450));
    turnpoint_list.push_back(turnpoint4);
    turnpoint4->next(turnpoint3);

    TurnPoint *turnpoint5 = new TurnPoint(QPoint(630,260));
    turnpoint_list.push_back(turnpoint5);
    turnpoint5->next(turnpoint4);

    TurnPoint*turnpoint6= new TurnPoint(QPoint(220,260));
    turnpoint_list.push_back(turnpoint6);
    turnpoint6->next(turnpoint5);

    TurnPoint*turnpoint7= new TurnPoint(QPoint(220,470));
    turnpoint_list.push_back(turnpoint7);
    turnpoint7->next(turnpoint6);

    TurnPoint*turnpoint8= new TurnPoint(QPoint(20,470));
    turnpoint_list.push_back(turnpoint8);
    turnpoint8->next(turnpoint7);
}
//储存塔台的位置并将其置入qlist中
void Easylevel::loadTowerposition(){
    qDebug()<<"store1";
    QPoint pos[15]={
      QPoint(280,310),
      QPoint(80,310),
      QPoint(295,420),
      QPoint(495,420),
      QPoint(820,270),
      QPoint(600,510),
      QPoint(715,510),
      QPoint(830,510),
      QPoint(945,510),
      QPoint(80,200),
      QPoint(685,170),
      QPoint(685,270),
      QPoint(190,540),
      QPoint(395,310),
      QPoint(510,310)
    };
    int len=sizeof(pos)/sizeof(pos[0]);
    for(int i=0;i<len;i++){
      towerposition_list.push_back(pos[i]);
    }
}
//绘制事件
void Easylevel::paintEvent(QPaintEvent *){

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/mode/map4.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //绘制塔台

    foreach (const Towerposition&towerposition, towerposition_list)
        towerposition.draw(&painter);
    //绘制防御塔
    foreach(Tower *tower,tower_list){
        if(tower->hasTower()){
        tower->draw(&painter);}
    }
    //绘制路径
    foreach(const TurnPoint *turnpoint,turnpoint_list){
        turnpoint->draw(&painter);
    }
    foreach(Enemy *enemy1,enemy_list){
        if(enemy1->returnlife()){

        enemy1->draw0(&painter);
        }
    }
    //绘制阿等
    QPixmap pix2;
    pix2.load(":/mode/dengjie.png");
    painter.drawPixmap(1100-60,290-130,260,260,pix2);
}

//设置鼠标事件
void Easylevel::mousePressEvent(QMouseEvent *event){
    int x = event->x();
    int y = event->y();
    qDebug()<<x<<" "<<y;
    if(event->button()==Qt::LeftButton)//鼠标左击
  {
    QPoint pressPos = event->pos();
    //list的循环结构
    auto it=towerposition_list.begin();
    while(it!=towerposition_list.end()) {
        if(it->containPoint(pressPos)){
            Tower *tower=new Tower(it->centerPos());
           if(!it->hastower()&&it->ReturnTowerlevel()==0){
                it->addtower();
                tower->placeTower();
                update();
                qDebug()<<it->ReturnTowerlevel()<<"fuck";
            }
           else if(it->hastower()){
               qDebug()<<"remove ready";
               tower->removeTower();
               qDebug()<<tower->hasTower();
               it->removethistower();
               update();
            }
             tower_list.push_back(tower);
           // else if(it->hastower()){
             //   tower->removeTower();
             //   update();
           // }
         }

        ++it;
    }

   }


}

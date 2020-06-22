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
#include"fire.h"
#include<QtMath>
#include<QMediaPlayer>
Easylevel::Easylevel(QWidget *parent) : QMainWindow(parent)
{
    counter=0;
    counter2=0;
    gold=50;
    reward=14;
    cost=25;
    cost2=30;
    i=0;
    deng=20;
    win=false;
    lost=false;
    player1 = new QMediaPlayer;
    player1->setMedia(QUrl("qrc:/sound/guanqiabgm.mp3"));
    player1->setVolume(30);
    this->setFixedSize(1200,800);
    loadTowerposition();
    wayPoint();
    Button1 * easy = new Button1(":/mode/easy.png");
    easy->setParent(this);
    easy->setFixedSize(50,50);
    easy->move(0,0);
    connect(easy, &Button1::clicked,this,[=](){
        easy->tiao();
        easy->jiang();
        player1->play();
        QTimer::singleShot(500,this,[=](){
            delete easy;
            QTimer * timer = new QTimer(this);
            connect(timer,SIGNAL(timeout()),this,SLOT(gengxin()));
            timer->start(8);
            QTimer * timer2= new QTimer(this);
            connect(timer2,&QTimer::timeout,this,&Easylevel::addEnemy);
            timer2->start(2000);
        });

       //QTimer::singleShot(100,this,SLOT(addEnemy()));
    });
}
void Easylevel::removeoneenemy(Enemy *enemy2){
    Q_ASSERT(enemy2);
    QMediaPlayer * player= new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/enemydead.mp3"));
    player->setVolume(100);
    player->play();
    if(!enemy_list.empty()){
        gold=gold+reward;
        enemy_list.removeOne(enemy2);
        delete enemy2;
    }
    else{
        ++counter;
    }

}
void Easylevel::removefire(Fire *fire){
    Q_ASSERT(fire);
    fire_list.removeOne(fire);
    delete fire;
}
//��ӹ���
void Easylevel::addEnemy(){

    loadWave();
}
bool Easylevel::canbuytower(){
    if(gold>=cost){
        return true;
    }
    else{
        return false;
    }
}

bool Easylevel::canbuytower2()
{
    if(gold>=cost2){
        return true;
    }
    else{
        return false;
    }
}
void Easylevel::setlost(){
    if(deng<=0){
       lost=true;
    }

}
void Easylevel::setwin(){
    win=true;
}
void Easylevel::drawgold(QPainter * painter)
{
    painter->setPen(QPen(Qt::green));
    painter->drawText(QRect(200, 5,200, 100), QString("GOLD : %1").arg(gold));
}

void Easylevel::drawhp(QPainter *painter)
{
    painter->setPen(QPen(Qt::green));
    painter->drawText(QRect(1000,400,10,10),QString("HP : %1").arg(deng));
}

void Easylevel::getDamagedeng()
{
    deng=deng-1;
    qDebug()<<deng;
}
bool Easylevel::loadWave()
{
    counter2++;
    QMediaPlayer * player= new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/addenemy1.mp3"));
    player->setVolume(50);

   if(counter>=22){
       return false;}
   else{
       TurnPoint * startpos = turnpoint_list.back();
       Enemy * enemy = new Enemy(startpos,this);
       if(counter2<=6){
           reward=14;
       enemy->setactive();
      // player->play();
       enemy_list.push_back(enemy);
       }
       if(counter2>6&&counter2<=15){
           reward=18;
           enemy->setactive();
           enemy->update();
           //player->play();
           enemy_list.push_back(enemy);
       }
       if(counter2>15&&counter2<=22){
           reward=22;
          enemy->setactive();
           enemy->update();
           enemy->update();
           //player->play();
           enemy_list.push_back(enemy);
       }
       if(counter2>22&&enemy_list.empty()&&counter2<30){
           player1->pause();
           setwin();

       }
       if(deng<=0){
           player1->pause();
           enemy_list.removeAll(enemy);
           counter2=30;
           setlost();

       }
   }
   return true;
}
//���ع��޵�list
QList<Enemy *> Easylevel::enemyList() const{
     return enemy_list;
}

void Easylevel::addfire(Fire *fire)
{
    Q_ASSERT(fire);
    fire_list.push_back(fire);
}
//��ʱ���н���
void Easylevel::gengxin(){
    foreach(Enemy*enemy1,enemy_list){
        enemy1->move();
    }
    foreach(Tower*tower,tower_list){
        tower->judgeenemtinrange();
    }
    update();
}
//���������ߵ�λ�ô�����qlist��
void Easylevel::wayPoint(){
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
//������̨��λ�ò���������qlist��
void Easylevel::loadTowerposition(){
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
//�����¼�
void Easylevel::paintEvent(QPaintEvent *){

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/mode/map4.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


    //������̨

    foreach (const Towerposition&towerposition, towerposition_list)
        towerposition.draw(&painter);
    //���Ʒ�����
    foreach(Tower *tower,tower_list){
        if(tower->hasTower()){
        tower->draw(&painter);}
    }
    //����·��
    foreach(const TurnPoint *turnpoint,turnpoint_list){
        turnpoint->draw(&painter);
    }
    foreach(Fire * fire,fire_list){
        fire->draw(&painter);
    }
    foreach(Enemy *enemy1,enemy_list){
        if(enemy1->returnlife()){
           enemy1->draw0(&painter);
        }
    }

    //���ư���
    QPixmap pix2;
    pix2.load(":/mode/dengjie.png");
    painter.drawPixmap(1100-60,290-130,260,260,pix2);
    drawgold(&painter);
    drawhp(&painter);
    if(win){
        painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/mode/start.jpg"));
    }
    if(lost){
        painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/mode/map1.png"));
    }
}

//��������¼�
void Easylevel::mousePressEvent(QMouseEvent *event){
    QPoint pressPos = event->pos();
    //list��ѭ���ṹ
    auto it=towerposition_list.begin();
    while(it!=towerposition_list.end()) {
        if(it->containPoint(pressPos)&&!it->hastower()&&canbuytower()&&event->button()==Qt::LeftButton)
        {
            Tower * tower= new Tower(it->centerPos(),this);
            tower->placeTower();
            it->addtower();
            tower->settype(1);
            gold=gold-cost;
            tower_list.push_back(tower);
            QMediaPlayer * player= new QMediaPlayer;
            player->setMedia(QUrl("qrc:/sound/placetower.mp3"));
            player->setVolume(100);
            player->play();
            ++i;
            update();
            break;
         }
        if(it->containPoint(pressPos)&&it->hastower()&&event->button()==Qt::LeftButton)
        {
            qDebug()<<i;
            for(int j=0;j<i;j++){
                int x=abs(pressPos.x()-tower_list[j]->returnpoint().x());
                int y=abs(pressPos.y()-tower_list[j]->returnpoint().y());
                int length=qSqrt(x*x+y*y);
                qDebug()<<length;
                if(length<100&&tower_list[j]->returntype()==1){
                    tower_list[j]->enemykilled();
                    it->removethistower();
                    tower_list.removeAt(j);
                    QMediaPlayer * player= new QMediaPlayer;
                    player->setMedia(QUrl("qrc:/sound/delettower.mp3"));
                    player->setVolume(100);
                    player->play();
                    gold=gold+10;
                    --i;
                }
            }
            update();
            break;
        }
        if(it->containPoint(pressPos)&&!it->hastower()&&canbuytower2()&&event->button()==Qt::RightButton)
        {
            Tower * tower= new Tower(it->centerPos(),this);
            tower->placeTower();
            tower->settype(2);
            it->addtower();
            gold=gold-cost2;
            QMediaPlayer * player= new QMediaPlayer;
            player->setMedia(QUrl("qrc:/sound/placetower.mp3"));
            player->setVolume(100);
            player->play();
            tower_list.push_back(tower);
            ++i;
            update();
            break;
         }
        if(it->containPoint(pressPos)&&it->hastower()&&event->button()==Qt::RightButton&&gold>=60)
        {
            qDebug()<<i;
            for(int j=0;j<i;j++){
                int x=abs(pressPos.x()-tower_list[j]->returnpoint().x());
                int y=abs(pressPos.y()-tower_list[j]->returnpoint().y());
                int length=qSqrt(x*x+y*y);
                qDebug()<<length;
                if(length<100&&tower_list[j]->returntype()==2){
                    tower_list[j]->upload();
                    gold=gold-60;
                    QMediaPlayer * player= new QMediaPlayer;
                    player->setMedia(QUrl("qrc:/sound/lvup.mp3"));
                    player->setVolume(100);
                    player->play();
                    update();
                    break;
                }
            }
            update();
            break;
        }
        ++it;
    }
}

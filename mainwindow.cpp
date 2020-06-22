#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<Qpainter>
#include "button1.h"
#include"button2.h"
#include<QDebug>
#include<QTimer>
#include<QMediaPlayer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1200,800);
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/startbgm.mp3"));
    player->setVolume(30);
    player->play();
    //��ʼ��ť������
    Button1 * start = new Button1(":/mode/play1.png",":/mode/play2.png");
    start ->setParent(this);
    //��ʼ��ť��λ��
    start ->move(200,500);
    QMediaPlayer *player2 = new QMediaPlayer;
    player2->setMedia(QUrl("qrc:/sound/enemydead.mp3"));
    easy=new Easylevel;
    //��ʱ���뵽��һ������
    connect(start,&Button1::clicked,[=](){

        player2->setVolume(100);
        player2->play();

          //������һ������
          QTimer::singleShot(500,this,[=](){
              this->hide();
              player->stop();
              easy ->show();
          });
    });
    //���ý���������İ�ť
    Button2 * rule1 = new Button2(":/mode/rule1.png",":/mode/rule2.png");
    rule1->setParent(this);
    rule1->move(200,620);
    rule=new Rule;
    //����������
    connect(rule,&Rule::ruleback,this,[=](){
        rule->hide();
        this->show();
    });
    connect(easy,&Easylevel::ruleback,this,[=](){
        easy->hide();
        easy->musicpause();
        player->play();
        this->show();
    });
    connect(rule1,&Button2::clicked,[=](){
        player2->play();
        QTimer::singleShot(500,this,[=](){
            this->hide();
            rule->show();

        });
    });

}
//����ͼƬ������
void MainWindow::paintEvent(QPaintEvent *){
   QPainter painter(this);
   QPixmap back;
   //����ͼƬ
   back.load(":/mode/background.png");
   //����ͼƬ
   painter.drawPixmap(0,0,this->width(),this->height(),back);
}



MainWindow::~MainWindow()
{
    delete ui;
}

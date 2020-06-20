#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<Qpainter>
#include "button1.h"
#include"button2.h"
#include<QDebug>
#include<QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1200,800);
    //��ʼ��ť������
    Button1 * start = new Button1(":/mode/play1.png",":/mode/play2.png");
    start ->setParent(this);
    //��ʼ��ť��λ��
    start ->move(200,500);

    easy=new Easylevel;
    //��ʱ���뵽��һ������
    connect(start,&Button1::clicked,[=](){

          //������һ������
          QTimer::singleShot(500,this,[=](){
              this->hide();
              easy ->show();
          });
    });
    //���ý���������İ�ť
    Button2 * rule1 = new Button2(":/mode/rule1.png",":/mode/rule2.png");
    rule1->setParent(this);
    rule1->move(200,620);
    rule=new Rule;
    //����������
    connect(rule1,&Button2::clicked,[=](){
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

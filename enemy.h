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
class Enemy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint _pos READ returnCurrentpoint WRITE setPoint)
public:
    Enemy(TurnPoint *startpos);
    void move();
    void draw0(QPainter*painter);
    void draw1(QPainter*painter);
    void draw2(QPainter*painter);
    void update();//����ȼ�����
    int level();//���ع���ȼ�
    void setactive();//���ù����
    void setdead();//���ù���ȥ��
    bool returnlife();//���ع���Ĵ�����
    QPoint returnCurrentpoint();
    void setPoint(QPoint pos);//�趨��ǰλ��
    bool judge(QPoint point1,int a,QPoint point2,int b);//�ж��Ƿ񵽴�ת�۵�
    int random();
    void judgedeath();//�жϹ����Ƿ�ȥ��
private:
    double speed;//�����ƶ����ٶ�
    QPoint _pos;//���ﵱǰ��λ��
    QPoint _pos1;//����ÿ�����õ���ʼλ��
    TurnPoint* _pos2;//����ÿ�����õ�Ŀ��λ��
    int _lv;//����ĵȼ�
    bool _active;
    QList<Enemy*>enemy_list;
    int HP;
signals:

public slots:
};

#endif // ENEMY_H

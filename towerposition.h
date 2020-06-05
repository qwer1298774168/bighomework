#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H
#include<QPoint>
#include<QSize>
#include<QPixmap>
#include<QPainter>
class Towerposition
{
public:
    //�˴��Ĵ���ѧϰ��csdn�ϵĴ���
    Towerposition(QPoint pos, const QPixmap &sprite = QPixmap(":/mode/addtower.png"));
    void addtower(bool hastower=true);//��ӷ�����
    bool hastower()const;//�ж��Ƿ���ڷ�����
    const QPoint centerPos()const;//������λ�����ĵ�ֵ
    bool containPoint(const QPoint &pos) const;//�ж������λ���Ƿ��ܹ����÷�����
    void draw(QPainter * paniter)const;
    QPoint position();
private:
    QPoint _pos;
    bool _hastower;
    QPixmap _sprite;
    static const QSize _fixedsize;//������Ե�������귶Χ��С
};

#endif // TOWERPOSITION_H

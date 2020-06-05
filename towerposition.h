#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H
#include<QPoint>
#include<QSize>
#include<QPixmap>
#include<QPainter>
class Towerposition
{
public:
    //此处的代码学习了csdn上的代码
    Towerposition(QPoint pos, const QPixmap &sprite = QPixmap(":/mode/addtower.png"));
    void addtower(bool hastower=true);//添加防御塔
    bool hastower()const;//判断是否存在防御塔
    const QPoint centerPos()const;//返回塔位的中心点值
    bool containPoint(const QPoint &pos) const;//判断鼠标点的位置是否能够放置防御塔
    void draw(QPainter * paniter)const;
    QPoint position();
private:
    QPoint _pos;
    bool _hastower;
    QPixmap _sprite;
    static const QSize _fixedsize;//定义可以点击的坐标范围大小
};

#endif // TOWERPOSITION_H

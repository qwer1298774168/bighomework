#ifndef BUTTON3_H
#define BUTTON3_H

#include <QPushButton>

class Button3 : public QPushButton
{
    Q_OBJECT
public:
    explicit Button3(QWidget *parent = nullptr);
    Button3(QString normal,QString press="");
    QString normal1;
    QString press1;
//按钮按下和释放
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
//按钮的弹跳动画
    void tiao();
    void jiang();
private:
signals:

public slots:
};

#endif // BUTTON3_H

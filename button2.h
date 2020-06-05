#ifndef BUTTON2_H
#define BUTTON2_H

#include <QMainWindow>
#include<QPushButton>
class Button2 : public QPushButton
{
    Q_OBJECT
public:
    explicit Button2(QWidget *parent = nullptr);
    Button2(QString normal,QString press="");
    QString normal1;
    QString press1;
//按钮按下和释放
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:

public slots:
};

#endif // BUTTON2_H

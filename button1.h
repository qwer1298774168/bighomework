#ifndef BUTTON1_H
#define BUTTON1_H

#include <QPushButton>
//��ť�������
class Button1 : public QPushButton
{
    Q_OBJECT
public:
    explicit Button1(QWidget *parent = nullptr);
    Button1(QString normal,QString press="");
    QString normal1;
    QString press1;
//��ť���º��ͷ�
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
//��ť�ĵ�������
    void tiao();
    void jiang();
private:
    QPixmap start1=QPixmap(":/mode/play1.png");
    QPixmap start2=QPixmap(":/mode/play2.png");
signals:

public slots:
};

#endif // BUTTON1_H

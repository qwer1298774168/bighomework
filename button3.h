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
//��ť���º��ͷ�
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
//��ť�ĵ�������
    void tiao();
    void jiang();
private:
signals:

public slots:
};

#endif // BUTTON3_H

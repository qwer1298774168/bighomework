#ifndef CHOOSE_H
#define CHOOSE_H

#include <QMainWindow>
#include"easylevel.h"
#include"hardlevel.h"
class Choose : public QMainWindow
{
    Q_OBJECT
public:
    explicit Choose(QWidget *parent = nullptr);
    //����ѡ��ؿ������Ժ�Ҫ���»��Ʊ���ͼƬ
    void paintEvent(QPaintEvent *event);
    Easylevel* easylevel;
    Hardlevel* hardlevel;
signals:

public slots:
};

#endif // CHOOSE_H

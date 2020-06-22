#ifndef RULE_H
#define RULE_H

#include <QMainWindow>
#include<QPainter>
#include<QPixmap>
#include"mainwindow.h"
class Rule : public QMainWindow
{
    Q_OBJECT
public:
    explicit Rule(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:
    void ruleback();
public slots:
};

#endif // RULE_H

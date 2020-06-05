#ifndef HARDLEVEL_H
#define HARDLEVEL_H

#include <QMainWindow>
#include<QMouseEvent>
class Hardlevel : public QMainWindow
{
    Q_OBJECT
public:
    explicit Hardlevel(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // HARDLEVEL_H

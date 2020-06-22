#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"choose.h"
#include"rule.h"
class Rule;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    Choose * choose =NULL;
    Rule *rule=NULL;
    Easylevel * easy=NULL;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H



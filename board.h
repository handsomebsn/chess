#ifndef BOARD_H
#define BOARD_H
#include <QWidget>
#include<QPainter>
#include<QVector>
#include<QMouseEvent>
#include"stone.h"
#include"step.h"
class Board : public QWidget
{
    Q_OBJECT
private:
    Stone stones[32];
    int postoids[10][9];//由棋盘位置返回此处的棋子id（stones数组下标）值，便于快速找到
    //
    QPainter painter;
public:
    explicit Board(QWidget *parent = 0);
    QVector<Step> chesteps(int moveId);
    void chesteps(int moveId,QVector<Step> &steps);
    QVector<Step> masteps(int moveId);
    QVector<Step> xiangsteps(int moveId);
    QVector<Step> shiteps(int moveId);
    QVector<Step> jiangsteps(int moveId);
    QVector<Step> paosteps(int moveId);
    QVector<Step> bingteps(int moveId);
    ///////////////////////////////////
     void move(int moveId,int rowto,int colto);
     //
     bool canmove(int moveId,int rowto,int colto);
signals:

public slots:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // BOARD_H

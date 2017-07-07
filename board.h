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
   inline int getstoneId(int row,int col){
           if(row<0||row>9||col<0||col>8)
               qDebug("......%d %d......",row,col);
        return postoids[row][col];
        }

    Stone stones[32];
    int postoids[10][9];//由棋盘位置返回此处的棋子id（stones数组下标）值，便于快速找到
    //
    QPainter painter;
public:
    explicit Board(QWidget *parent = 0);
    QVector<Step> chesteps(int moveId);
    inline void chesteps(int moveId,QVector<Step> &steps);
    QVector<Step> masteps(int moveId);
    inline void masteps(int moveId,QVector<Step> &steps);
    QVector<Step> xiangsteps(int moveId);
    inline void xiangsteps(int moveId,QVector<Step> &steps);
    QVector<Step> shisteps(int moveId);
    inline void shisteps(int moveId,QVector<Step> &steps);
    QVector<Step> jiangsteps(int moveId);
    inline void jiangsteps(int moveId,QVector<Step> &steps);
    QVector<Step> paosteps(int moveId);
    inline void paosteps(int moveId,QVector<Step> &steps);
    QVector<Step> bingsteps(int moveId);
    inline void bingsteps(int moveId,QVector<Step> &steps);
    ///////////////////////////////////
     void move(int moveId,int rowto,int colto);

     bool canmove(int moveId,int rowto,int colto);
     //////////
     void getAllsetps(QVector<Step> &steps,bool player=false);
     void move(const Step &step);
     void unmove(const Step &step);

signals:

public slots:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // BOARD_H

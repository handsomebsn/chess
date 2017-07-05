#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include"stone.h"
#include<QPainter>
class Board : public QWidget
{
    Q_OBJECT
private:
    Stone stones[32];
    //
    QPainter painter;
public:
    explicit Board(QWidget *parent = 0);


signals:

public slots:
    void paintEvent(QPaintEvent *event);
};

#endif // BOARD_H

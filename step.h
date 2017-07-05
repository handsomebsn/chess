#ifndef STEP_H
#define STEP_H


class Step
{
public:
    Step();
    //移动棋子的标记
    int moveId;
    //杀死棋子的标记
    int killId;
    //起点
    int rowFrom;
    int colFrom;
    //终点
    int rowTo;
    int colTo;
};

#endif // STEP_H

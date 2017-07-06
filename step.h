#ifndef STEP_H
#define STEP_H


class Step
{
public:
    Step();
    Step(int _moveId,int _killId,int _rowFrom,int _colFrom,int _rowTo,int _colTo);
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
    bool operator==(const Step &step)const;
};

#endif // STEP_H

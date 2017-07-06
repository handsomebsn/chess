#include "step.h"

Step::Step()
{

}
Step::Step(int _moveId, int _killId, int _rowFrom, int _colFrom, int _rowTo, int _colTo){
    moveId=_moveId;
    killId=_killId;
    rowFrom=_rowFrom;
    colFrom=_colFrom;
    rowTo=_rowTo;
    colTo=_colTo;

}

bool Step::operator ==(const Step &step)const{



return moveId==step.moveId&&killId==step.killId&&rowFrom==step.rowFrom&&colFrom==step.colFrom&&rowTo==step.rowTo&&colTo==step.colTo;
}

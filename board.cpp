#include "board.h"

Board::Board(QWidget *parent) : QWidget(parent),painter(this)
{
    bool redbool=false;
    stones[0].init(CHE,0,0,redbool);
    stones[1].init(MA,0,1,redbool);
    stones[2].init(XIANG,0,2,redbool);
    stones[3].init(SHI,0,3,redbool);
    stones[4].init(JIANG,0,4,redbool);
    stones[5].init(SHI,0,5,redbool);
    stones[6].init(XIANG,0,6,redbool);
    stones[7].init(MA,0,7,redbool);
    stones[8].init(CHE,0,8,redbool);
    stones[9].init(PAO,2,1,redbool);
    stones[10].init(PAO,2,7,redbool);
    stones[11].init(BING,3,0,redbool);
    stones[12].init(BING,3,2,redbool);
    stones[13].init(BING,3,4,redbool);
    stones[14].init(BING,3,6,redbool);
    stones[15].init(BING,3,8,redbool);
    /////
    if(redbool)redbool=false;
    else
    redbool=true;
    stones[16].init(CHE,9,0,redbool);
    stones[17].init(MA,9,1,redbool);
    stones[18].init(XIANG,9,2,redbool);
    stones[19].init(SHI,9,3,redbool);
    stones[20].init(JIANG,9,4,redbool);
    stones[21].init(SHI,9,5,redbool);
    stones[22].init(XIANG,9,6,redbool);
    stones[23].init(MA,9,7,redbool);
    stones[24].init(CHE,9,8,redbool);
    stones[25].init(PAO,7,1,redbool);
    stones[26].init(PAO,7,7,redbool);
    stones[27].init(BING,6,0,redbool);
    stones[28].init(BING,6,2,redbool);
    stones[29].init(BING,6,4,redbool);
    stones[30].init(BING,6,6,redbool);
    stones[31].init(BING,6,8,redbool);
    setMinimumSize(520,576);
    setMaximumSize(520,576);
}
/*绘图里面根据属性值来绘图，而不改变属性值本身，即视图层不参与逻辑运算，让代码条理更清晰*/
void Board::paintEvent(QPaintEvent *event){

    painter.begin(this);
    painter.drawImage(0,0,QImage(":/images/BOARD.BMP"));
    for(int i=0;i<32;i++)
        stones[i].display(painter);
    painter.end();
}

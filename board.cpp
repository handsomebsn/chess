#include "board.h"
#define getstoneId(_row,_col) postoids[_row][_col]
#define samecolor(c1,c2) c1==c2
#define decolor(c1,c2) c1!=c2
Board::Board(QWidget *parent) : QWidget(parent),painter(this)
{
    bool computercolor=false;
    stones[0].init(CHE,0,0,computercolor);
    stones[1].init(MA,0,1,computercolor);
    stones[2].init(XIANG,0,2,computercolor);
    stones[3].init(SHI,0,3,computercolor);
    stones[4].init(JIANG,0,4,computercolor);
    stones[5].init(SHI,0,5,computercolor);
    stones[6].init(XIANG,0,6,computercolor);
    stones[7].init(MA,0,7,computercolor);
    stones[8].init(CHE,0,8,computercolor);
    stones[9].init(PAO,2,1,computercolor);
    stones[10].init(PAO,2,7,computercolor);
    stones[11].init(BING,3,0,computercolor);
    stones[12].init(BING,3,2,computercolor);
    stones[13].init(BING,3,4,computercolor);
    stones[14].init(BING,3,6,computercolor);
    stones[15].init(BING,3,8,computercolor);
    /////
    if(computercolor)computercolor=false;
    else
    computercolor=true;
    stones[16].init(CHE,9,0,computercolor);
    stones[17].init(MA,9,1,computercolor);
    stones[18].init(XIANG,9,2,computercolor);
    stones[19].init(SHI,9,3,computercolor);
    stones[20].init(JIANG,9,4,computercolor);
    stones[21].init(SHI,9,5,computercolor);
    stones[22].init(XIANG,9,6,computercolor);
    stones[23].init(MA,9,7,computercolor);
    stones[24].init(CHE,9,8,computercolor);
    stones[25].init(PAO,7,1,computercolor);
    stones[26].init(PAO,7,7,computercolor);
    stones[27].init(BING,6,0,computercolor);
    stones[28].init(BING,6,2,computercolor);
    stones[29].init(BING,6,4,computercolor);
    stones[30].init(BING,6,6,computercolor);
    stones[31].init(BING,6,8,computercolor);
    setMinimumSize(520,576);
    setMaximumSize(520,576);
    for(int i=0;i<10;i++)
        for(int j=0;j<9;j++)
            postoids[i][j]=-1;
   for(int id=0;id<32;id++)
   {
     postoids[stones[id].row][stones[id].col]=id;

   }

}
/*绘图里面根据属性值来绘图，而不改变属性值本身，即视图层不参与逻辑运算，让代码条理更清晰*/
void Board::paintEvent(QPaintEvent *event){

    painter.begin(this);
    painter.drawImage(0,0,QImage(":/images/BOARD.BMP"));
    for(int i=0;i<32;i++)
        stones[i].display(painter);
    painter.end();
}
QVector<Step> Board::chesteps(int moveId){
    QVector<Step> steps;
    int row=stones[moveId].row;
    int col=stones[moveId].col;
     //
    for(;row<10;row++)
    if(getstoneId(row,col)==-1)
    {
     steps.append(Step());
    }
    else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
    {
     break;
    }else{
     steps.append(Step());
    }
    row=stones[moveId].row;
    //
    for(;row>=0;row--)
    if(getstoneId(row,col)==-1)
    {
     steps.append(Step());
    }
    else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
    {
     break;
    }else{
     steps.append(Step());
    }
    row=stones[moveId].row;







}

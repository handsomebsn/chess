﻿#include "board.h"
//#define getstoneId(_row,_col) postoids[_row][_col]



#define samecolor(c1,c2) c1==c2
#define decolor(c1,c2) c1!=c2
Board::Board(QWidget *parent) : QWidget(parent),painter(this)
{  _level=4;
    computreture=false;
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
     /////////////////////////////在列上蛮力探索///////////////////////////////////////
    //列的下方进行探索
    for(row++;row<10;row++)
    if(getstoneId(row,col)==-1)//如果探索位置没有任何棋子
    {
     steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));//将走法插入到走法数组中
    }
    else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))//探索位置有子 和待走子同一种颜色
    {

     break;//此方向上停止探索
    }else{//探索位置有子 和待走子不同颜色

     steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));//将走法插入到走法数组中
     break;//此方向上停止探索
    }
    row=stones[moveId].row;
    //列的上方进行探索
    for(row--;row>=0;row--)
    if(getstoneId(row,col)==-1)
    {
     steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
    }
    else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
    {
     break;
    }else{
     steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
     break;
    }
    row=stones[moveId].row;
   //////////////////////////////////////在行上蛮力探索//////////////////////////////////////////////////////////////
    for(col++;col<9;col++)
    if(getstoneId(row,col)==-1)
    {
     steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
    }
    else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
    {
     break;
    }else{
     steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
     break;
    }
    col=stones[moveId].col;
    //
    for(col--;col>=0;col--)
    if(getstoneId(row,col)==-1)
    {
     steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
    }
    else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
    {
     break;
    }else{
     steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
     break;
    }

  return steps;
}


inline void Board::chesteps(int moveId, QVector<Step> &steps){
    int row=stones[moveId].row;
    int col=stones[moveId].col;
    //qDebug("%d %d %d",row,col,getstoneId(row,col));
     /////////////////////////////在列上蛮力探索///////////////////////////////////////
    for(row++;row<10;row++)
    if(getstoneId(row,col)==-1)
    {
     steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
    }
    else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
    {

     break;
    }else{

     steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
     break;
    }
    row=stones[moveId].row;
    //
    for(row--;row>=0;row--)
    if(getstoneId(row,col)==-1)
    {
     steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
    }
    else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
    {
     break;
    }else{
     steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
     break;
    }
    row=stones[moveId].row;
   //////////////////////////////////////在行上蛮力探索//////////////////////////////////////////////////////////////
    for(col++;col<9;col++)
    if(getstoneId(row,col)==-1)
    {
     steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
    }
    else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
    {
     break;
    }else{
     steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
     break;
    }
    col=stones[moveId].col;
    //
    for(col--;col>=0;col--)
    if(getstoneId(row,col)==-1)
    {
     steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
    }
    else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
    {
     break;
    }else{
     steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
     break;
    }
}

QVector<Step> Board::masteps(int moveId){
    QVector<Step> steps;
    int row=stones[moveId].row;
    int col=stones[moveId].col;
    if(row+2<10&&col+1<9&&getstoneId(row+1,col)==-1)
    if(getstoneId(row+2,col+1)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+2,col+1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row+2,col+1)].color))
          steps.append(Step(moveId,getstoneId(row+2,col+1),stones[moveId].row,stones[moveId].col,row+2,col+1));
    //
    if(row-2>=0&&col-1>=0&&getstoneId(row-1,col)==-1)
    if(getstoneId(row-2,col-1)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-2,col-1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-2,col-1)].color))
          steps.append(Step(moveId,getstoneId(row-2,col-1),stones[moveId].row,stones[moveId].col,row-2,col-1));
    //
    if(row-2>=0&&col+1<9&&getstoneId(row-1,col)==-1)
    if(getstoneId(row-2,col+1)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-2,col+1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-2,col+1)].color))
          steps.append(Step(moveId,getstoneId(row-2,col+1),stones[moveId].row,stones[moveId].col,row-2,col+1));
    //
    if(row+2<10&&col-1>=0&&getstoneId(row+1,col)==-1)
    if(getstoneId(row+2,col-1)==-1)
        steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+2,col-1));
    else if(decolor(stones[moveId].color,stones[getstoneId(row+2,col-1)].color))
         steps.append(Step(moveId,getstoneId(row+2,col-1),stones[moveId].row,stones[moveId].col,row+2,col-1));
    ///////////////////////////////////////////////////////////////////////
    if(row+1<10&&col+2<9&&getstoneId(row,col+1)==-1)
    if(getstoneId(row+1,col+2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+1,col+2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row+1,col+2)].color))
          steps.append(Step(moveId,getstoneId(row+1,col+2),stones[moveId].row,stones[moveId].col,row+1,col+2));
    //
    if(row-1>=0&&col-2>=0&&getstoneId(row,col-1)==-1)
    if(getstoneId(row-1,col-2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-1,col-2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-1,col-2)].color))
          steps.append(Step(moveId,getstoneId(row-1,col-2),stones[moveId].row,stones[moveId].col,row-1,col-2));
    //
    if(row-1>=0&&col+2<9&&getstoneId(row,col+1)==-1)
    if(getstoneId(row-1,col+2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-1,col+2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-1,col+2)].color))
          steps.append(Step(moveId,getstoneId(row-1,col+2),stones[moveId].row,stones[moveId].col,row-1,col+2));
    //
    if(row+1<10&&col-2>=0&&getstoneId(row,col-1)==-1)
    if(getstoneId(row+1,col-2)==-1)
        steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+1,col-2));
    else if(decolor(stones[moveId].color,stones[getstoneId(row+1,col-2)].color))
         steps.append(Step(moveId,getstoneId(row+1,col-2),stones[moveId].row,stones[moveId].col,row+1,col-2));

return steps;

}
inline void Board::masteps(int moveId, QVector<Step> &steps){

    int row=stones[moveId].row;
    int col=stones[moveId].col;
    if(row+2<10&&col+1<9&&getstoneId(row+1,col)==-1)
    if(getstoneId(row+2,col+1)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+2,col+1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row+2,col+1)].color))
          steps.append(Step(moveId,getstoneId(row+2,col+1),stones[moveId].row,stones[moveId].col,row+2,col+1));
    //
    if(row-2>=0&&col-1>=0&&getstoneId(row-1,col)==-1)
    if(getstoneId(row-2,col-1)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-2,col-1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-2,col-1)].color))
          steps.append(Step(moveId,getstoneId(row-2,col-1),stones[moveId].row,stones[moveId].col,row-2,col-1));
    //
    if(row-2>=0&&col+1<9&&getstoneId(row-1,col)==-1)
    if(getstoneId(row-2,col+1)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-2,col+1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-2,col+1)].color))
          steps.append(Step(moveId,getstoneId(row-2,col+1),stones[moveId].row,stones[moveId].col,row-2,col+1));
    //
    if(row+2<10&&col-1>=0&&getstoneId(row+1,col)==-1)
    if(getstoneId(row+2,col-1)==-1)
        steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+2,col-1));
    else if(decolor(stones[moveId].color,stones[getstoneId(row+2,col-1)].color))
         steps.append(Step(moveId,getstoneId(row+2,col-1),stones[moveId].row,stones[moveId].col,row+2,col-1));
    ///////////////////////////////////////////////////////////////////////
    if(row+1<10&&col+2<9&&getstoneId(row,col+1)==-1)
    if(getstoneId(row+1,col+2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+1,col+2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row+1,col+2)].color))
          steps.append(Step(moveId,getstoneId(row+1,col+2),stones[moveId].row,stones[moveId].col,row+1,col+2));
    //
    if(row-1>=0&&col-2>=0&&getstoneId(row,col-1)==-1)
    if(getstoneId(row-1,col-2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-1,col-2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-1,col-2)].color))
          steps.append(Step(moveId,getstoneId(row-1,col-2),stones[moveId].row,stones[moveId].col,row-1,col-2));
    //
    if(row-1>=0&&col+2<9&&getstoneId(row,col+1)==-1)
    if(getstoneId(row-1,col+2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-1,col+2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-1,col+2)].color))
          steps.append(Step(moveId,getstoneId(row-1,col+2),stones[moveId].row,stones[moveId].col,row-1,col+2));
    //
    if(row+1<10&&col-2>=0&&getstoneId(row,col-1)==-1)
    if(getstoneId(row+1,col-2)==-1)
        steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+1,col-2));
    else if(decolor(stones[moveId].color,stones[getstoneId(row+1,col-2)].color))
         steps.append(Step(moveId,getstoneId(row+1,col-2),stones[moveId].row,stones[moveId].col,row+1,col-2));

}


QVector<Step> Board::xiangsteps(int moveId){
    QVector<Step> steps;
    int row=stones[moveId].row;
    int col=stones[moveId].col;
    int rmin=0;
    int rmax=9;
    //qDebug("aaa");
    if(moveId<16)
          rmax=4;
        else
         rmin=5;
    //
   if(row+2<=rmax&&col+2<9&&getstoneId(row+1,col+1)==-1)
    if(getstoneId(row+2,col+2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+2,col+2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row+2,col+2)].color))
          steps.append(Step(moveId,getstoneId(row+2,col+2),stones[moveId].row,stones[moveId].col,row+2,col+2));
   //
   if(row-2>=rmin&&col-2>=0&&getstoneId(row-1,col-1)==-1)
    if(getstoneId(row-2,col-2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-2,col-2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-2,col-2)].color))
          steps.append(Step(moveId,getstoneId(row-2,col-2),stones[moveId].row,stones[moveId].col,row-2,col-2));
   //
   if(row-2>=rmin&&col+2<9&&getstoneId(row-1,col+1)==-1)
    if(getstoneId(row-2,col+2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-2,col+2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-2,col+2)].color))
          steps.append(Step(moveId,getstoneId(row-2,col+2),stones[moveId].row,stones[moveId].col,row-2,col+2));
  //
   if(row+2<=rmax&&col-2>=0&&getstoneId(row+1,col-1)==-1)
   if(getstoneId(row+2,col-2)==-1)
        steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+2,col-2));
    else if(decolor(stones[moveId].color,stones[getstoneId(row+2,col-2)].color))
         steps.append(Step(moveId,getstoneId(row+2,col-2),stones[moveId].row,stones[moveId].col,row+2,col-2));



return steps;
}

inline void Board::xiangsteps(int moveId, QVector<Step> &steps){
    int row=stones[moveId].row;
    int col=stones[moveId].col;
    int rmin=0;
    int rmax=9;
    //qDebug("aaa");
    if(moveId<16)
          rmax=4;
        else
         rmin=5;
    //
   if(row+2<=rmax&&col+2<9&&getstoneId(row+1,col+1)==-1)
    if(getstoneId(row+2,col+2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+2,col+2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row+2,col+2)].color))
          steps.append(Step(moveId,getstoneId(row+2,col+2),stones[moveId].row,stones[moveId].col,row+2,col+2));
   //
   if(row-2>=rmin&&col-2>=0&&getstoneId(row-1,col-1)==-1)
    if(getstoneId(row-2,col-2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-2,col-2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-2,col-2)].color))
          steps.append(Step(moveId,getstoneId(row-2,col-2),stones[moveId].row,stones[moveId].col,row-2,col-2));
   //
   if(row-2>=rmin&&col+2<9&&getstoneId(row-1,col+1)==-1)
    if(getstoneId(row-2,col+2)==-1)
         steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row-2,col+2));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-2,col+2)].color))
          steps.append(Step(moveId,getstoneId(row-2,col+2),stones[moveId].row,stones[moveId].col,row-2,col+2));
  //
   if(row+2<=rmax&&col-2>=0&&getstoneId(row+1,col-1)==-1)
   if(getstoneId(row+2,col-2)==-1)
        steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row+2,col-2));
    else if(decolor(stones[moveId].color,stones[getstoneId(row+2,col-2)].color))
         steps.append(Step(moveId,getstoneId(row+2,col-2),stones[moveId].row,stones[moveId].col,row+2,col-2));
}

QVector<Step> Board::shisteps(int moveId){
    QVector<Step> steps;
    int row=stones[moveId].row;
    int col=stones[moveId].col;
    int rmin=0;
    int rmax=9;
    //qDebug("aaa");
    if(moveId<16)
          rmax=2;
        else
         rmin=7;
     if(row+1<=rmax&&col+1<=5)
     if(getstoneId(row+1,col+1)==-1)
        steps.append(Step(moveId,getstoneId(row+1,col+1),stones[moveId].row,stones[moveId].col,row+1,col+1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row+1,col+1)].color))
         steps.append(Step(moveId,getstoneId(row+1,col+1),stones[moveId].row,stones[moveId].col,row+1,col+1));
//
     if(row-1>=rmin&&col-1>=3)
     if(getstoneId(row-1,col-1)==-1)
        steps.append(Step(moveId,getstoneId(row-1,col-1),stones[moveId].row,stones[moveId].col,row-1,col-1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-1,col-1)].color))
         steps.append(Step(moveId,getstoneId(row-1,col-1),stones[moveId].row,stones[moveId].col,row-1,col-1));
//

     if(row+1<=rmax&&col-1>=3)
     if(getstoneId(row+1,col-1)==-1)
        steps.append(Step(moveId,getstoneId(row+1,col-1),stones[moveId].row,stones[moveId].col,row+1,col-1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row+1,col-1)].color))
         steps.append(Step(moveId,getstoneId(row+1,col-1),stones[moveId].row,stones[moveId].col,row+1,col-1));

     if(row-1>=rmin&&col+1<=5)
     if(getstoneId(row-1,col+1)==-1)
        steps.append(Step(moveId,getstoneId(row-1,col+1),stones[moveId].row,stones[moveId].col,row-1,col+1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-1,col+1)].color))
         steps.append(Step(moveId,getstoneId(row-1,col+1),stones[moveId].row,stones[moveId].col,row-1,col+1));
return steps;

}

inline void Board::shisteps(int moveId, QVector<Step> &steps){

    int row=stones[moveId].row;
    int col=stones[moveId].col;
    int rmin=0;
    int rmax=9;
    //qDebug("aaa");
    if(moveId<16)
          rmax=2;
        else
         rmin=7;
     if(row+1<=rmax&&col+1<=5)
     if(getstoneId(row+1,col+1)==-1)
        steps.append(Step(moveId,getstoneId(row+1,col+1),stones[moveId].row,stones[moveId].col,row+1,col+1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row+1,col+1)].color))
         steps.append(Step(moveId,getstoneId(row+1,col+1),stones[moveId].row,stones[moveId].col,row+1,col+1));
//
     if(row-1>=rmin&&col-1>=3)
     if(getstoneId(row-1,col-1)==-1)
        steps.append(Step(moveId,getstoneId(row-1,col-1),stones[moveId].row,stones[moveId].col,row-1,col-1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-1,col-1)].color))
         steps.append(Step(moveId,getstoneId(row-1,col-1),stones[moveId].row,stones[moveId].col,row-1,col-1));
//

     if(row+1<=rmax&&col-1>=3)
     if(getstoneId(row+1,col-1)==-1)
        steps.append(Step(moveId,getstoneId(row+1,col-1),stones[moveId].row,stones[moveId].col,row+1,col-1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row+1,col-1)].color))
         steps.append(Step(moveId,getstoneId(row+1,col-1),stones[moveId].row,stones[moveId].col,row+1,col-1));

     if(row-1>=rmin&&col+1<=5)
     if(getstoneId(row-1,col+1)==-1)
        steps.append(Step(moveId,getstoneId(row-1,col+1),stones[moveId].row,stones[moveId].col,row-1,col+1));
     else if(decolor(stones[moveId].color,stones[getstoneId(row-1,col+1)].color))
         steps.append(Step(moveId,getstoneId(row-1,col+1),stones[moveId].row,stones[moveId].col,row-1,col+1));


}


QVector<Step> Board::jiangsteps(int moveId){
    QVector<Step> steps;
    int row=stones[moveId].row;
    int col=stones[moveId].col;
    int rmin=0;
    int rmax=9;
    //qDebug("aaa");
    if(moveId<16)
          rmax=2;
        else
         rmin=7;

    if(row-1>=rmin&&getstoneId(row-1,col)==-1)
              steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
        else if(row-1>=rmin&&decolor(stones[moveId].color,stones[getstoneId(row-1,col)].color))
              steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
    if(row+1<=rmax&&getstoneId(row+1,col)==-1)
              steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));
        else if(row+1<=rmax&&decolor(stones[moveId].color,stones[getstoneId(row+1,col)].color))
              steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));
   //////
    if(col+1<=5&&getstoneId(row,col+1)==-1)
              steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
        else if(col+1<=5&&col+1<9&&decolor(stones[moveId].color,stones[getstoneId(row,col+1)].color))
              steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
   //
    if(col-1>=3&&getstoneId(row,col-1)==-1)
              steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));
        else if(col-1>=3&&decolor(stones[moveId].color,stones[getstoneId(row,col-1)].color))
              steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));
    ;

    //////////////////////////////////老爷喝酒///////////////////////////////////////////////////////
    if(moveId<16)
    for(row++;row<10;row++){
       if(getstoneId(row,col)==-1)
           continue;
       else if(stones[getstoneId(row,col)].type!=JIANG)
           break;
       else
       steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
    }else
        for(row--;row>=0;row--){
           if(getstoneId(row,col)==-1)
               continue;
           else if(stones[getstoneId(row,col)].type!=JIANG)
               break;
           else
           steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
        }
    return steps;
}

inline void Board::jiangsteps(int moveId, QVector<Step> &steps){

    int row=stones[moveId].row;
    int col=stones[moveId].col;
    int rmin=0;
    int rmax=9;
    //qDebug("aaa");
    if(moveId<16)
          rmax=2;
        else
         rmin=7;

    if(row-1>=rmin&&getstoneId(row-1,col)==-1)
              steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
        else if(row-1>=rmin&&decolor(stones[moveId].color,stones[getstoneId(row-1,col)].color))
              steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
    if(row+1<=rmax&&getstoneId(row+1,col)==-1)
              steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));
        else if(row+1<=rmax&&decolor(stones[moveId].color,stones[getstoneId(row+1,col)].color))
              steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));
   //////
    if(col+1<=5&&getstoneId(row,col+1)==-1)
              steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
        else if(col+1<=5&&col+1<9&&decolor(stones[moveId].color,stones[getstoneId(row,col+1)].color))
              steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
   //
    if(col-1>=3&&getstoneId(row,col-1)==-1)
              steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));
        else if(col-1>=3&&decolor(stones[moveId].color,stones[getstoneId(row,col-1)].color))
              steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));
    ;

    //////////////////////////////////老爷喝酒///////////////////////////////////////////////////////
    if(moveId<16)
    for(row++;row<10;row++){
       if(getstoneId(row,col)==-1)
           continue;
       else if(stones[getstoneId(row,col)].type!=JIANG)
           break;
       else
       steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
    }else
        for(row--;row>=0;row--){
           if(getstoneId(row,col)==-1)
               continue;
           else if(stones[getstoneId(row,col)].type!=JIANG)
               break;
           else
           steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
        }



}


QVector<Step> Board::paosteps(int moveId){
    QVector<Step> steps;
    int row=stones[moveId].row;
    int col=stones[moveId].col;
    int numinline=0;
    //qDebug("%d %d %d",row,col,getstoneId(row,col));
     /////////////////////////////在列上蛮力探索///////////////////////////////////////
    for(row++;row<10;row++)
      if(numinline==0){//中间隔子为0个
           if(getstoneId(row,col)==-1)//无子
                 steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
               else
                  numinline++;

      }else{//中间隔子为1个
              if(getstoneId(row,col)==-1)//无子
                   continue;//次位置忽略，继续下一位置探索
              else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))//有子切相同颜色
                      break;
              else//无子且不同颜色
                 {steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
                  break;
                 }
      }
    row=stones[moveId].row;
    numinline=0;
    for(row--;row>=0;row--)
      if(numinline==0){
           if(getstoneId(row,col)==-1)
                 steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
               else
                  numinline++;

      }else{
              if(getstoneId(row,col)==-1)
                   continue;
              else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
                      break;
              else
                 {steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
                  break;
                 }
      }
      row=stones[moveId].row;
      numinline=0;
      //////////////////////////////////////在行上蛮力探索//////////////////////////////////////////////////////////////
      for(col++;col<9;col++)
        if(numinline==0){
             if(getstoneId(row,col)==-1)
                   steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
                 else
                    numinline++;

        }else{
                if(getstoneId(row,col)==-1)
                     continue;
                else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
                        break;
                else
                   {steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
                    break;
                   }
        }
      col=stones[moveId].col;
      numinline=0;
      for(col--;col>=0;col--)
        if(numinline==0){
             if(getstoneId(row,col)==-1)
                   steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
                 else
                    numinline++;

        }else{
                if(getstoneId(row,col)==-1)
                     continue;
                else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
                        break;
                else
                   {steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
                    break;
                   }
        }
      //col=stones[moveId].col;
      //numinline=0;
return steps;
}



void Board::paosteps(int moveId,QVector<Step> &steps){

    int row=stones[moveId].row;
    int col=stones[moveId].col;
    int numinline=0;
    //qDebug("%d %d %d",row,col,getstoneId(row,col));
     /////////////////////////////在列上蛮力探索///////////////////////////////////////
    for(row++;row<10;row++)
      if(numinline==0){
           if(getstoneId(row,col)==-1)
                 steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
               else
                  numinline++;

      }else{
              if(getstoneId(row,col)==-1)
                   continue;
              else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
                      break;
              else
                 {steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
                  break;
                 }
      }
    row=stones[moveId].row;
    numinline=0;
    for(row--;row>=0;row--)
      if(numinline==0){
           if(getstoneId(row,col)==-1)
                 steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
               else
                  numinline++;

      }else{
              if(getstoneId(row,col)==-1)
                   continue;
              else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
                      break;
              else
                 {steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
                  break;
                 }
      }
      row=stones[moveId].row;
      numinline=0;
      //////////////////////////////////////在行上蛮力探索//////////////////////////////////////////////////////////////
      for(col++;col<9;col++)
        if(numinline==0){
             if(getstoneId(row,col)==-1)
                   steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
                 else
                    numinline++;

        }else{
                if(getstoneId(row,col)==-1)
                     continue;
                else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
                        break;
                else
                   {steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
                    break;
                   }
        }
      col=stones[moveId].col;
      numinline=0;
      for(col--;col>=0;col--)
        if(numinline==0){
             if(getstoneId(row,col)==-1)
                   steps.append(Step(moveId,-1,stones[moveId].row,stones[moveId].col,row,col));
                 else
                    numinline++;

        }else{
                if(getstoneId(row,col)==-1)
                     continue;
                else if(samecolor(stones[moveId].color,stones[getstoneId(row,col)].color))
                        break;
                else
                   {steps.append(Step(moveId,getstoneId(row,col),stones[moveId].row,stones[moveId].col,row,col));
                    break;
                   }
        }
      //col=stones[moveId].col;
      //numinline=0;

}

QVector<Step> Board::bingsteps(int moveId){
 QVector<Step> steps;
 int row=stones[moveId].row;
 int col=stones[moveId].col;
 if(moveId<16){
      if(row<5){

          if(getstoneId(row+1,col)==-1)
                    steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));
              else if(decolor(stones[moveId].color,stones[getstoneId(row+1,col)].color))
                    steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));

      }else{
          if(row+1<10&&getstoneId(row+1,col)==-1)
                    steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));
              else if(row+1<10&&decolor(stones[moveId].color,stones[getstoneId(row+1,col)].color))
                    steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));
         //////
          if(col+1<9&&getstoneId(row,col+1)==-1)
                    steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
              else if(col+1<9&&decolor(stones[moveId].color,stones[getstoneId(row,col+1)].color))
                    steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
         //
          if(col-1>=0&&getstoneId(row,col-1)==-1)
                    steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));
              else if(col-1>=0&&decolor(stones[moveId].color,stones[getstoneId(row,col+1)].color))
                    steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));
      }
 }else{
     if(row>4){
         if(getstoneId(row-1,col)==-1)
                   steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
             else if(decolor(stones[moveId].color,stones[getstoneId(row-1,col)].color))
                   steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
     }else{
         if(row-1>=0&&getstoneId(row-1,col)==-1)
                   steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
             else if(row-1>=0&&decolor(stones[moveId].color,stones[getstoneId(row-1,col)].color))
                   steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
        //////
         if(col+1<9&&getstoneId(row,col+1)==-1)
                   steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
             else if(col+1<9&&decolor(stones[moveId].color,stones[getstoneId(row,col+1)].color))
                   steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
        //
         if(col-1>=0&&getstoneId(row,col-1)==-1)
                   steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));
             else if(col-1>=0&&decolor(stones[moveId].color,stones[getstoneId(row,col+1)].color))
                   steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));

     }
 }

return steps;
}
inline void Board::bingsteps(int moveId, QVector<Step> &steps){
    int row=stones[moveId].row;
    int col=stones[moveId].col;
    if(moveId<16){
         if(row<5){

             if(getstoneId(row+1,col)==-1)
                       steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));
                 else if(decolor(stones[moveId].color,stones[getstoneId(row+1,col)].color))
                       steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));

         }else{
             if(row+1<10&&getstoneId(row+1,col)==-1)
                       steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));
                 else if(row+1<10&&decolor(stones[moveId].color,stones[getstoneId(row+1,col)].color))
                       steps.append(Step(moveId,getstoneId(row+1,col),stones[moveId].row,stones[moveId].col,row+1,col));
            //////
             if(col+1<9&&getstoneId(row,col+1)==-1)
                       steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
                 else if(col+1<9&&decolor(stones[moveId].color,stones[getstoneId(row,col+1)].color))
                       steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
            //
             if(col-1>=0&&getstoneId(row,col-1)==-1)
                       steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));
                 else if(col-1>=0&&decolor(stones[moveId].color,stones[getstoneId(row,col+1)].color))
                       steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));
         }
    }else{
        if(row>4){
            if(getstoneId(row-1,col)==-1)
                      steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
                else if(decolor(stones[moveId].color,stones[getstoneId(row-1,col)].color))
                      steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
        }else{
            if(row-1>=0&&getstoneId(row-1,col)==-1)
                      steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
                else if(row-1>=0&&decolor(stones[moveId].color,stones[getstoneId(row-1,col)].color))
                      steps.append(Step(moveId,getstoneId(row-1,col),stones[moveId].row,stones[moveId].col,row-1,col));
           //////
            if(col+1<9&&getstoneId(row,col+1)==-1)
                      steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
                else if(col+1<9&&decolor(stones[moveId].color,stones[getstoneId(row,col+1)].color))
                      steps.append(Step(moveId,getstoneId(row,col+1),stones[moveId].row,stones[moveId].col,row,col+1));
           //
            if(col-1>=0&&getstoneId(row,col-1)==-1)
                      steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));
                else if(col-1>=0&&decolor(stones[moveId].color,stones[getstoneId(row,col+1)].color))
                      steps.append(Step(moveId,getstoneId(row,col-1),stones[moveId].row,stones[moveId].col,row,col-1));

        }
    }





}
bool Board::canmove(int moveId, int rowto, int colto){
  if(moveId<0||moveId>31)
     return false;
   TYPE _type=stones[moveId].type;
   QVector<Step> steps;
   switch (_type) {
   case CHE:
       steps=chesteps(moveId);
       break;
    case MA:
       steps=masteps(moveId);
       break;
   case XIANG:
       steps=xiangsteps(moveId);
       break;
   case SHI:
       steps=shisteps(moveId);
       break;
   case JIANG:
       steps=jiangsteps(moveId);
       break;
   case PAO:
       steps=paosteps(moveId);
       break;
   case BING:
       steps=bingsteps(moveId);
       break;
   default:
       break;
   }

return steps.contains(Step(moveId,getstoneId(rowto,colto),stones[moveId].row,stones[moveId].col,rowto,colto));
}


void Board::move(int moveId, int rowto, int colto){
    qDebug("move %d ",moveId);
    postoids[stones[moveId].row][stones[moveId].col]=-1;
    stones[moveId].row=rowto;
    stones[moveId].col=colto;
    if(getstoneId(rowto,colto)!=-1)
       stones[getstoneId(rowto,colto)].dead=true;

    postoids[rowto][colto]=moveId;
    if(computreture)
        computreture=false;
    else
        computreture=true;
    int num=0;
    for(int i=0;i<32;i++){
        if(stones[i].dead)
        num++;
    }
    if(num<10)
        _level=4;
    else if(num<20)
        _level=5;
    else if(num<26)
        _level=6;
    else
        _level=7;



}

void Board::mousePressEvent(QMouseEvent *event){
if(computreture)
    return;

//qDebug("haha");
    static int moveid=-1;
    int killedid=-1;
    int row,col;
if(moveid==-1){
  row=(event->y()-Stone::offy+Stone::jiange/2)/Stone::jiange;
 col=(event->x()-Stone::offx+Stone::jiange/2)/Stone::jiange;
//
 if(row<0||row>9||col<0||col>8)
 {qDebug("%d...... %d when select moveid",row,col);return;}
 qDebug("frow %d %d",row,col);
 moveid=getstoneId(row,col);
 if(moveid!=-1)
stones[moveid].gaoliang(true);
 qDebug("moveid %d ",moveid);
}else{

    row=(event->y()-Stone::offy+Stone::jiange/2)/Stone::jiange;
   col=(event->x()-Stone::offx+Stone::jiange/2)/Stone::jiange;
  //
   qDebug("to %d %d",row,col);
   if(row<0||row>9||col<0||col>8)
   {qDebug("%d...... %d",row,col);return;}
   killedid=getstoneId(row,col);
   qDebug(" moveid  %d killedid %d",moveid,killedid);
   if(killedid!=-1&&samecolor(stones[killedid].color,stones[moveid].color))
    {stones[moveid].gaoliang(false);moveid=killedid;stones[moveid].gaoliang(true);update();return;}
   //qDebug("haha");
   if(canmove(moveid,row,col))
   {qDebug("haha");
  move(moveid,row,col);
  stones[moveid].gaoliang(false);
  //
  moveid=-1;

   }
}
update();
}

inline void Board::getAllsteps(QVector<Step> &steps, bool player){
int min=0,max=32;
if(player)
    min=16;
else
   max=16;
for(int moveId=min;moveId<max;moveId++)
  {
    if(stones[moveId].dead)continue;//have changed it for delete bug
    switch (stones[moveId].type) {
    case CHE:
        chesteps(moveId,steps);
        break;
     case MA:
        masteps(moveId,steps);
        break;
    case XIANG:
        xiangsteps(moveId,steps);
        break;
    case SHI:
        shisteps(moveId,steps);
        break;
    case JIANG:
        jiangsteps(moveId,steps);
        break;
    case PAO:
        paosteps(moveId,steps);
        break;
    case BING:
        bingsteps(moveId,steps);
        break;
    default:
        break;
    }
   }

}
void Board::move(const Step &step){
    postoids[step.rowFrom][step.colFrom]=-1;
    stones[step.moveId].row=step.rowTo;
    stones[step.moveId].col=step.colTo;
    if(step.killId!=-1)
       stones[step.killId].dead=true;

    postoids[step.rowTo][step.colTo]=step.moveId;

}
void Board::unmove(const Step &step){
    postoids[step.rowTo][step.colTo]=step.killId;
    stones[step.moveId].row=step.rowFrom;
    stones[step.moveId].col=step.colFrom;
    if(step.killId!=-1)
       stones[step.killId].dead=false;

    postoids[step.rowFrom][step.colFrom]=step.moveId;


}


int Board::score()
{
    // enum TYPE{CHE, MA, PAO, BING, JIANG, SHI, XIANG};
    static int s[] = {1000, 499, 501, 200, 15000, 100, 100};
    int scorecomputre = 0;
    int scoreplayer = 0;

    for(int i = 0; i < 16; ++i)
    {
        if(stones[i].dead) continue;
        scorecomputre += s[stones[i].type];
    }
    for(int i = 16; i < 32; ++i)
    {
        if(stones[i].dead) continue;
        scoreplayer += s[stones[i].type];
    }
    return scorecomputre- scoreplayer;
}

int Board::getMinScore(int level, int curMin)
{
    if(level == 0)
    {
        return score();
    }
    //if(stones[4].dead||stones[20].dead)
    //return score();
    QVector<Step> steps;
    getAllsteps(steps,true);
    int minInAllMaxScore = 300000;
    for(int i=0;i<steps.count();i++)
    {
        move(steps.at(i));
        if(stones[4].dead){
         unmove(steps.at(i));
        return -10000;
        }


        int maxScore = getMaxScore(level - 1, minInAllMaxScore);
        unmove(steps.at(i));

        if(maxScore <= curMin)
        {
        qDebug("..............................");
            return maxScore;
        }

        if(maxScore < minInAllMaxScore)
        {
            minInAllMaxScore = maxScore;
        }
    }
    return minInAllMaxScore;
}

int Board::getMaxScore(int level, int curMax)
{
    if(level == 0)
        return score();
    //if(stones[4].dead||stones[20].dead)
    //return score();
    QVector<Step> steps;
    getAllsteps(steps,false);
    int maxInAllMinScore = -300000;
    for(int i=0;i<steps.count();i++)
    {
        move(steps.at(i));
        if(stones[20].dead){
         unmove(steps.at(i));
        return 10000;
        }
        int minScore = getMinScore(level - 1, maxInAllMinScore);
        unmove(steps.at(i));
        if(minScore >= curMax)
        {
            return minScore;
        }
        if(minScore > maxInAllMinScore)
        {
            maxInAllMinScore = minScore;
        }
    }
    return maxInAllMinScore;
}
Step Board::getcomputerbeststep(){
    Step beststep;
   QVector<Step> steps;
    getAllsteps(steps,false);
    qDebug("gong you %d zou fa",steps.count());
      int maxInAllMinScore = -300000;

      for(int i=0;i<steps.count();i++)
      {
          move(steps.at(i));
          int minScore = getMinScore(_level, maxInAllMinScore);
           //qDebug("jumianfenshu %d",minScore);
          unmove(steps.at(i));
          if(minScore > maxInAllMinScore)
          {
              maxInAllMinScore = minScore;
              beststep=steps.at(i);
          }
      }

return beststep;
}


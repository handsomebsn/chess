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

  return steps;
}


void Board::chesteps(int moveId, QVector<Step> &steps){
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



QVector<Step> Board::paosteps(int moveId){
    QVector<Step> steps;
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
return steps;
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
   case PAO:
       steps=paosteps(moveId);
       break;
   default:
       break;
   }

return steps.contains(Step(moveId,getstoneId(rowto,colto),stones[moveId].row,stones[moveId].col,rowto,colto));
}


void Board::move(int moveId, int rowto, int colto){
    postoids[stones[moveId].row][stones[moveId].col]=-1;
    stones[moveId].row=rowto;
    stones[moveId].col=colto;
    if(getstoneId(rowto,colto)!=-1)
       stones[getstoneId(rowto,colto)].dead=true;

    postoids[rowto][colto]=moveId;
}

void Board::mousePressEvent(QMouseEvent *event){

//qDebug("haha");
    static int moveid=-1;
    int killedid=-1;
    int row,col;
if(moveid==-1){
  row=(event->y()-Stone::offy+Stone::jiange/2)/Stone::jiange;
 col=(event->x()-Stone::offx+Stone::jiange/2)/Stone::jiange;
//
 qDebug("frow %d %d",row,col);
 moveid=getstoneId(row,col);
 if(moveid!=-1)
stones[moveid].gaoliang(true);
}else{

    row=(event->y()-Stone::offy+Stone::jiange/2)/Stone::jiange;
   col=(event->x()-Stone::offx+Stone::jiange/2)/Stone::jiange;
  //
   qDebug("to %d %d",row,col);
   killedid=getstoneId(row,col);
   qDebug(" moveid  %d killedid %d",moveid,killedid);
   if(killedid!=-1&&samecolor(stones[killedid].color,stones[moveid].color))
    {stones[moveid].gaoliang(false);moveid=killedid;stones[moveid].gaoliang(true);update();return;}
   qDebug("haha");
   if(canmove(moveid,row,col))
   {
  move(moveid,row,col);
  stones[moveid].gaoliang(false);
  moveid=-1;

   }
}
update();
}


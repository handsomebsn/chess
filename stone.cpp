#include "stone.h"
#include<QRect>
QImage Stone::imgrche=QImage(":/images/rche.png");
QImage Stone::imgrma=QImage(":/images/rma.png");
QImage Stone::imgrxiang=QImage(":/images/rxiang.png");
QImage Stone::imgrshi=QImage(":/images/rshi.png");
QImage Stone::imgrjiang=QImage(":/images/rjiang.png");
QImage Stone::imgrpao=QImage(":/images/rpao.png");
QImage Stone::imgrbing=QImage(":/images/rbing.png");
QImage Stone::imgbche=QImage(":/images/bche.png");
QImage Stone::imgbma=QImage(":/images/bma.png");
QImage Stone::imgbxiang=QImage(":/images/bxiang.png");
QImage Stone::imgbshi=QImage(":/images/bshi.png");
QImage Stone::imgbjiang=QImage(":/images/bjiang.png");
QImage Stone::imgbpao=QImage(":/images/bpao.png");
QImage Stone::imgbbing=QImage(":/images/bbing.png");
int Stone::r=28;
int Stone::jiange=56;
int Stone::offx=36;
int Stone::offy=36;
Stone::Stone()
{

}
Stone::Stone(TYPE _type, int _row, int _col, bool _color, bool _dead)
{

    type=_type;
    row=_row;
    col=_col;
    color=_color;
    dead=_dead;

}
QString Stone::name(){
    switch(this->type)
    {
    case CHE:
        return "车";
    case MA:
        return "马";
    case PAO:
        return "炮";
    case BING:
        return "兵";
    case JIANG:
        return "将";
    case SHI:
        return "士";
    case XIANG:
        return "相";
    }
    return "错误";
}
void Stone::init(TYPE _type, int _row, int _col, bool _color, bool _dead){
    type=_type;
    row=_row;
    col=_col;
    color=_color;
    dead=_dead;
}

void Stone::display(QPainter &painter){
    if(this->dead)
        return;
    //根据所在行号和列号算出中心点位置
    int x=col*jiange+offx;
    int y=row*jiange+offy;

    //根据中心点位置算出棋子矩形范围
    QRect rect(x-r,y-r,2*r,2*r);

   if(this->color)
       switch(this->type)
       {
       case CHE:
           //painter.drawImage(rect,imgrche);
           painter.drawImage(rect,QImage(":/images/rche.png"));
           break;
       case MA:
           painter.drawImage(rect,QImage(":/images/rma.png"));
           break;
       case PAO:
           painter.drawImage(rect,QImage(":/images/rpao.png"));
           break;
       case BING:
           painter.drawImage(rect,QImage(":/images/rbing.png"));
           break;
       case JIANG:
          painter.drawImage(rect,QImage(":/images/rjiang.png"));
           break;
       case SHI:
          painter.drawImage(rect,QImage(":/images/rshi.png"));
           break;
       case XIANG:
          painter.drawImage(rect,QImage(":/images/rxiang.png"));
           break;
       }

   else
       switch(this->type)
       {
       case CHE:
           painter.drawImage(rect,QImage(":/images/bche.png"));
           break;
       case MA:
           painter.drawImage(rect,QImage(":/images/bma.png"));
           break;
       case PAO:
           painter.drawImage(rect,QImage(":/images/bpao.png"));
           break;
       case BING:
           painter.drawImage(rect,QImage(":/images/bbing.png"));
           break;
       case JIANG:
          painter.drawImage(rect,QImage(":/images/bjiang.png"));
           break;
       case SHI:
          painter.drawImage(rect,QImage(":/images/bshi.png"));
           break;
       case XIANG:
          painter.drawImage(rect,QImage(":/images/bxiang.png"));
           break;
       }

}


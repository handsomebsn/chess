#include "board.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  Board w;
  w.move(9,5,1);
  w.move(25,7,2);
  QVector<Step> vects= w.paosteps(9);
  for(int i=0;i<vects.count();i++)
  qDebug("%d %d",vects.at(i).rowTo,vects.at(i).colTo);


    w.show();

    return a.exec();
}

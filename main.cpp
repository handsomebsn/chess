#include "board.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  Board w;
  w.move(0,6,1);
  QVector<Step> vects= w.chesteps(0);
  for(int i=0;i<vects.count();i++)
  qDebug("%d %d",vects.at(i).rowTo,vects.at(i).colTo);


    w.show();

    return a.exec();
}

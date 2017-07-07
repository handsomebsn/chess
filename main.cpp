#include "board.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  Board w;

  QVector<Step> steps;
  w.getAllsetps(steps);
  for(int i=0;i<steps.count();i++){
  qDebug("%d %d %d",steps.at(i).moveId,steps.at(i).rowTo,steps.at(i).colTo);
w.move(steps.at(i));
w.unmove(steps.at(i));
}
    w.show();

    return a.exec();
}

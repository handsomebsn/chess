#include "board.h"
#include <QApplication>
#include<ctime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  Board w;
double start=clock();

  QVector<Step> steps;


double end=clock();
qDebug("%f",end-start);
    w.show();

    return a.exec();
}

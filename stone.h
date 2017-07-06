#ifndef STONE_H
#define STONE_H
#include<QString>
#include<QPainter>

//所有棋子名称
enum TYPE{CHE, MA, PAO,  BING, JIANG, SHI, XIANG};
class Stone
{
public:
    Stone(); 
    Stone(TYPE _type,int _row,int _col,bool _red=false,bool _dead=true);
    //获得棋子中文名称
    QString name();
    friend class Board;
protected:
    int row;//棋子所在的行
    int col;//棋子所在的列
    //是否死棋
    bool dead;
    //棋子颜色
    bool color;//true 为红色 false为黑色
    //棋子名称
    TYPE type;
    //
    void init(TYPE _type,int _row,int _col,bool _color=true,bool _dead=false);
    //
    void display(QPainter &painter);

/////////////////////////////

    static QImage imgrche;
    static QImage imgrma;
    static QImage imgrxiang;
    static QImage imgrshi;
    static QImage imgrjiang;
    static QImage imgrpao;
    static QImage imgrbing;

    static QImage imgbche;
    static QImage imgbma;
    static QImage imgbxiang;
    static QImage imgbshi;
    static QImage imgbjiang;
    static QImage imgbpao;
    static QImage imgbbing;
    ///
    static int r;//棋子半径
    static int jiange;//棋子中心点间隔
    static int offx;//棋子x偏移量，像素
    static int offy;//棋子y偏移量，像素

};

#endif // STONE_H

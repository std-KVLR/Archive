#include <iostream>
#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include <vector>
#include "My_Box.h"
#include <cmath>
using namespace std;

int main()
{
    using namespace Graph_lib;
    Simple_window win(Point(400,150), 750, 750, "My Window");

    BinaryTree test1(Point(100,100), 1);
    BinaryTree test2(Point(300,300), 2);
    BinaryTree test3(Point(500,500), 3);
    win.attach(test1);
    win.attach(test2);
    win.attach(test3);
    win.wait_for_button();


    return 0;
}

















void task14_ChessBoard()
{
        using namespace Graph_lib;
    Simple_window win(Point(400,150), 750, 750, "My Window");

    Vector_ref<Rectangle> board;
    Vector_ref<Circle> checkers;

    for(int y = 0, i = 12; y < 600; y+= 75, i-=4){

        static bool BW = 0;
        static bool GR = 0;
        if(y == 375){ i = 12, GR = 1;}

        for(size_t x = 0; x < 600; x+=75){

            board.push_back(new Rectangle(Point(x, y), 75, 75));

            if(BW == 0) board[board.size() - 1].set_fill_color(Color::white);
            else {
                board[board.size() - 1].set_fill_color(Color::black);

                if( i > 0){
                    checkers.push_back(new Circle(board[board.size() - 1].center(), 38));
                    if(GR == 0) checkers[checkers.size() - 1].set_fill_color(Color::dark_magenta);
                    else checkers[checkers.size() - 1].set_fill_color(Color::red);
                }

            }
            win.attach(board[board.size() - 1]);
            BW = !BW;
        }
        BW = !BW;
    }
    for(size_t i = 0; i < checkers.size() - 1; ++i) win.attach(checkers[i]);

    win.wait_for_button();
    checkers[8].move(-75,75);
    //win.put_on_top(checkers[8]);
    win.wait_for_button();
    checkers[15].move(75, -75);
    win.wait_for_button();
}



void task13_0()
{
    Simple_window win(Point(400,150), 800, 1000, "My Window");
    Vector_ref<Rectangle> vr;

    for(size_t i = 0; i < 8; ++i){
        for(size_t j = 0 ; j < 8; ++j){
            vr.push_back(new Rectangle(Point(i*100, j *100), 100,100));
            //vr[vr.size() -1].set_fill_color(i*8+j);
            win.attach(vr[vr.size()-1]);
        }
    }

      Vector_ref<Image> vii;

    /*for(size_t i = 0; i < 3; ++i)
    {
        vii.push_back(new Image(Point(i*150,0),"60545068_p0_master1200.jpg",Suffix::jpg));
        vii[vii.size() -1].set_mask(Point(i*150,0),100,100);
        win.attach(vii[vii.size()-1]);
    }*/

    /*for(size_t i = 0, j = 0; i < 8; ++i, ++j)
    {
        vr.push_back(new Rectangle(Point(i*50, j *50), 50,50));
        vr[vr.size() -1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }*/
    Image nextii(Point(0,0),"71204910_p0.jpg", Suffix::jpg);
    nextii.set_mask(Point(0,0),100,100);
    win.attach(nextii);

    for(size_t i = 1; i < 10; ++i){
        for(size_t j = 1 ; j <= 8;){
            if(win.wait_for_button()){
            nextii.move(100, 0);
            ++j;
            }
        }
        nextii.move(-800, 100);
    }

    win.wait_for_button();
}
void task12_0()
{
    Point tl(100,100);
    Simple_window win(tl,600,400,"Canvas");

    Axis xa(Axis::x, Point(20,300), 280, 10, "x Axis");
    win.attach(xa);

    Axis ya(Axis::y, Point(20,300), 280, 10, "y Axis");
    win.attach(ya);


    Function sine(sin, 0, 100, Point(20,150), 1000, 50, 50);
    sine.set_color(Color::blue);
    win.attach(sine);

    Polygon poly;
    poly.add(Point(300,200));
    poly.add(Point(350,100));
    poly.add(Point(400,200));
    poly.set_color(Color::red);
    poly.set_fill_color(Color::red);
    win.attach(poly);

    Rectangle r(Point(200,200),100,50);
    r.set_color(Color::dark_green);
    r.set_fill_color(Color::dark_green);
    win.attach(r);

    Polygon f;
    f.add(Point(100,50));
    f.add(Point(200,50));
    f.add(Point(200,100));
    f.add(Point(100,100));
    f.add(Point(50,75));

    f.set_color(Color::yellow);
    f.set_fill_color(Color::yellow);
    win.attach(f);

    Text t(Point(250,50), "Hello World!");
    t.set_font(Graph_lib::Font::times_bold);
    t.set_font_size(20);

    win.attach(t);

    win.wait_for_button();
}

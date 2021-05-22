#ifndef MY_BOX_H
#define MY_BOX_H

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"
#include <cmath>



struct Box{

    Box(Point fp, int w, int h, int R);

    void draw(Simple_window& workW);

    Point getA() const {return points[0];}
    Point getB() const {return points[2];}
    Point getC() const {return points[3];}
    Point getD() const {return points[4];}
    int width() const {return ww;}
    int height() const {return hh;}
private:
    Lines containerLs;
    Vector_ref<Arc> arcs;
    void makePoints(Point &A, Point &B, Point &C, Point &D,
                    const int w, const int h);
    int ww;
    int hh;
    Point points[4];
};

Point turnPoint(const Point& axis, const Point& rotPoint, int angle);

class Arrow{
    public:
        Arrow(Point sp, Point ep);
        void draw(Simple_window& workW);
    private:
        Lines containerLs;
};

class Hexagon{
    public:
        Hexagon(Point sp, int len);

        void draw(Simple_window& workW);
    private:
        int L;
        Lines containerLs;
};

class PseudoWindow {

public:
    PseudoWindow(Point p, int w, int h, const string& name)
    : myWindow(p, w , h + 20, (w+h)/20),
      manLine(Point(p.x, p.y + 20), Point(p.x + w, p.y + 20)),
      label(Point(p.x + w/20, p.y + 15), name)
    {
        label.set_font_size((w/4)/2);
        contBut.add(Point((p.x + w) - w/4, p.y), Point((p.x + w) - w/4, p.y + 20));
        contBut.add(Point((p.x + w) - w/4 + w/16, p.y), Point((p.x + w) - w/4 + w/16, p.y + 20));
        contBut.add(Point((p.x + w) - w/4 + w/8, p.y), Point((p.x + w) - w/4 + w/8, p.y + 20));

    }
    void draw (Simple_window& win){
        myWindow.draw(win);
        win.attach(manLine);
        win.attach(label);
        win.attach(contBut);
    }
private:
    Box myWindow;
    Line manLine;
    Text label;
    Lines contBut;

};


#endif // MY_BOX_H

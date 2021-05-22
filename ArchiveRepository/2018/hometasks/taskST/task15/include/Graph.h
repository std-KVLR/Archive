
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef GRAPH_GUARD
#define GRAPH_GUARD 1

#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include "Point.h"
#include "std_lib_facilities.h"
#include <iostream>

namespace Graph_lib {

// defense against ill-behaved Linux macros:
#undef major
#undef minor

//------------------------------------------------------------------------------

// Color is the type we use to represent color. We can use Color like this:
//    grid.set_color(Color::red);
struct Color {
    enum Color_type {
        red=FL_RED,
        blue=FL_BLUE,
        green=FL_GREEN,
        yellow=FL_YELLOW,
        white=FL_WHITE,
        black=FL_BLACK,
        magenta=FL_MAGENTA,
        cyan=FL_CYAN,
        dark_red=FL_DARK_RED,
        dark_green=FL_DARK_GREEN,
        dark_yellow=FL_DARK_YELLOW,
        dark_blue=FL_DARK_BLUE,
        dark_magenta=FL_DARK_MAGENTA,
        dark_cyan=FL_DARK_CYAN
    };

    enum Transparency { invisible = 0, visible=255 };

    Color(Color_type cc) :c(Fl_Color(cc)), v(visible) { }
    Color(Color_type cc, Transparency vv) :c(Fl_Color(cc)), v(vv) { }
    Color(int cc) :c(Fl_Color(cc)), v(visible) { }
    Color(Transparency vv) :c(Fl_Color()), v(vv) { }    // default color

    int as_int() const { return c; }

    char visibility() const { return v; }
    void set_visibility(Transparency vv) { v=vv; }
private:
    char v;    // invisible and visible for now
    Fl_Color c;
};

//------------------------------------------------------------------------------

struct Line_style {
    enum Line_style_type {
        solid=FL_SOLID,            // -------
        dash=FL_DASH,              // - - - -
        dot=FL_DOT,                // .......
        dashdot=FL_DASHDOT,        // - . - .
        dashdotdot=FL_DASHDOTDOT,  // -..-..
    };

    Line_style(Line_style_type ss) :s(ss), w(0) { }
    Line_style(Line_style_type lst, int ww) :s(lst), w(ww) { }
    Line_style(int ss) :s(ss), w(0) { }

    int width() const { return w; }
    int style() const { return s; }
private:
    int s;
    int w;
};

//------------------------------------------------------------------------------

class Font {
public:
    enum Font_type {
        helvetica=FL_HELVETICA,
        helvetica_bold=FL_HELVETICA_BOLD,
        helvetica_italic=FL_HELVETICA_ITALIC,
        helvetica_bold_italic=FL_HELVETICA_BOLD_ITALIC,
        courier=FL_COURIER,
        courier_bold=FL_COURIER_BOLD,
        courier_italic=FL_COURIER_ITALIC,
        courier_bold_italic=FL_COURIER_BOLD_ITALIC,
        times=FL_TIMES,
        times_bold=FL_TIMES_BOLD,
        times_italic=FL_TIMES_ITALIC,
        times_bold_italic=FL_TIMES_BOLD_ITALIC,
        symbol=FL_SYMBOL,
        screen=FL_SCREEN,
        screen_bold=FL_SCREEN_BOLD,
        zapf_dingbats=FL_ZAPF_DINGBATS
    };

    Font(Font_type ff) :f(ff) { }
    Font(int ff) :f(ff) { }

    int as_int() const { return f; }
private:
    int f;
};

//------------------------------------------------------------------------------

template<class T> class Vector_ref {
    vector<T*> v;
    vector<T*> owned;
public:
    Vector_ref() {}
    Vector_ref(T& a) { push_back(a); }
    Vector_ref(T& a, T& b);
    Vector_ref(T& a, T& b, T& c);
    Vector_ref(T* a, T* b = 0, T* c = 0, T* d = 0)
    {
        if (a) push_back(a);
        if (b) push_back(b);
        if (c) push_back(c);
        if (d) push_back(d);
    }

    ~Vector_ref() { for (int i=0; i<owned.size(); ++i) delete owned[i]; }

    void push_back(T& s) { v.push_back(&s); }
    void push_back(T* p) { v.push_back(p); owned.push_back(p); }

    T& operator[](int i) { return *v[i]; }
    const T& operator[](int i) const { return *v[i]; }

    int size() const { return v.size(); }
};

//------------------------------------------------------------------------------

typedef double Fct(double);

class Shape  {        // deals with color and style, and holds sequence of lines
public:
    void draw() const;                 // deal with color and draw lines
    virtual void move(int dx, int dy); // move the shape +=dx and +=dy

    void set_color(Color col) { lcolor = col; }
    Color color() const { return lcolor; }
    void set_style(Line_style sty) { ls = sty; }
    Line_style style() const { return ls; }
    void set_fill_color(Color col) { fcolor = col; }
    Color fill_color() const { return fcolor; }

    Point point(int i) const { return points[i]; } // read only access to points
    int number_of_points() const { return int(points.size()); }

    virtual ~Shape() { }
protected:
    Shape();
    virtual void draw_lines() const;   // draw the appropriate lines
    void add(Point p);                 // add p to points
    void set_point(int i,Point p);     // points[i]=p;
private:
    vector<Point> points;              // not used by all shapes
    Color lcolor;                      // color for lines and characters
    Line_style ls;
    Color fcolor;                      // fill color

    Shape(const Shape&);               // prevent copying
    Shape& operator=(const Shape&);
};

//------------------------------------------------------------------------------

struct Function : Shape {
    // the function parameters are not stored
    Function(Fct f, double r1, double r2, Point orig,
        int count = 100, double xscale = 25, double yscale = 25);
};

//------------------------------------------------------------------------------

struct Line : Shape {            // a Line is a Shape defined by two Points
    Line(Point p1, Point p2);    // construct a line from two points
};

//------------------------------------------------------------------------------

struct Rectangle : Shape {

    Rectangle(Point xy, int ww, int hh) : fp(xy), w(ww), h(hh)
    {
        add(xy);
        if (h<=0 || w<=0) error("Bad rectangle: non-positive side");
    }

    Rectangle(Point x, Point y) : fp(x), w(y.x-x.x), h(y.y-x.y)
    {
        add(x);
        if (h<=0 || w<=0) error("Bad rectangle: non-positive width or height");
    }

    void draw_lines() const;

    int height() const { return h; }
    int width() const { return w; }
    Point n() const { return Point(fp.x + w/2, fp.y);}
    Point s() const { return Point(fp.x + w/2, fp.y + h);}
    Point e() const { return Point(fp.x + w, fp.y + h/2);}
    Point west() const { return Point(fp.x , fp.y + h/2);}
    Point center() const { return Point(fp.x + w/2, fp.y + h/2);}
    Point ne() const { return Point(fp.x + w, fp.y);}
    Point se() const { return Point(fp.x + w, fp.y + h);}
    Point sw() const { return Point(fp.x , fp.y + h);}
    Point nw() const { return fp;}
private:
    Point fp;
    int h;    // height
    int w;    // width
};

class StripedRectangle : public Shape{
public:
    StripedRectangle(Point xy, int ww, int hh);

    void draw_lines() const;

private:
    Point fp;
    int h;
    int w;

    void striping(const Point& fp, int lowest, int higest, bool eq);
};

//------------------------------------------------------------------------------

struct Open_polyline : Shape {         // open sequence of lines
    void add(Point p) { Shape::add(p); }
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Closed_polyline : Open_polyline { // closed sequence of lines
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Polygon : Closed_polyline {    // closed sequence of non-intersecting lines
    void add(Point p);
    void draw_lines() const;
};

//------------------------------------------------------------------------------



struct Lines : Shape {                 // related lines
    void draw_lines() const;
    void add(Point p1, Point p2);      // add a line defined by two points
};

//------------------------------------------------------------------------------

struct Text : Shape {
    // the point is the bottom left of the first letter
    Text(Point x, const string& s) : lab(s), fnt(fl_font()), fnt_sz(fl_size()) { add(x); }

    void draw_lines() const;

    void set_label(const string& s) { lab = s; }
    string label() const { return lab; }

    void set_font(Font f) { fnt = f; }
    Font font() const { return Font(fnt); }

    void set_font_size(int s) { fnt_sz = s; }
    int font_size() const { return fnt_sz; }
private:
    string lab;    // label
    Font fnt;
    int fnt_sz;
};

//------------------------------------------------------------------------------

struct Axis : Shape {
    enum Orientation { x, y, z };
    Axis(Orientation d, Point xy, int length,
        int number_of_notches=0, string label = "");

    void draw_lines() const;
    void move(int dx, int dy);
    void set_color(Color c);

    Text label;
    Lines notches;
};

//------------------------------------------------------------------------------

struct Circle : Shape {
    Circle() : r(0){};
    Circle(Point p, int rr);    // center and radius

    void draw_lines() const;

    Point center() const ;
    int radius() const { return r; }
    void set_radius(int rr) { r=rr; }
private:
    int r;
};

//------------------------------------------------------------------------------

struct Ellipse : Shape {
    Ellipse(Point p, int w, int h)    // center, min, and max distance from center
        : w(w), h(h)
    {
        add(Point(p.x-w,p.y-h));
    }

    void draw_lines() const;

    Point center() const { return Point(point(0).x+w,point(0).y+h); }
    Point focus1() const { return Point(center().x+int(sqrt(double(w*w-h*h))),center().y); }
    Point focus2() const { return Point(center().x-int(sqrt(double(w*w-h*h))),center().y); }

    void set_major(int ww) { w=ww; }
    int major() const { return w; }
    void set_minor(int hh) { h=hh; }
    int minor() const { return h; }
private:
    int w;
    int h;
};

//------------------------------------------------------------------------------

struct Arc : Shape {
    Arc(Point p, int w, int h)
        :w(w), h(h)
    {
        add(Point(p.x - w, p.y - h));

    }
    Arc(Point p, int w, int h, int stA, int enA)
        :w(w), h(h)
    {
        if(stA < 0 || enA < 0){
                throw runtime_error("error: arc's start or end coordinates is a negative number");
        }
        startA = stA, endA = enA;
        add(Point(p.x - w, p.y - h));

    }
    void draw_lines() const;

private:
    int w;
    int h;
    int startA = 0;
    int endA = 180;
};

//-----------------------------------------------------------------------------

struct Marked_polyline : Open_polyline {
    Marked_polyline(const string& m) :mark(m) { }
    void draw_lines() const;
private:
    string mark;
};

//------------------------------------------------------------------------------

struct Marks : Marked_polyline {
    Marks(const string& m) :Marked_polyline(m)
    {
        set_color(Color(Color::invisible));
    }
};

//------------------------------------------------------------------------------

struct Mark : Marks {
    Mark(Point xy, char c) : Marks(string(1,c))
    {
        add(xy);
    }
};

//------------------------------------------------------------------------------

struct Suffix {
    enum Encoding { none, jpg, gif  };
};

Suffix::Encoding get_encoding(const string& s);

//------------------------------------------------------------------------------

struct Image : Shape {
    Image(Point xy, string file_name, Suffix::Encoding e = Suffix::none);
    ~Image() { delete p; }
    void draw_lines() const;
    void set_mask(Point xy, int ww, int hh) { w=ww; h=hh; cx=xy.x; cy=xy.y; }
private:
    int w,h;  // define "masking box" within image relative to position (cx,cy)
    int cx,cy;
    Fl_Image* p;
    Text fn;
};

//------------------------------------------------------------------------------

struct Bad_image : Fl_Image {
    Bad_image(int h, int w) : Fl_Image(h,w,0) { }
    void draw(int x,int y, int, int, int, int) { draw_empty(x,y); }
};

//------------------------------------------------------------------------------

struct Smiley : Circle {

    Smiley(Point p, int rr);

    void draw_lines() const;

    Point center() const { return Point(point(0).x+r, point(0).y+r); }

private:
    int r;
};

//------------------------------------------------------------------------------

struct Frowney : Circle {

    Frowney (Point p, int rr);

    void draw_lines() const;

    Point center() const { return Point(point(0).x+r, point(0).y+r); }

private:
    int r;
};

//-----------------------------------------------------------------------

class Octagon : public Shape {
public:
        Octagon(Point xy, int len)
        {
            add(xy);
            add(Point(xy.x + len, xy.y));
            for(size_t i = 0; i <= 360; i+=45){
                add(Point(xy.x + len*cos(degToRad(i)),
                          xy.y + len*sin(degToRad(i))));
            }
        }

        void draw_lines() const
        {
            for(size_t i = 1; i < number_of_points() - 1; ++i){
                fl_line(point(i).x, point(i).y,
                        point(i+1).x, point(i+1).y);
            }
        }
        double degToRad(int angle)
        {
           return angle * (acos(-1)/180);
        }
};

//------------------------------------------------------------------------------

class Group {
public:
    enum objType{Line, Rectangle, Open_polyline,
                 Closed_polyline, Polygon, Lines,
                 Text, Axis, Circle, Ellipse, Arc,
                 Marked_polyline, Marks, Mark, Suffix,
                 Image, Bad_image, Smiley, Frowney, Octagon};


    void add(Shape* obj){ contObj.push_back(obj);}
    Shape& get(int i) { return contObj[i];}
    private:
    Vector_ref<Shape> contObj;
    std::vector<objType> contTypes;
    std::vector<bool> attachState;
    bool init = 0;
};

class BinaryTree : public Shape {
public:
        BinaryTree(Point p, int levels)
        : level(levels)
        {
            switch(levels)
            {
            case 3: case 2:
                add(Point(p.x, p.y + 29)); // 0
                add(turnPoint(point(number_of_points() -1), // 1
                              Point(p.x, p.y + 80), 135));
                add(turnPoint(point(number_of_points() -2), // 2
                              Point(p.x, p.y + 80), -135));
                if(levels == 3){
                    add(Point(point(number_of_points() - 2).x, //3
                        point(number_of_points() - 2).y + 30));
                    add(Point(point(number_of_points() - 2).x, //4
                        point(number_of_points() - 2).y + 30));
                    add(turnPoint(point(number_of_points() -2), //5
                                  Point(point(number_of_points() - 2).x,
                                        point(number_of_points() - 2).y + 50), 135));
                    add(turnPoint(point(number_of_points() -3), // 6
                                  Point(point(number_of_points() - 3).x,
                                        point(number_of_points() - 3).y + 50), -135));
                    add(turnPoint(point(number_of_points() -3), //7
                                  Point(point(number_of_points() - 3).x,
                                        point(number_of_points() - 3).y + 50), 135));
                    add(turnPoint(point(number_of_points() -4),
                                  Point(point(number_of_points() - 4).x,
                                        point(number_of_points() - 4).y + 50), -135));
                }

            case 1:
                add(Point(p.x, p.y + 15));
            }
        }
        void draw_lines() const
        {

            switch(level)
            {
            case 1:
                fl_arc(point(0).x - 15, point(0).y - 15, 30, 30, 0, 360);
                break;
            case 2:
                fl_line(point(0).x, point(0).y, point(1).x, point(1).y);
                fl_line(point(0).x, point(0).y, point(2).x, point(2).y);
                fl_arc(point(1).x - 15, point(1).y, 30, 30, 0, 360);
                fl_arc(point(2).x - 15, point(2).y, 30, 30, 0, 360);
                fl_arc(point(3).x - 15, point(3).y - 15, 30, 30, 0, 360);
                break;
            case 3:
                fl_line(point(0).x, point(0).y, point(1).x, point(1).y);
                fl_line(point(0).x, point(0).y, point(2).x, point(2).y);
                fl_arc(point(1).x - 15, point(1).y, 30, 30, 0, 360);
                fl_arc(point(2).x - 15, point(2).y, 30, 30, 0, 360);
                fl_line(point(3).x, point(3).y, point(5).x, point(5).y);
                fl_line(point(3).x, point(3).y, point(6).x, point(6).y);
                fl_line(point(4).x, point(4).y, point(7).x, point(7).y);
                fl_line(point(4).x, point(4).y, point(8).x, point(8).y);
                fl_arc(point(5).x - 15, point(5).y, 30, 30, 0, 360);
                fl_arc(point(6).x - 15, point(6).y, 30, 30, 0, 360);
                fl_arc(point(7).x - 15, point(7).y, 30, 30, 0, 360);
                fl_arc(point(8).x - 15, point(8).y, 30, 30, 0, 360);
                fl_arc(point(9).x - 15, point(9).y - 15, 30, 30, 0, 360);
            }
        }
private:
    int level;

Point turnPoint(const Point& axis, const Point& rotPoint, int angle)
{
    double sinA = sin(angle * 180/atan(1) * 4),
           cosA = cos(angle * 180/atan(1) * 4);

    return Point(axis.x - axis.x*cosA + axis.y * sinA +
                 rotPoint.x * cosA - rotPoint.y * sinA,
                 axis.y - axis.x*sinA - axis.y * cosA +
                 rotPoint.x * sinA + rotPoint.y * cosA);
}

};
} // of namespace Graph_lib

#endif

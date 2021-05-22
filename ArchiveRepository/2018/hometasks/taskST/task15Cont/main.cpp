#include <iostream>
#include "FLTKGRAPHICS/Window.h"
#include "FLTKGRAPHICS/Graph.h"
#include "FLTKGRAPHICS/std_lib_facilities.h"
#include "FLTKGRAPHICS/Simple_window.h"
#include "Gystorgamm.h"


int main()
{
    using namespace Graph_lib;
    Simple_window win(Point(400,400), 800,600, "MainWindow");
    Gystogramm test(Point(300,500), 400,400, "Nametest", "Valuetest");
    win.attach(test);

    win.wait_for_button();



    return 0;
}















double one(double x) { return 1;}
double slope(double x) {return x/2;}
double sqare(double x) {return x * x;}
double sloping_cos(double x) {return std::cos(x) + x/2;}
double sinPlusCos(double x) { return std::cos(x) + std::sin(x);}
double sinMulSin(double x)
{
    double arg = std::sin(x);
    return  arg * arg;
}
double cosMulCos(double x)
{
    double arg = std::cos(x);
    return  arg * arg;
}

double Leibnizs_series(double precision)
{
    if(precision < 1) error("precision lower than one");

    double summ = 0;

    for(size_t n = 0; n < precision; ++n){
            summ += std::pow(-1, n)/(2*n + 1);
    }
    return summ;
}
void task15_1()
{
    using namespace Graph_lib;
    Simple_window mainWindow(Point(600,300), 600, 600, "Function graphics");

    const int xmax = 600;
    const int ymax = 600;
    const int xlength = 400;
    const int ylength = 400;
    const int xoffset = 100;
    const int yoffset = 100;
    const int xscale = 20;
    const int yscale = 20;
    const Point center(300,300);

    Axis x(Axis::x,Point(xoffset, ymax/2), xlength, xlength/xscale, "x axis");
    Axis y(Axis::y,Point(xmax/2, ymax - yoffset), ylength, ylength/yscale, "y axis");

    x.set_color(Color::red);
    y.set_color(Color::red);
    x.label.set_color(Color::black);
    x.label.move(-xlength/5, -20);
    y.label.set_color(Color::black);

    mainWindow.attach(x);
    mainWindow.attach(y);

    const int r_min = 1;
    const int r_max = 11;


    size_t n = 0;
    cout << "Enter the precision value: ";
    cin >> n;
    if(!cin) error("Bad value!");
    Func leibnizSeries(Leibnizs_series, r_min, n, center, xlength, xscale, yscale);
    mainWindow.attach(leibnizSeries);

    for(size_t i = 2; i <= n; ++i)
    {
        ostringstream ss;
        ss << "precision Pi/4. n =" << i;
        mainWindow.set_label(ss.str().c_str());
        leibnizSeries.changeR1R2(r_min, i);
        mainWindow.wait_for_button();
    }




    // functions task2_4

    /*Func f1(std::sin, r_min, r_max, center, xlength, xscale, yscale);
    mainWindow.attach(f1);
    Func f2(std::cos, r_min, r_max, center, xlength, xscale, yscale);
    mainWindow.attach(f2);
    Func f3(sinPlusCos, r_min, r_max, center, xlength, xscale, yscale);
    mainWindow.attach(f3);
    Func f4(sinMulSin, r_min, r_max, center, xlength, xscale, yscale);
    mainWindow.attach(f4);
    Func f5(cosMulCos, r_min, r_max, center, xlength, xscale, yscale);
    mainWindow.attach(f5);*/

    //functions task1_1

    /*Function f1(one, r_min, r_max, center, xlength, xscale, yscale);
    mainWindow.attach(f1);
    Function f2(slope, r_min, r_max, center, xlength, xscale, yscale);
    mainWindow.attach(f2);
    Text f2Text(Point(xoffset - 20, ymax - (yoffset + ylength/4)), "x/2");
    mainWindow.attach(f2Text);

    Function f3(sqare, r_min, r_max, center, xlength, xscale, yscale);
    mainWindow.attach(f3);

    Function f4(std::cos, r_min, r_max, center, xlength, xscale, yscale);
    f4.set_color(Color::blue);
    mainWindow.attach(f4);

    Function f5(sloping_cos, r_min, r_max, center, xlength, xscale, yscale);
    mainWindow.attach(f5);*/

    gui_main();
}

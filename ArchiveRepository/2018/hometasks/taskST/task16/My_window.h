#ifndef MY_WINDOW_H
#define MY_WINDOW_H
#include <cstdlib>
#include <ctime>
#include "FLTKGRAPHICS/GUI.h"

using namespace Graph_lib;

class My_window : public Graph_lib::Window
{
public:
    My_window(Point xy, int w, int h, const string& title );


protected:
    Button quit_button;

    static void cb_quit(Address,Address);
    void quit();

    Button next_button;     // the "next" button

    static void cb_next(Address, Address); // callback for next_button
    void next();


    Image img;

    Button img_button;

    static void cb_imgbut(Address, Address);
    void img_press();





};

#endif // MY_WINDOW_H

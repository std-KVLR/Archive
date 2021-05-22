#ifndef LINES_WINDOW_H
#define LINES_WINDOW_H

#include "FLTKGRAPHICS/GUI.h"

using namespace Graph_lib;

class Lines_window : public Graph_lib::Window {

public:
    explicit Lines_window(Point xy, int w, int h, const string& title);

private:
    Open_polyline lines;
    Button next_button;
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button menu_button;
    Menu linestyle_menu;
    Button lsmenu_button;

    void changels(Line_style ls) {lines.set_style(ls);}
    void hide_ls_menu() {linestyle_menu.hide(); lsmenu_button.show();}

    void solid_pressed() {changels(Line_style::solid); redraw(); hide_ls_menu();}
    void dash_pressed() {changels(Line_style::dash); redraw(); hide_ls_menu();}
    void dot_pressed() {changels(Line_style::dot); redraw(); hide_ls_menu();}
    void dashdot_pressed() {changels(Line_style::dashdot); redraw(); hide_ls_menu();}
    void dashdotdot_pressed() {changels(Line_style::dashdotdot); redraw(); hide_ls_menu();}
    void lsmenu_pressed() {lsmenu_button.hide();linestyle_menu.show();}

    static void cb_solid(Address, Address);
    static void cb_dash(Address, Address);
    static void cb_dot(Address, Address);
    static void cb_dashdot(Address, Address);
    static void cb_dashdotdot(Address, Address);
    static void cb_lsmenu(Address, Address);


    void change(Color c) { lines.set_color(c);}
    void hide_menu() {color_menu.hide(); menu_button.show();}

    void red_pressed() {change(Color::red); hide_menu();}
    void blue_pressed() {change(Color::blue);hide_menu();}
    void black_pressed() {change(Color::black);hide_menu();}
    void menu_pressed() {menu_button.hide();color_menu.show();}

    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    static void cb_menu(Address, Address);

    void next();
    static void cb_next(Address, Address);

    void quit();
    static void cb_quit(Address, Address);

};


#endif // LINES_WINDOW_H

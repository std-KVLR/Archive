#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H


#include "My_window.h"


class Chess_window : public My_window
{
public:



    Chess_window(Point xy, int w, int h, const string& title);
    void change_gr_clr(Vector_ref<Shape>& cont, Color c);

private:
    Vector_ref<Shape> fst;
    Vector_ref<Shape> scnd;

    bool clrfl = 0;

    Button next_button;

    void action_change();
    void chess_board(int, int, int);

     static void cb_next(Address, Address); // callback for next_button
     void next();

};
#endif // CHESS_WINDOW_H

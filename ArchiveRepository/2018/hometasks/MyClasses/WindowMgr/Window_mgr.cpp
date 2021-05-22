#include "Window_mgr.h"


void Window_mgr::clear(Window_mgr::ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}
void Window_mgr::show (Window_mgr::ScreenIndex i)
{
    screens[i].display(std::cout);
}
void Window_mgr::add(const Screen &data)
{
    screens.push_back(data);
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() -1;
}

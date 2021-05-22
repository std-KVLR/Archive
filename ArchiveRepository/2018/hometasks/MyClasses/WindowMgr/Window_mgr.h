#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>

class Screen;
class Window_mgr
{
private:
    std::vector<Screen> screens;
public:
    void add(const Screen&);
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    void show (ScreenIndex);
    ScreenIndex addScreen(const Screen&);
};
#include "Screen.h"
#endif // WINDOW_MGR_H


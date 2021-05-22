#ifndef GYSTOGRAMM_H
#define GYSTOGRAMM_H

#include "../FLTKGRAPHICS/Graph.h"

namespace Graph_lib
{

struct GystogrammColumn {
    std::string name;
    double value = 0;

    GystogrammColumn() = default;
    GystogrammColumn(const std::string& nameArg, double valueArg)
                    :name(nameArg), value(valueArg) {}

};

class Gystogramm : public Shape {
    public:
        Gystogramm(Point xy, int width, int height,
                   const std::string& objName,
                   const std::string& objValue)
        :x(Axis::x, xy, width, 0, objName),
         y(Axis::y, xy, height, 0, objValue)
        {
            x.label.move(xy.x + width - width/3 + 10, -15); // Корректировка положения метки
        }

        void draw_lines() const
        {
            x.draw_lines();
            y.draw_lines();
        }

    private:
        Axis x;
        Axis y;
        std::vector<GystogrammColumn> data;
        Vector_ref<Rectangle> dataColumns;
};

}

#endif // GYSTOGRAMM_H

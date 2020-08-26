#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsRectItem>


class Rectangle:public QGraphicsRectItem
{
private:
    float X, Y, Width, Height;
public:
    Rectangle(float x, float y, float w, float h);
    void show();
};

#endif // RECTANGLE_H

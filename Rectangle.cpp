#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, float w, float h)
{
    X = x;
    Y = y;
    Width = x + w;
    Height = y + h;
}

void Rectangle::show(){
    setRect(X, Y, Width, Height);
};



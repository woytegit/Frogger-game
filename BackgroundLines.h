#ifndef BACKG_H
#define BACKG_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class BackgroundLines :public QGraphicsPixmapItem
{
public:
    BackgroundLines(int line=0, int typeBG=0);
};

#endif // BACKG_H

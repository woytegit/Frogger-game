#ifndef MOBJECT_H
#define MOBJECT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class MObject :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    MObject(int line=0, float speed=0, int offset=0, int h=32);
public slots:
    void move();
    float speed_value();

private:
    float S=0, L=0, grid=0;
};

#endif // MOBJECT_H

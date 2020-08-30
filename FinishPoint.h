#ifndef FINISHPOINT_H
#define FINISHPOINT_H

#include <QGraphicsPixmapItem>

/** Klasa odpowiedzialna za tworzenie pola 32x32px miejsca konca gry */
class FinishPoint :public QGraphicsPixmapItem
{
public:
    /** Constructor of FinishPoint class
    * @param offset parametr mowiacy jak daleko od lewej krawedzi ekranu ma zostac umieszczona platforma konczaca poziom
    * */
    FinishPoint(int offset=0);
};

#endif // FINISHPOINT_H

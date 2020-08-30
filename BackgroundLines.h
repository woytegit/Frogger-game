#ifndef BACKG_H
#define BACKG_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

/** Klasa odpowiedzialna za tworzenie pojedynczej lini tla gry */
class BackgroundLines :public QGraphicsPixmapItem
{
public:
    /** Constructor of BackgroundLines class
    * @param line parametr w ktorej lini ma zostac dodane tlo
    * @param typeBG parametr wyboru typu tla
    * */
    BackgroundLines(int line=0, int typeBG=0);
};

#endif // BACKG_H

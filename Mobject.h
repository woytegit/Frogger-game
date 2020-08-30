#ifndef MOBJECT_H
#define MOBJECT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

/** Klasa odpowiedzialna za wszystkie samodzielnie poruszajace sie obiekty */
class MObject :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /** Constructor of MObject class
    * @param line parametr w ktorej lini ma zostac dodany obiekt
    * @param speed parametr predkosci
    * @param offset parametr przesuniecia miejsca startowego w poziomie
    * @param h parametr wysokosci kratki
    * */
    MObject(int line=0, float speed=0, int offset=0, int h=32);
public slots:
    void move();
    float speed_value();
private:
    float S=0, L=0, grid=0;
};

#endif // MOBJECT_H

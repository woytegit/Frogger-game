#ifndef LOG_H
#define LOG_H

#include "Mobject.h"

/** Klasa odpowiedzialna za wszystkie obiekty polozone na wodzie */
class OnWater :public MObject
{
public:
    /** Constructor of OnWater class
    * @param line parametr w ktorej lini ma zostac dodany obiekt
    * @param speed parametr predkosci
    * @param offset parametr przesuniecia miejsca startowego w poziomie
    * @param typeO parametr wyboru typu pbiektu/wielkosci
    * */
    OnWater(int line=0, float speed=0, int offset=0, int typeO=0);
};

#endif // LOG_H

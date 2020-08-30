#ifndef CAR_H
#define CAR_H

#include "Mobject.h"

/** Klasa odpowiedzialna za wszystkie obiekty polozone na jezdni */
class Vehicle :public MObject
{
public:
    /** Constructor of Vehicle class
    * @param line parametr w ktorej lini ma zostac dodany obiekt
    * @param speed parametr predkosci
    * @param offset parametr przesuniecia miejsca startowego w poziomie
    * @param typeOfVehicle parametr wyboru typu pojazdu
    * */
    Vehicle(int line=0, float speed=0, int offset=0, int typeOfVehicle=1);
};

#endif // CAR_H

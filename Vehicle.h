#ifndef CAR_H
#define CAR_H

#include "Mobject.h"

class Vehicle :public MObject
{
public:
    Vehicle(int line=0, float speed=0, int offset=0, int typeOfVehicle=1);
};

#endif // CAR_H

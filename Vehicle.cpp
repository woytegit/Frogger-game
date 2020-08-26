#include "Vehicle.h"

Vehicle::Vehicle(int line, float speed, int offset, int typeOfVehicle):
    MObject(line, speed, offset){

    if (typeOfVehicle==1){
        setPixmap(QPixmap(":/Images/Car_Blue.png"));
    }else if (typeOfVehicle==2){
        setPixmap(QPixmap(":/Images/Car_Blue2.png"));
    }else if (typeOfVehicle==3){
        setPixmap(QPixmap(":/Images/Car_Green2.png"));
    }else if (typeOfVehicle==4){
        setPixmap(QPixmap(":/Images/Car_Orange.png"));
    }else if (typeOfVehicle==5){
        setPixmap(QPixmap(":/Images/Car_Yellow.png"));
    }else if (typeOfVehicle==6){
        setPixmap(QPixmap(":/Images/Truck.png"));
    }

    if(speed<0){
        setTransformOriginPoint(32,16);
        setRotation(180);
    }

}

#include "Mobject.h"
#include <QTimer>

MObject::MObject(int line, float speed, int offset, int h)
{
    S=speed;
    L=line;
    grid=h;
    setPos(offset,grid*line);
    //conect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void MObject::move(){
    // move object
    setX(x()+S);
    if(S>=0 && x()>scene()->width()){
        setX(-200);
    }else if(S<0 && x()<-200)
        setX(scene()->width()+200);
}

float MObject::speed_value()
{
    return S;
}

#include "FinishPoint.h"


FinishPoint::FinishPoint(int offset)
{
    setPixmap(QPixmap(":/Images/finish_point.png"));
    setPos(offset,0);
}

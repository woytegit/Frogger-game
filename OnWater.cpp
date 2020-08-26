#include "OnWater.h"

OnWater::OnWater(int line, float speed, int offset, int typeO ):
    MObject(line, speed, offset){
    if(typeO==1){
        setPixmap(QPixmap(":/Images/Log_m.png"));
    }else if(typeO==2){
        setPixmap(QPixmap(":/Images/Log_l.png"));
    }else{
        setPixmap(QPixmap(":/Images/leaf.png"));
    }

}


#include "BackgroundLines.h"

BackgroundLines::BackgroundLines(int line, int typeBG)
{
    if(typeBG == 0){
        setPixmap(QPixmap(":/Images/grass_long.png"));
    }else if (typeBG == 1){
        setPixmap(QPixmap(":/Images/road_long.png"));
    }else if (typeBG == 2){
        setPixmap(QPixmap(":/Images/water_long.png"));
    }else if (typeBG == 3){
        setPixmap(QPixmap(":/Images/waterfall_long.png"));
    }

    setPos(0,32*line);
}

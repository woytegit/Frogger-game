#include "Scene.h"
#include <QTime>
#include <QDebug>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{

}

void Scene::addFrog()
{
    Frog *frog = new Frog();
    addItem(frog);
    frog->setFlag(QGraphicsItem::ItemIsFocusable);
    frog->setFocus();
    frog->Reset();
}

void Scene::addBackground()
{
    QList<BackgroundLines*> BGList;
    for (int i=0; i<=10; i++){
        if(i==5 or i==10){                              /*Linia 5 i 10*/
            BGList.push_back(new BackgroundLines(i,0)); /*grass*/
        }else if(i>=6 and i<=9){                        /*Linia 6-9*/
            BGList.push_back(new BackgroundLines(i,1)); /*road*/
        }else if(i>=1 and i<=4){                        /*Linia 1-4*/
            BGList.push_back(new BackgroundLines(i,2)); /*water*/
        }else{                                          /*Linia 0*/
            BGList.push_back(new BackgroundLines(i,3)); /*waterfall*/
        }
    }

    for (QList<BackgroundLines*>::const_iterator iter = BGList.begin(),
         end = BGList.end();
         iter != end;
         ++iter)
    {
        addItem(*iter);
    }
}

void Scene::addCars()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    int znak;

    QVector<int> speed;
    for(int i=0; i<4; i++){
        if(((rand() % (2)))==0){
            znak=-1;
        }else{
            znak=1;
        }
        speed.append(znak*((rand() % (4)*2+7)));
    }

    QList<Vehicle*> carList;
    carList.push_back(new Vehicle(9,speed[0],0,6));
    carList.push_back(new Vehicle(9,speed[0],64*4,1));
    carList.push_back(new Vehicle(8,speed[1],0,4));
    carList.push_back(new Vehicle(8,speed[1],64*3,1));
    carList.push_back(new Vehicle(7,speed[2],0,5));
    carList.push_back(new Vehicle(7,speed[2],192,2));
    carList.push_back(new Vehicle(7,speed[2],500,6));
    carList.push_back(new Vehicle(6,speed[3],-64,6));
    carList.push_back(new Vehicle(6,speed[3],-64,6));
    carList.push_back(new Vehicle(6,speed[3],180,2));
    carList.push_back(new Vehicle(6,speed[3],404,3));

    for (QList<Vehicle*>::const_iterator iter = carList.begin(),
         end = carList.end();
         iter != end;
         ++iter)
    {
        addItem(*iter);
    }
}

void Scene::addLogs()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QVector<int> speed;
    for(int i=0; i<3; i++){
        speed.append(2*((rand() % (4)+2)));
    }

    QList<OnWater*> onWaterList;
    onWaterList.push_back(new OnWater(4,speed[0],64,1));            /*Log*/
    onWaterList.push_back(new OnWater(4,speed[0],64*3,1));          /*Log*/
    onWaterList.push_back(new OnWater(4,speed[0],64*7,2));          /*Log*/
    onWaterList.push_back(new OnWater(3,-speed[1],64,2));           /*Log*/
    onWaterList.push_back(new OnWater(3,-speed[1],64*4.5,1));       /*Log*/
    onWaterList.push_back(new OnWater(1,speed[2],0,1));             /*Log*/
    onWaterList.push_back(new OnWater(1,speed[2],64*2,1));          /*Log*/
    onWaterList.push_back(new OnWater(1,speed[2],64*6,2));          /*Log*/
    onWaterList.push_back(new OnWater(2,0,32));                     /*Leaf*/
    onWaterList.push_back(new OnWater(2,0,32*((rand() % (5)) + 3)));/*Leaf*/
    onWaterList.push_back(new OnWater(2,0,32*8));                   /*Leaf*/

    for (QList<OnWater*>::const_iterator iter = onWaterList.begin(),
         end = onWaterList.end();
         iter != end;
         ++iter)
    {
        addItem(*iter);
    }

}

void Scene::addFinishPoint()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    FinishPoint *FPoint = new FinishPoint(32*((rand() % (6)) + 3));
    addItem(FPoint);
}

void Scene::startGame()
{
    Scene::addBackground();
    Scene::addCars();
    Scene::addLogs();
    Scene::addFinishPoint();
}

void Scene::showGameOverGraphics()
{
    gameOverPix = new QGraphicsPixmapItem(QPixmap(":/Images/finish_point.png"));
    addItem(gameOverPix);
    gameOverPix->setPos(0,0);

}

void Scene::hideGameOverGraphics()
{
    if(gameOverPix){
        removeItem(gameOverPix);
        delete gameOverPix;
        gameOverPix = nullptr;
    }
}

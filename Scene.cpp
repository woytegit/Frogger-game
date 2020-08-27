#include "Scene.h"

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
    BackgroundLines *grass1 = new BackgroundLines(10,0);
    BackgroundLines *road1 = new BackgroundLines(9,1);
    BackgroundLines *road2 = new BackgroundLines(8,1);
    BackgroundLines *road3 = new BackgroundLines(7,1);
    BackgroundLines *road4 = new BackgroundLines(6,1);
    BackgroundLines *grass2 = new BackgroundLines(5,0);
    BackgroundLines *water1 = new BackgroundLines(4,2);
    BackgroundLines *water2 = new BackgroundLines(3,2);
    BackgroundLines *water3 = new BackgroundLines(2,2);
    BackgroundLines *water4 = new BackgroundLines(1,2);
    BackgroundLines *waterfall = new BackgroundLines(0,3);

    addItem(grass1);
    addItem(grass2);
    addItem(road1);
    addItem(road2);
    addItem(road3);
    addItem(road4);
    addItem(water1);
    addItem(water2);
    addItem(water3);
    addItem(water4);
    addItem(waterfall);
}

void Scene::addCars()
{
    Vehicle *car1 = new Vehicle(9,-11,0,6);
    Vehicle *car2 = new Vehicle(9,-11,64*4,1);
    Vehicle *car3 = new Vehicle(8,13,0,4);
    Vehicle *car4 = new Vehicle(8,13,64*3,1);
    Vehicle *car5 = new Vehicle(7,-8,0,5);
    Vehicle *car6 = new Vehicle(7,-8,192,2);
    Vehicle *car7 = new Vehicle(7,-8,500,6);
    Vehicle *car8 = new Vehicle(6,6,-64,6);
    Vehicle *car9 = new Vehicle(6,6,180,2);
    Vehicle *car10 = new Vehicle(6,6,404,3);

    addItem(car1);
    addItem(car2);
    addItem(car3);
    addItem(car4);
    addItem(car5);
    addItem(car6);
    addItem(car7);
    addItem(car8);
    addItem(car9);
    addItem(car10);
}

void Scene::addLogs()
{
    OnWater *log1 = new OnWater(4,9,64,1);
    OnWater *log2 = new OnWater(4,9,64*3,1);
    OnWater *log3 = new OnWater(4,9,64*7,2);
    OnWater *log4 = new OnWater(3,-11,64,2);
    OnWater *log5 = new OnWater(3,-11,64*4.5,1);
    OnWater *leaf1 = new OnWater(2,0,32*5);
    OnWater *leaf2 = new OnWater(2,0,32*6);
    OnWater *leaf3 = new OnWater(2,0,32);
    OnWater *log6 = new OnWater(1,6,0,1);
    OnWater *log7 = new OnWater(1,6,64*2,1);
    OnWater *log8 = new OnWater(1,6,64*6,2);

    addItem(log1);
    addItem(log2);
    addItem(log3);
    addItem(log4);
    addItem(log5);
    addItem(log6);
    addItem(log7);
    addItem(log8);
    addItem(leaf1);
    addItem(leaf2);
    addItem(leaf3);

}

void Scene::addFinishPoint()
{
    FinishPoint *FPoint = new FinishPoint(96);
    addItem(FPoint);
}

void Scene::startGame()
{
    Scene::addBackground();
    Scene::addCars();
    Scene::addLogs();
    Scene::addFinishPoint();
    //    Scene::addFrog();
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

#include "Game.h"
#include "ui_Game.h"

#include <QTimer>
#include <QDebug>

Game::Game(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->graphicsView->setFixedWidth(32*11+2);
    ui->graphicsView->setFixedHeight(32*11+2);
    ui->verticalLayout->setMargin(0);
    Scene *scene = new Scene(this);
    scene->setSceneRect(0,0,32*11,32*11);
    ui->graphicsView->setScene(scene);



    // add the item to the scene
    // background
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

    scene->addItem(grass1);
    scene->addItem(grass2);
    scene->addItem(road1);
    scene->addItem(road2);
    scene->addItem(road3);
    scene->addItem(road4);
    scene->addItem(water1);
    scene->addItem(water2);
    scene->addItem(water3);
    scene->addItem(water4);
    scene->addItem(waterfall);


    // foreground
    FinishPoint *FPoint = new FinishPoint(96);
    frog = new Frog;
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

    scene->addItem(FPoint);
    scene->addItem(leaf1);
    scene->addItem(leaf2);
    scene->addItem(leaf3);
    scene->addItem(car1);
    scene->addItem(car2);
    scene->addItem(car3);
    scene->addItem(car4);
    scene->addItem(car5);
    scene->addItem(car6);
    scene->addItem(car7);
    scene->addItem(car8);
    scene->addItem(car9);
    scene->addItem(car10);
    scene->addItem(log1);
    scene->addItem(log2);
    scene->addItem(log3);
    scene->addItem(log4);
    scene->addItem(log5);
    scene->addItem(log6);
    scene->addItem(log7);
    scene->addItem(log8);
    scene->addItem(frog);

    frog->setFlag(QGraphicsItem::ItemIsFocusable);
    frog->setFocus();
    frog->Reset();

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(500);

}

Game::~Game()
{
    delete ui;
}

void Game::update()
{
    ui->lcdNumber->display(frog->getHighScore());
    ui->lcdNumber_2->display(frog->getScore());
}


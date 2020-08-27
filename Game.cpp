#include "Game.h"
#include "ui_Game.h"

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

    scene->startGame();


//    scene->addBackground();
//    scene->addCars();
//    scene->addLogs();
//    scene->addFinishPoint();
//    scene->addFrog();

    frog = new Frog;
    scene->addItem(frog);
    frog->setFlag(QGraphicsItem::ItemIsFocusable);
    frog->setFocus();
    frog->Reset();

    rect = new QGraphicsRectItem();
    rect->setRect(0,0,scene->width()-1,scene->height()-1);
    rect->setBrush(QBrush(Qt::gray));
    scene->addItem(rect);

//    QTimer * timer = new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
//    timer->start(500);

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


void Game::on_startGameButton_clicked()
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(500);
    rect->hide();
}

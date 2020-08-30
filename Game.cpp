#include "Game.h"
#include "ui_Game.h"

Game::Game(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget),tim(0)
{
    ui->setupUi(this);
    ui->graphicsView->setFixedWidth(32*11+2);
    ui->graphicsView->setFixedHeight(32*11+2);
    ui->verticalLayout->setMargin(0);
    Scene *scene = new Scene(this);
    scene->setSceneRect(0,0,32*11,32*11);
    ui->graphicsView->setScene(scene);

    scene->startGame();

    frog = new Frog;
    scene->addItem(frog);
    frog->setFlag(QGraphicsItem::ItemIsFocusable);
    frog->setFocus();
    frog->Reset();

    startPix = new QGraphicsPixmapItem(QPixmap(":/Images/startSceen.png"));
    scene->addItem(startPix);
    startPix->show();

    gameOverPix = new QGraphicsPixmapItem(QPixmap(":/Images/gameOverScreen.png"));
    scene->addItem(gameOverPix);
    gameOverPix->hide();

}

Game::~Game()
{
    delete ui;
}

void Game::update()
{
    if(frog->IsAlive==false and tim == 1){
        tim=2;
        showGameOverGraphics();
//        qDebug()<<"Collision";
    }
    if(frog->IsAlive){
        ui->lcdNumber->display(frog->getHighScore());
        ui->lcdNumber_2->display(frog->getScore());
    }
}

void Game::on_startGameButton_clicked()
{
    frog->Reset();
    startPix->hide();
    gameOverPix->hide();
    if(tim==0)
    {
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(update()));
        timer->start(50);
        frog->resetHighscore();
    }

    tim=1;
}

void Game::showGameOverGraphics()
{
    gameOverPix->show();
}

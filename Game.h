#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>

#include "Scene.h"
#include "Frog.h"
#include "Vehicle.h"
#include "OnWater.h"
#include "BackgroundLines.h"
#include "FinishPoint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

/** Klasa odpowiedzialna za wyswietlanie gry */
class Game : public QWidget
{
    Q_OBJECT
public:
    /** Constructor of Game class
    * @param *parent
    * */
    Game(QWidget *parent = nullptr);
    ~Game();
public slots:
    void update();

private slots:
    void on_startGameButton_clicked();

private:
    void showGameOverGraphics();
    /// Wskaznik do Ui widget
    Ui::Widget *ui;
    /// Wskaznik do sceny
    Scene *scene;
    /// Wskaznik do zaby/bohatera
    Frog *frog;
    /// Wskaznik do ekranu powitalnego
    QGraphicsPixmapItem *startPix;
    /// Wskaznik do ekranu porazki
    QGraphicsPixmapItem *gameOverPix;
    int tim;

};
#endif // WIDGET_H

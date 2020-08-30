#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QPointF>

#include "Frog.h"
#include "Vehicle.h"
#include "OnWater.h"
#include "BackgroundLines.h"
#include "FinishPoint.h"

/** Klasa odpowiedzialna za wyglad calej gry */
class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    /// Dodawanie zaby na ekran
    void addFrog();
    /// Dodawanie tla gry
    void addBackground();
    /// Dodawanie pojazdow
    void addCars();
    /// Dodawanie klod i lisci
    void addLogs();
    /// Dodawanie punktow konczacych
    void addFinishPoint();
    /// wywolanie wszystkich dodawan na raz
    void startGame();
    /// Wyswieltanie ekranu konca gry
    void showGameOverGraphics();
    /// Ukrywanie ekranu konca gry
    void hideGameOverGraphics();
    /// Wskaznik do grafiki konca gry
    QGraphicsPixmapItem * gameOverPix;

};

#endif // SCENE_H

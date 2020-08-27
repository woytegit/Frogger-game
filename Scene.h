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

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

    void addFrog();
    void addBackground();
    void addCars();
    void addLogs();
    void addFinishPoint();
    void startGame();
    void showGameOverGraphics();
    void hideGameOverGraphics();

    QGraphicsPixmapItem * gameOverPix;
    QGraphicsTextItem * scoreTextItem;

signals:

private:

//    Frog* frog;

};

#endif // SCENE_H

#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
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

signals:

private:

//    Frog* frog;

};

#endif // SCENE_H

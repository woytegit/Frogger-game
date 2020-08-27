#ifndef FROG_H
#define FROG_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Frog :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Frog(int w=32);
    void keyPressEvent(QKeyEvent * event);
    void Reset();
    int getScore();
    int getHighScore();
    bool IsAlive;
public slots:
    void IsFrogAlive();
private:
    int grid = 0;
    int score = 0;
    int highscore = 0;
    int line=0;
    bool frogOnLog;    
    void IsCollisionWithCar();
    void IsFrogOnLog();
    void IsFrogInWater();
    void IsFrogOnFinishPoint();

};

#endif // FROG_H

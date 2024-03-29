#include "Frog.h"
#include "Vehicle.h"
#include "OnWater.h"
#include "FinishPoint.h"

//#include "ui_widget.h"

#include <QTimer>
#include <QList>
#include <QDebug>

template <class any_data_type>
any_data_type NewHighscore(any_data_type Var1, any_data_type Var2)
{
    if(Var1<Var2){
        Var1=Var2;
    }
    return Var1;
}

Frog::Frog(int w)
{
    grid=w;
    frogOnLog=false;
    IsAlive=true;
    // draw graphics
    setPixmap(QPixmap(":/Images/Frog.png"));
    setTransformOriginPoint(15,15);
    //conect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(IsFrogAlive()));
    timer->start(50);
}

void Frog::keyPressEvent(QKeyEvent *event){
    int step = grid;
    if(event->key() == Qt::Key_Left){
        setRotation(270);
        if (pos().x()>0)
            setPos(x()-step,y());
    }
    else if(event->key() == Qt::Key_Right){
        setRotation(90);
        if (pos().x()<scene()->width()-grid)
            setPos(x()+step,y());
    }
    else if(event->key() == Qt::Key_Down){
        setRotation(180);
        if (pos().y()<scene()->height()-grid-1) {// -1 bo zaba jest wysokosci 30
            setPos(x(),y()+step);
            if (directionChanged==true){
                if (line<0){
                    line++;
                }else{
                    score++;
                }
            }else{
                line--;
            }

        }
    }
    else if(event->key() == Qt::Key_Up){
        setRotation(0);
        if (pos().y()>1) {// 1 bo zaba jest wysokosci 30
            setPos(x(),y()-step);
            if (directionChanged==false){
                if (line<0){
                    line++;
                }else{
                    score++;
                }
            }else{
                line--;
            }

        }
    }
}

void Frog::Reset()
{
    setPos(int(scene()->width()/2)-int(grid/2), int(scene()->height()-grid+1));
    if(IsAlive==false){
        score=0;
        IsAlive=true;
        directionChanged=false;
    }
}

void Frog::IsFrogAlive()
{
    IsCollisionWithCar();
    IsFrogOnLog();
    IsFrogOnFinishPoint();
    IsFrogInWater();
    IsFrogOnStartLine();

    highscore = NewHighscore(highscore,score);

}

void Frog::IsCollisionWithCar()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    foreach (QGraphicsItem * item, colliding_items){
        Vehicle * car = dynamic_cast<Vehicle*>(item);
        if(car){
            IsAlive=false;
            frogOnLog=false;      
        }
    }
}

void Frog::IsFrogOnLog()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    foreach (QGraphicsItem * item, colliding_items){
        OnWater * log = dynamic_cast<OnWater*>(item);
        if(log){
            frogOnLog=true;
            if(this->x()>=0&&this->x()<=scene()->width()-grid){
                this->setX(this->x()+log->speed_value());
                if(this->x()<0){
                    this->setX(0);
                }else if(this->x()>scene()->width()-grid){
                    this->setX(scene()->width()-grid);
                }
            }
        break;
        }
        frogOnLog = false;
    }
}

void Frog::IsFrogInWater()
{
    if(this->y()<5*grid && frogOnLog==false && this->y()>=0*grid){
        IsAlive=false;
    }
}

void Frog::IsFrogOnFinishPoint()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    foreach (QGraphicsItem * item, colliding_items){
        FinishPoint * point = dynamic_cast<FinishPoint*>(item);
        if(point){
            frogOnLog=true;
            if(directionChanged==false){
                score+=5;
            }
            directionChanged=true;
//            this->Reset();
        }
    }
}

void Frog::IsFrogOnStartLine()
{
    if(this->y()>10*grid && directionChanged==true){
        directionChanged=false;
        score+=5;
    }
}

int Frog::getScore()
{
    return score;
}

int Frog::getHighScore()
{
    return highscore;
}

void Frog::resetHighscore()
{
    highscore=0;
}







#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsRectItem>

#include "Scene.h"
#include "Frog.h"
#include "Vehicle.h"
#include "OnWater.h"
#include "BackgroundLines.h"
#include "FinishPoint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Game : public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);
    ~Game();
public slots:
    void update();

private:
    Ui::Widget *ui;
    Scene *scene;
    Frog *frog;
};
#endif // WIDGET_H

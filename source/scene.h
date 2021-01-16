#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QtMath>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene();
    ~Scene();

    void setUp();
    void updateDots(int cnt);
    void updateLines(double times);
    void clearDots();
    void clearLines();

private:
    QGraphicsEllipseItem *main_ellipse = nullptr;
    QVector<QGraphicsEllipseItem *> dots;
    QVector<QGraphicsLineItem *> lines;

    const int DOT_RAD = 3;
    const double SCALE_COEF = 1.5;
    double times_t = 1;
};

#endif // SCENE_H

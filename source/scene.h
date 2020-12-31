#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene();
    ~Scene();

    void setUp();
    void updateDots(int cnt);
    void updateLines(double times);
    void clearDots();
    void clearLines();

private:
    QGraphicsEllipseItem *el = nullptr;
    QVector<QGraphicsEllipseItem *> dots;
    QVector<QGraphicsLineItem *> lines;

    const int DOT_RAD = 3;
    int radius;
    double times_t = 1;
    int color_cnt = 1;
    int r = 100;
    int g = 0;
    int b = 0;
    QPointF center_of_el;
};

#endif // SCENE_H

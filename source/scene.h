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

private:
    QGraphicsEllipseItem *el = nullptr;
};

#endif // SCENE_H

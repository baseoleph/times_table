#ifndef MQGRAPHICSVIEW_H
#define MQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QDebug>

#include "scene.h"

class MQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    MQGraphicsView();
    ~MQGraphicsView();

    void resizeEvent(QResizeEvent *event);
    void updateSceneRect();

    Scene *mscene = nullptr;

private:

    const int SCENE_INDENT = 5;
};

#endif // MQGRAPHICSVIEW_H

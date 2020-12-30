#include "scene.h"

Scene::Scene()
{
    el = new QGraphicsEllipseItem;
    el->setPen(QPen(QBrush(QColor(Qt::darkBlue)), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    addItem(el);
}

Scene::~Scene()
{
    if (el != nullptr) delete el;
}

void Scene::setUp()
{
    double scale_coef = 1.5;
    double diameter = qMin(width(), height())/scale_coef;
    int radius = diameter / 2;

    int rect_width = width()/2 - radius;
    int rect_height = height()/2 - radius;

    el->setRect(rect_width, rect_height, radius * 2, radius * 2);
}

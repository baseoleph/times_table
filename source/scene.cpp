#include "scene.h"

Scene::Scene()
{
    el = new QGraphicsEllipseItem;
    el->setPen(QPen(QBrush(QColor(Qt::darkBlue)), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    addItem(el);
}

Scene::~Scene()
{
    clearLines();
    clearDots();
    if (el != nullptr) delete el;
}

void Scene::setUp()
{
    double scale_coef = 1.5;
    double diameter = qMin(width(), height())/scale_coef;
    radius = diameter / 2;
    QPointF center_of_el = el->rect().center();

    int rect_width = width()/2 - radius;
    int rect_height = height()/2 - radius;

    el->setRect(rect_width, rect_height, radius * 2, radius * 2);

    center_of_el = el->rect().center();
    for (int i = 0; i < dots.size(); ++i)
    {
        double x = center_of_el.x() - radius * qCos(2 * M_PI / dots.size() * i) - DOT_RAD;
        double y = center_of_el.y() - radius * qSin(2 * M_PI / dots.size() * i) - DOT_RAD;
        dots[i]->setRect(x, y, DOT_RAD * 2, DOT_RAD * 2);
    }
}

void Scene::updateDots(int cnt)
{
    clearDots();

    if (cnt != 0)
    {
        for (int i = 0; i < cnt; ++i)
        {
            dots.append(new QGraphicsEllipseItem);
            addItem(dots.last());
        }
    }
    setUp();
}

void Scene::updateLines(double times)
{
    clearLines();
    for (int i = 0; i < dots.size(); ++i)
    {
        QLineF line;
        line.setP1(dots[i]->rect().center());
        double x = center_of_el.x() - radius * qCos(2 * M_PI / dots.size() * (i * times)) - DOT_RAD;
        double y = center_of_el.y() - radius * qSin(2 * M_PI / dots.size() * (i * times)) - DOT_RAD;
        line.setP2(QPointF(x+100, y+100));
        lines.append(new QGraphicsLineItem);
        lines.last()->setLine(line);
        addItem(lines.last());
    }
}

void Scene::clearDots()
{
    foreach (auto e, dots)
    {
        delete e;
    }
    dots.clear();
}

void Scene::clearLines()
{
    foreach (auto e, lines)
    {
        delete e;
    }
    lines.clear();
}

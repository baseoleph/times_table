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
    clearLines();

    color_cnt += 1;
    color_cnt %= 3;


//    if (color_cnt == 0)
//    {
//        r += 1;
//        r %= 255;
//    }
//    else if ( color_cnt == 1)
//    {
//        g += 2;
//        g %= 255;
//    }
//    else if ( color_cnt == 2)
//    {
        b += 1;
        b %= 255;
//    }

    QPen pen_line(QColor(r, g, b));
    for (int i = 0; i < dots.size(); ++i)
    {
        double x = center_of_el.x() - radius * qCos(2 * M_PI / dots.size() * i) - DOT_RAD;
        double y = center_of_el.y() - radius * qSin(2 * M_PI / dots.size() * i) - DOT_RAD;
        dots[i]->setRect(x, y, DOT_RAD * 2, DOT_RAD * 2);

        QLineF line;
        line.setP1(QPointF(x + DOT_RAD, y + DOT_RAD));
        x = center_of_el.x() - radius * qCos(2 * M_PI / dots.size() * (i * times_t));
        y = center_of_el.y() - radius * qSin(2 * M_PI / dots.size() * (i * times_t));
        line.setP2(QPointF(x, y));
        lines.append(new QGraphicsLineItem);
        lines.last()->setLine(line);
        lines.last()->setPen(pen_line);
        addItem(lines.last());
    }
}

void Scene::updateDots(int cnt)
{
    clearDots();

    QPen dot_pen(Qt::darkCyan, 1);
    QBrush dot_brush(Qt::darkCyan);
    if (cnt != 0)
    {
        for (int i = 0; i < cnt; ++i)
        {
            dots.append(new QGraphicsEllipseItem);
            dots.last()->setPen(dot_pen);
            dots.last()->setBrush(dot_brush);
            addItem(dots.last());
        }
    }
    setUp();
}

void Scene::updateLines(double times)
{
    times_t = times;
    setUp();
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

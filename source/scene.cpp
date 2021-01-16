#include "scene.h"

Scene::Scene()
{
    main_ellipse = new QGraphicsEllipseItem;
    main_ellipse->setPen(QPen(QBrush(QColor(Qt::darkBlue)), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    addItem(main_ellipse);
}

Scene::~Scene()
{
    clearLines();
    clearDots();
    if (main_ellipse != nullptr) delete main_ellipse;
}

void Scene::setUp()
{
    const double DIAMETER = qMin(width(), height())/SCALE_COEF;
    const double RADIUS = DIAMETER / 2;

    const int RECT_WIDTH = width()/2 - RADIUS;
    const int RECT_HEIGHT = height()/2 - RADIUS;

    main_ellipse->setRect(RECT_WIDTH, RECT_HEIGHT, RADIUS * 2, RADIUS * 2);

    QPointF center_of_el = main_ellipse->rect().center();
    clearLines();

    QPen pen_line(Qt::darkRed);
    for (int i = 0; i < dots.size(); ++i)
    {
        double x = center_of_el.x() - RADIUS * qCos(2 * M_PI / dots.size() * i) - DOT_RAD;
        double y = center_of_el.y() - RADIUS * qSin(2 * M_PI / dots.size() * i) - DOT_RAD;
        dots[i]->setRect(x, y, DOT_RAD * 2, DOT_RAD * 2);

        QLineF line;
        line.setP1(QPointF(x + DOT_RAD, y + DOT_RAD));
        x = center_of_el.x() - RADIUS * qCos(2 * M_PI / dots.size() * (i * times_t));
        y = center_of_el.y() - RADIUS * qSin(2 * M_PI / dots.size() * (i * times_t));
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

// Multiplication Table
// Copyright (C) 2021 baseoleph@gmail.com

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

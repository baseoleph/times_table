// Times Table
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

#include "mqgraphicsview.h"

MQGraphicsView::MQGraphicsView()
{
    setRenderHints(QPainter::Antialiasing);
    mscene = new Scene;
    setScene(mscene);
}

MQGraphicsView::~MQGraphicsView()
{
    if (mscene != nullptr) delete mscene;
}


void MQGraphicsView::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    updateSceneRect();
}

void MQGraphicsView::updateSceneRect()
{
    QRectF rect = this->rect();
    rect.setSize(QSizeF(rect.width() - SCENE_INDENT, rect.height() - SCENE_INDENT));
    mscene->setSceneRect(rect);
    mscene->setUp();
}

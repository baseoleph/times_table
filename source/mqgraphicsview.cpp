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

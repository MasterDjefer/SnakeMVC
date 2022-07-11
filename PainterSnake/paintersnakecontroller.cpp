#include "paintersnakecontroller.h"

PainterSnakeController::PainterSnakeController(std::shared_ptr<ModelSnakeBody> model, std::shared_ptr<WidgetInfo> widgetInfo) : mModel(model), mWidgetInfo(widgetInfo)
{

}

void PainterSnakeController::draw(QPainter &painter)
{
    std::for_each(mModel->begin(), mModel->end(), [&painter, this](const QPoint& p)
    {
        painter.drawRect(p.x(), p.y(), mWidgetInfo->blockSize, mWidgetInfo->blockSize);
    });
}



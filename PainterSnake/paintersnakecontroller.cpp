#include "paintersnakecontroller.h"

PainterSnakeController::PainterSnakeController(std::shared_ptr<ModelSnakeBody> model, std::shared_ptr<ModelFood> food, std::shared_ptr<WidgetInfo> widgetInfo) :
    mWidgetInfo(widgetInfo), mModel(model), mFood(food)
{
}

void PainterSnakeController::drawSnake(QPainter &painter)
{
    std::for_each(mModel->begin(), mModel->end(), [&painter, this](const QPoint& p)
    {
        painter.drawRect(p.x(), p.y(), mWidgetInfo->blockSize, mWidgetInfo->blockSize);
    });
}

void PainterSnakeController::drawFood(QPainter &painter)
{
    painter.drawRect(mFood->x(), mFood->y(), mWidgetInfo->blockSize, mWidgetInfo->blockSize);
}



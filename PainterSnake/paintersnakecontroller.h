#ifndef PAINTERSNAKECONTROLLER_H
#define PAINTERSNAKECONTROLLER_H

#include <QPainter>
#include <memory>

#include "modelsnakebody.h"
#include "modelfood.h"
#include "widgetinfo.h"

class PainterSnakeController
{
public:
    PainterSnakeController(std::shared_ptr<ModelSnakeBody> model, std::shared_ptr<ModelFood> food, std::shared_ptr<WidgetInfo> widgetInfo);
    void drawSnake(QPainter& painter);
    void drawFood(QPainter& painter);

private:
    std::shared_ptr<WidgetInfo> mWidgetInfo;
    std::shared_ptr<ModelSnakeBody> mModel;
    std::shared_ptr<ModelFood> mFood;
};

#endif // PAINTERSNAKECONTROLLER_H

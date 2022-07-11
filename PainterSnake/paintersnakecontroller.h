#ifndef PAINTERSNAKECONTROLLER_H
#define PAINTERSNAKECONTROLLER_H

#include <QPainter>
#include <memory>

#include "modelsnakebody.h"
#include "widgetinfo.h"

class PainterSnakeController
{
public:
    PainterSnakeController(std::shared_ptr<ModelSnakeBody> model, std::shared_ptr<WidgetInfo> widgetInfo);
     void draw(QPainter& painter);

private:
    std::shared_ptr<WidgetInfo> mWidgetInfo;
    std::shared_ptr<ModelSnakeBody> mModel;
};

#endif // PAINTERSNAKECONTROLLER_H

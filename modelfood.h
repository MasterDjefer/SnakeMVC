#ifndef MODELFOOD_H
#define MODELFOOD_H

#include <QPoint>
#include <memory>
#include <ctime>
#include <cstdlib>

#include "widgetinfo.h"

class ModelFood : public QPoint
{
public:
    ModelFood(std::shared_ptr<WidgetInfo> widgetInfo);
    void generate();

private:
    std::shared_ptr<WidgetInfo> mWidgetInfo;
};

#endif // MODELFOOD_H

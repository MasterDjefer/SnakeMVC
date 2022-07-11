#include "modelfood.h"

ModelFood::ModelFood(std::shared_ptr<WidgetInfo> widgetInfo) : mWidgetInfo(widgetInfo)
{
    std::srand(std::time(nullptr));

    generate();
}

void ModelFood::generate()
{
    setX(((std::rand() % (mWidgetInfo->windowWidth - mWidgetInfo->blockSize)) / mWidgetInfo->blockSize) * mWidgetInfo->blockSize);
    setY(((std::rand() % (mWidgetInfo->windowHeight - mWidgetInfo->blockSize)) / mWidgetInfo->blockSize) * mWidgetInfo->blockSize);
}

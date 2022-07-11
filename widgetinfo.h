#ifndef WIDGETINFO_H
#define WIDGETINFO_H

struct WidgetInfo
{
    WidgetInfo(int bs, int wW, int wH);
    int blockSize;
    int windowWidth;
    int windowHeight;
};

#endif // WIDGETINFO_H

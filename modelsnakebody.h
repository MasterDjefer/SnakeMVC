#ifndef MODELSNAKEBODY_H
#define MODELSNAKEBODY_H

#include <QObject>
#include <QList>
#include <QPainter>
#include <QPoint>
#include <memory>

#include "widgetinfo.h"
#include "modelfood.h"

class ModelSnakeBody : public QObject
{
    Q_OBJECT

    enum Direction
    {
        Left = 0,
        Right,
        Up,
        Down
    };

public:
    ModelSnakeBody(std::shared_ptr<ModelFood> food, std::shared_ptr<WidgetInfo> widgetInfo);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void eat();
    QList<QPoint>::const_iterator begin() const;
    QList<QPoint>::const_iterator end() const;
    void makeMove();

private:
    void checkFood();

private:
    QList<QPoint> mBody;
    QPoint mLastBody;
    Direction mDirection;
    std::shared_ptr<WidgetInfo> mWidgetInfo;
    std::shared_ptr<ModelFood> mFood;
};

#endif // MODELSNAKEBODY_H

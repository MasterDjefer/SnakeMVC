#ifndef MODELSNAKEBODY_H
#define MODELSNAKEBODY_H

#include <QObject>
#include <QList>
#include <QPainter>
#include <QPoint>
#include <memory>

#include "widgetinfo.h"

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
    ModelSnakeBody(int startHeadX, int startHeadY, std::shared_ptr<WidgetInfo> widgetInfo);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void eat();
    QList<QPoint>::const_iterator begin() const;
    QList<QPoint>::const_iterator end() const;

public slots:
    void makeMove();

private:
    QList<QPoint> mBody;
    Direction mDirection;
    std::shared_ptr<WidgetInfo> mWidgetInfo;
};

#endif // MODELSNAKEBODY_H

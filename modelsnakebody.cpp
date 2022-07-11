#include "modelsnakebody.h"

ModelSnakeBody::ModelSnakeBody(int startHeadX, int startHeadY, std::shared_ptr<WidgetInfo> widgetInfo) : mDirection(Left), mWidgetInfo(widgetInfo)
{
    mBody.append({startHeadX, startHeadY});
}

void ModelSnakeBody::moveLeft()
{
    mDirection = Left;
}

void ModelSnakeBody::moveRight()
{
    mDirection = Right;
}

void ModelSnakeBody::moveUp()
{
    mDirection = Up;
}

void ModelSnakeBody::moveDown()
{
    mDirection = Down;
}

void ModelSnakeBody::makeMove()
{
    QPoint head = mBody.front();

    switch (mDirection)
    {
    case Left:
        head.setX(head.x() - mWidgetInfo->blockSize);
        break;
    case Right:
        head.setX(head.x() + mWidgetInfo->blockSize);
        break;
    case Up:
        head.setY(head.y() - mWidgetInfo->blockSize);
        break;
    case Down:
        head.setY(head.y() + mWidgetInfo->blockSize);
        break;
    }

    mBody.removeLast();
    mBody.prepend(head);
}

void ModelSnakeBody::eat()
{
    QPoint lastBody = mBody.back();
    makeMove();
    mBody.push_back(lastBody);
}

QList<QPoint>::const_iterator ModelSnakeBody::begin() const
{
    return mBody.cbegin();
}

QList<QPoint>::const_iterator ModelSnakeBody::end() const
{
    return mBody.cend();
}

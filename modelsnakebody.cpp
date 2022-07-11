#include "modelsnakebody.h"

ModelSnakeBody::ModelSnakeBody(std::shared_ptr<ModelFood> food, std::shared_ptr<WidgetInfo> widgetInfo) : mDirection(Left), mWidgetInfo(widgetInfo), mFood(food)
{
    mBody.append({((mWidgetInfo->windowWidth / 2) / mWidgetInfo->blockSize) * mWidgetInfo->blockSize,
                  ((mWidgetInfo->windowHeight / 2) / mWidgetInfo->blockSize) * mWidgetInfo->blockSize});

    mLastBody = mBody.front();
    mLastBody.setX(mLastBody.x() + mWidgetInfo->blockSize);
}

void ModelSnakeBody::moveLeft()
{
    if (mDirection != Right)
        mDirection = Left;
}

void ModelSnakeBody::moveRight()
{
    if (mDirection != Left)
        mDirection = Right;
}

void ModelSnakeBody::moveUp()
{
    if (mDirection != Down)
        mDirection = Up;
}

void ModelSnakeBody::moveDown()
{
    if (mDirection != Up)
        mDirection = Down;
}

void ModelSnakeBody::makeMove()
{
    QPoint head = mBody.front();

    switch (mDirection)
    {
    case Left:
        head.setX(head.x() - mWidgetInfo->blockSize);
        if (head.x() < 0)
            head.setX(mWidgetInfo->windowWidth - mWidgetInfo->blockSize);
        break;
    case Right:
        head.setX(head.x() + mWidgetInfo->blockSize);
        if (head.x() >= mWidgetInfo->windowWidth)
            head.setX(0);
        break;
    case Up:
        head.setY(head.y() - mWidgetInfo->blockSize);
        if (head.y() < 0)
            head.setY(mWidgetInfo->windowHeight - mWidgetInfo->blockSize);
        break;
    case Down:
        head.setY(head.y() + mWidgetInfo->blockSize);
        if (head.y() >= mWidgetInfo->windowHeight)
            head.setY(0);
        break;
    }

    mLastBody = mBody.back();
    mBody.removeLast();
    mBody.prepend(head);

    checkFood();
}

void ModelSnakeBody::checkFood()
{
    foreach (const QPoint& p, mBody)
    {
        if (p.x() == mFood->x() && p.y() == mFood->y())
        {
            mFood->generate();
            eat();
            return;
        }
    }
}

void ModelSnakeBody::eat()
{
    mBody.push_back(mLastBody);
}

QList<QPoint>::const_iterator ModelSnakeBody::begin() const
{
    return mBody.cbegin();
}

QList<QPoint>::const_iterator ModelSnakeBody::end() const
{
    return mBody.cend();
}

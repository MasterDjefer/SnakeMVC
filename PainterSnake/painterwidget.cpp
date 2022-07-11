#include "painterwidget.h"

PainterWidget::PainterWidget(QWidget *parent) : QWidget(parent)
{
    mWidgetInfo = std::make_shared<WidgetInfo>(20, 500, 600);
    mModelFood = std::make_unique<ModelFood>(mWidgetInfo);
    mModelSnakeBody = std::make_shared<ModelSnakeBody>(mModelFood, mWidgetInfo);
    mController = std::make_unique<PainterSnakeController>(mModelSnakeBody, mModelFood, mWidgetInfo);

    resize(mWidgetInfo->windowWidth, mWidgetInfo->windowHeight);

    connect(&mTimer, &QTimer::timeout, this, &PainterWidget::onTimerIntervalEnd);

    mTimer.setInterval(200);
    mTimer.start();
}

PainterWidget::~PainterWidget()
{
}

void PainterWidget::paintEvent(QPaintEvent *event)
{
    (void)event;

    QPainter painter(this);
    painter.setPen(Qt::black);

    painter.setBrush(Qt::red);
    mController->drawSnake(painter);

    painter.setBrush(Qt::green);
    mController->drawFood(painter);
}

void PainterWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Space:
        mModelSnakeBody->eat();
        break;
    case Qt::Key_Up:
        mModelSnakeBody->moveUp();
        break;
    case Qt::Key_Down:
        mModelSnakeBody->moveDown();
        break;
    case Qt::Key_Left:
        mModelSnakeBody->moveLeft();
        break;
    case Qt::Key_Right:
        mModelSnakeBody->moveRight();
        break;
    }
}

void PainterWidget::onTimerIntervalEnd()
{
    mModelSnakeBody->makeMove();

    update();
}


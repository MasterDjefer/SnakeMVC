#include "painterwidget.h"

PainterWidget::PainterWidget(QWidget *parent) : QWidget(parent)
{
    mWidgetInfo = std::make_shared<WidgetInfo>(20, 500, 600);
    mModel = std::make_shared<ModelSnakeBody>(400, 100, mWidgetInfo);
    mController = std::make_unique<PainterSnakeController>(mModel, mWidgetInfo);

    resize(mWidgetInfo->windowWidth, mWidgetInfo->windowHeight);

    connect(&mTimer, &QTimer::timeout, mModel.get(), &ModelSnakeBody::makeMove);

    mTimer.setInterval(500);
    mTimer.start();
}

PainterWidget::~PainterWidget()
{
}

void PainterWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::red);
    painter.setPen(Qt::black);

    mController->draw(painter);

    this->update();
}

void PainterWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Space:
        mModel->eat();
        break;
    case Qt::Key_Up:
        mModel->moveUp();
        break;
    case Qt::Key_Down:
        mModel->moveDown();
        break;
    case Qt::Key_Left:
        mModel->moveLeft();
        break;
    case Qt::Key_Right:
        mModel->moveRight();
        break;
    }
}


#ifndef PainterWidget_H
#define PainterWidget_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <memory>

#include "modelsnakebody.h"
#include "paintersnakecontroller.h"
#include "widgetinfo.h"

class PainterWidget : public QWidget
{
    Q_OBJECT

public:
    PainterWidget(QWidget *parent = nullptr);
    ~PainterWidget();

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    std::shared_ptr<WidgetInfo> mWidgetInfo;
    std::shared_ptr<ModelSnakeBody> mModel;
    std::unique_ptr<PainterSnakeController> mController;
    QTimer mTimer;
};
#endif // PainterWidget_H

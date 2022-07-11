#ifndef PainterWidget_H
#define PainterWidget_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <memory>

#include "modelsnakebody.h"
#include "modelfood.h"
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

private slots:
    void onTimerIntervalEnd();

private:
    std::shared_ptr<WidgetInfo> mWidgetInfo;
    std::shared_ptr<ModelSnakeBody> mModelSnakeBody;
    std::shared_ptr<ModelFood> mModelFood;
    std::unique_ptr<PainterSnakeController> mController;
    QTimer mTimer;
};
#endif // PainterWidget_H

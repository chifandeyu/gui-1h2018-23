#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>

#include <windows.h>

class TestModel : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit TestModel(QObject *parent = 0);
    ~TestModel();
     void keyPressEvent(QKeyEvent *event);

signals:

public slots:
    void slotGameTimer();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal angle;

};
#endif // TESTMODEL_H

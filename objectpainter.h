#ifndef OBJECTPAINTER_H
#define OBJECTPAINTER_H


#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>

class ObjectPainter : public QObject, public QGraphicsItem {
  Q_OBJECT
public:
    explicit ObjectPainter(QObject *parent = 0);
    ~ObjectPainter();
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

#endif // OBJECTPAINTER_H

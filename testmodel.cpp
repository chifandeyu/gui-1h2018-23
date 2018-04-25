#include "testmodel.h"

TestModel::TestModel(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    angle = 0;
    setRotation(angle);
}

TestModel::~TestModel()
{

}

QRectF TestModel::boundingRect() const
{
    return QRectF(-25,-40,50,80);
}

void TestModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;

        polygon << QPoint(0,-10) << QPoint(6,10) << QPoint(-6,10);
        painter->setBrush(Qt::red);
        painter->drawPolygon(polygon);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void TestModel::keyPressEvent(QKeyEvent *event) {
    switch(event->key())
    {
    case Qt::Key_Up:
        setPos(mapToParent(0, -5));
        break;
    case Qt::Key_Down:
        setPos(mapToParent(0, 5));
        break;
    case Qt::Key_Left:
        angle -= 10;
        setRotation(angle);
        break;
    case Qt::Key_Right:
        angle += 10;
        setRotation(angle);
        break;
    case Qt::Key_Space:

        break;
    default:
        break;
    }
}
void TestModel::slotGameTimer()
{
    //  GetAsyncKeyState only for WINDOWS
    // 
    /*
    if(GetAsyncKeyState(VK_LEFT)){
        angle -= 10;
        setRotation(angle);
    }
    if(GetAsyncKeyState(VK_RIGHT)){
        angle += 10;
        setRotation(angle);
    }
    if(GetAsyncKeyState(VK_UP)){
        setPos(mapToParent(0, -5));
    }
    if(GetAsyncKeyState(VK_DOWN)){
        setPos(mapToParent(0, 5));
    }
*/

    //board check
    if(this->x() - 10 < -250){
        this->setX(-240);
    }
    if(this->x() + 10 > 250){
        this->setX(240);
    }

    if(this->y() - 10 < -250){
        this->setY(-240);
    }
    if(this->y() + 10 > 250){
        this->setY(240);
    }
}

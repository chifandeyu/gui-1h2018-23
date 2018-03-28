#include "widget.h"
#include "ui_widget.h"
#include <typeinfo>
#include <QSignalMapper>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    _state(new State()),
    _controller(new Controller(_state.get())),
    _objectPainter(new ObjectPainter(_state.get()))
{

    this->resize(800,600);
    this->setFixedSize(800,600);
   .. QSignalMapper* signalMapper = new QSignalMapper (this);
    timer = std::shared_ptr<QTimer>(new QTimer());
    connect(timer.get(), &QTimer::timeout, _controller.get(), &Controller::update);
    //connect(timer.get(), &QTimer::timeout, _objectPainter.get(), [&ObjectPainter] { slotGameTimer(_state);});
    connect(timer.get(), &QTimer::timeout, _objectPainter.get(), &ObjectPainter::slotGameTimer);
    timer->start(1000 / 50);
    //    ui->setupUi(this);
    //    scene = new QGraphicsScene();
    //    // add obj
    //    model =new TestModel();
    //    ui->graphicsView->setScene(scene);
    //    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    //
    //    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // scroll off
    //    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //    scene->setSceneRect(-250,-250,500,500);

    //    //    scene->addLine(-250,0,250,0,QPen(Qt::black));   // lines
    //    //    scene->addLine(0,-250,0,250,QPen(Qt::black));

    //    scene->addLine(-250,-250, 250,-250, QPen(Qt::black)); // board
    //    scene->addLine(-250, 250, 250, 250, QPen(Qt::black));
    //    scene->addLine(-250,-250,-250, 250, QPen(Qt::black));
    //    scene->addLine( 250,-250, 250, 250, QPen(Qt::black));

    //    scene->addItem(model);   // add obj
    //    model->setPos(0,0);      // center
    //    model->setFlag(QGraphicsItem::ItemIsFocusable);
    //    model->setFocus();
    //    // speed 20 times in 1 second
    //    timer = new QTimer();
    //    connect(timer, &QTimer::timeout, model, &TestModel::slotGameTimer);
    //    timer->start(1000 / 50);

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"KEYPREESD";
    switch(event->key())
    {
    case Qt::Key_Up:


        break;
    case Qt::Key_Down:

        break;
    case Qt::Key_Left:


        break;
    case Qt::Key_Right:

        break;
    case Qt::Key_Space:

        break;
    default:
        break;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{

}

Widget::~Widget()
{
    delete ui;
}
/*
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    ObjectBuilder builder;

    drawAsteroids(_state, &painter);

    auto asteroid = builder.makeAsteroid(241,400,3);
    auto bullet = builder.makeBullet(418,180.0);
    auto ship = std::dynamic_pointer_cast<Ship>(builder.makeShip(110,180.0));
    //Ship ship(0.0,0.0);
    drawShip(ship, &painter);
    drawBullet(bullet, &painter);
    drawAsteroid(asteroid, &painter);
}
*/

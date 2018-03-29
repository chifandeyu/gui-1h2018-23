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
    //QSignalMapper* signalMapper = new QSignalMapper (this);
    timer = std::shared_ptr<QTimer>(new QTimer());
    connect(timer.get(), &QTimer::timeout, _controller.get(), &Controller::update);
    //connect(timer.get(), &QTimer::timeout, _objectPainter.get(), [&ObjectPainter] { slotGameTimer(_state);});
    connect(timer.get(), &QTimer::timeout,  _objectPainter.get(), [this] { update();});

    timer->start(1000 / 50);
    //ui->setupUi(this);
    //scene = new QGraphicsScene();
    // add obj
    //ui->graphicsView->setScene(scene);
    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);    //
    //ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // scroll off
    //ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //    scene->setSceneRect(-250,-250,500,500);

    //    //    scene->addLine(-250,0,250,0,QPen(Qt::black));   // lines
    //    //    scene->addLine(0,-250,0,250,QPen(Qt::black));

    //    scene->addLine(-250,-250, 250,-250, QPen(Qt::black)); // board
    //    scene->addLine(-250, 250, 250, 250, QPen(Qt::black));
    //    scene->addLine(-250,-250,-250, 250, QPen(Qt::black));
    //    scene->addLine( 250,-250, 250, 250, QPen(Qt::black));

    // scene->addItem(_objectPainter.get());   // add obj
    // _objectPainter->setPos(0,0);      // center
    //    model->setFlag(QGraphicsItem::ItemIsFocusable);
    //    model->setFocus();
    //    // speed 20 times in 1 second
    //    timer = new QTimer();
   // connect(timer, &QTimer::timeout, _objectPainter.get(), &ObjectPainter::slotGameTimer);
    //    timer->start(1000 / 50);

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"KEYPREESD";
    _controller->keyPressEvent(event);

}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
  _controller->keyReleaseEvent(event);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    _objectPainter->paint(&painter, nullptr, this);

}

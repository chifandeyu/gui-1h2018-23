#include "widget.h"
#include "ui_widget.h"
#include <typeinfo>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    _state(new State()),
    _controller(new Controller(_state.get()))
{

    this->resize(800,600);
    this->setFixedSize(800,600);
    timer = std::shared_ptr<QTimer>(new QTimer());
    connect(timer.get(), &QTimer::timeout, _controller.get(), &Controller::update);
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

Widget::~Widget()
{
    delete ui;
}

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

inline void Widget::drawShip(std::shared_ptr<Ship> ship,QPainter *painter) {

    drawObject(std::dynamic_pointer_cast<Object>(ship),painter);
}

inline void Widget::drawBullet(std::shared_ptr<Object> object, QPainter *painter) {
    drawObject(object,painter);
}

inline void Widget::drawAsteroids(std::shared_ptr<State> state, QPainter *painter)
{
    for (auto asteriod : state->objects)
        drawBullet(asteriod,painter);

}

inline void Widget::drawAsteroid(std::shared_ptr<Object> asteroid, QPainter *painter)
{
    drawObject(asteroid,painter);
}


void Widget::drawObject(std::shared_ptr<Object> object,QPainter *painter)
{
    Object::cloud points=object->getPointCloud();
    for (size_t i=1;i<points.size();i++)
        painter->drawLine(object->getPos()+points[i-1]*25,object->getPos()+points[i]*25);
    painter->drawLine(object->getPos()+points.front()*25,object->getPos()+points.back()*25);


}

void Widget::drawBullets(std::shared_ptr<State> state, QPainter *painter)
{
    for (auto bullet : state->bullets)
        drawBullet(bullet,painter);

}


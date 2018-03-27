#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(800,600);
    this->setFixedSize(800,600);

    scene = new QGraphicsScene();
    // add obj
    model =new TestModel();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    //
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // scroll off
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(-250,-250,500,500);

//    scene->addLine(-250,0,250,0,QPen(Qt::black));   // lines
//    scene->addLine(0,-250,0,250,QPen(Qt::black));

    scene->addLine(-250,-250, 250,-250, QPen(Qt::black)); // board
    scene->addLine(-250, 250, 250, 250, QPen(Qt::black));
    scene->addLine(-250,-250,-250, 250, QPen(Qt::black));
    scene->addLine( 250,-250, 250, 250, QPen(Qt::black));

    scene->addItem(model);   // add obj
    model->setPos(0,0);      // center
    model->setFlag(QGraphicsItem::ItemIsFocusable);
    model->setFocus();
    // speed 20 times in 1 second
    timer = new QTimer();
    connect(timer, &QTimer::timeout, model, &TestModel::slotGameTimer);


    timer->start(1000 / 50);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::drawShip(Ship *ship)
{
    ship->getPointCloud();
    //QPainter painter();
    QPolygon polygon;

    polygon << QPoint(0,-40) << QPoint(25,40) << QPoint(-25,40);
  //  painter->setBrush(Qt::red);
    //painter->drawPolygon(polygon);

}

void Widget::drawObject(Object *object)
{

}

void Widget::paintEvent(QPaintEvent *event)
{

}


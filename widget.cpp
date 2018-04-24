#include "widget.h"
#include "ui_widget.h"
#include <typeinfo>
#include <QSignalMapper>
#include <QDebug>
#include <QCheckBox>
#include <QPushButton>
#include <QMenu>
#include <QLabel>
#include <QTextBlock>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    scene(new QGraphicsScene),
    _state(new State()),
    _controller(new Controller(_state.get())),
    _objectPainter(new ObjectPainter(_state.get())),
    _grid(new  QGridLayout),
    _menu(createMenu()),
    _score(createScoreMenu()),
    pause(true)
{   //std::shared_ptr<QWidget> rect;


    //_grid->addWidget(new Widget,2,2);
    //    QGroupBox *groupBox = new QGroupBox;
    //    std::shared_ptr<QVBoxLayout>vbox (new QVBoxLayout);
    //    vbox->addStretch(1);
    //    groupBox->setFlat(true);
    //    groupBox->setLayout(vbox.get());
    //    QGroupBox *groupBox2 = new QGroupBox;
    //    std::shared_ptr<QVBoxLayout>vbox2 (new QVBoxLayout);
    //    vbox2->addStretch(1);
    //    groupBox2->setFlat(true);
    //    groupBox2->setLayout(vbox2.get());
    //vbox->addWidget(checkBox1);
    // vbox->addWidget(checkBox2);
    //vbox->addWidget(tristateBox);


    //  QGroupBox *menu=createMenu();
    QWidget *em1 =EmptyMenu();
    QWidget *em2 =EmptyMenu();
    _grid->addWidget(_menu.get(),1,1);
    _grid->addWidget(em1,0,0);
    _grid->addWidget(em2,2,2);
    _grid->addWidget(_score.get(),1,1);
    em1->show();
    em2->show();
    em1->setEnabled(false);
    em2->setEnabled(false);
    _score->hide();
    _score->setEnabled(false);
    _menu->show();
    _menu->setEnabled(true);

    setLayout(_grid.get());

    this->resize(800,600);
    this->setFixedSize(800,600);
    //scene->backgroundBrush()
    // QBrush brush;
    // brush.setColor(Qt::black);
    //brush.setStyle(Qt::SolidPattern);
    // scene->backgroundBrush().color().black();


    // ui->graphicsView->setScene(scene);

    // std::shared_ptr<QPainter> painter;
    //  painter->setPen(QPen(Qt::black));
    //    QVector<QPoint> point;//(new QPointF(0,0),  new QPointF(800,0), new QPointF(800,600), new QPointF(0,600));
    //    point.push_back( QPoint (0,0))  ;
    //    point. push_back(QPoint(800,0));
    //    point.push_back( QPoint(800,600));
    //    point.push_back( QPoint(0,600));
    //    QPolygon game_space (*&point);
    //    painter->drawPolygon(game_space);
    // QSignalMapper* signalMapper = new QSignalMapper (this);
    timer = std::shared_ptr<QTimer>(new QTimer());
    connect(timer.get(), &QTimer::timeout, _controller.get(), &Controller::update);
    //connect(timer.get(), &QTimer::timeout, _objectPainter.get(), [&ObjectPainter] { slotGameTimer(_state);});
    connect(timer.get(), &QTimer::timeout,  _objectPainter.get(), [this] { update();});

    //timer->start(1000 / 50);
    //ui->setupUi(this);
    //scene = new QGraphicsScene();
    // add obj

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
    if(event->key() ==Qt::Key_Escape){
        if (!pause) {
            timer->stop();
            _menu->setEnabled(true);
            _menu->show();

            pause=true;




        } else {
            _menu->setEnabled(false);
            _menu->hide();


            pause=false;
            timer->start(1000 / 50);
        }
        // this->close();
        // this->~Widget();
        //  emit firstWindow();


    }

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

QGroupBox *Widget::createMenu()
{

    QGroupBox *groupBox = new QGroupBox();
    // groupBox->setCheckable(true);
    //  groupBox->setChecked(true);
    QString styleSheet ="background-color:rgb(0, 0, 0);color:white;"
                        "border: 5px solid white;border-style: outset;border-width: 2px; border-radius: 10px; border-color: beige; "
                        " font: bold 14px;min-width: 10em;padding: 6px;";
    QPushButton *startButton=new QPushButton(tr("&Start"));
    QPushButton *scoreButton=new QPushButton(tr("&GameScore"));
    QPushButton *quitButton=new QPushButton(tr("&Quit"));
    connect(startButton,&QPushButton::clicked,this,startGame);
    connect(scoreButton,&QPushButton::clicked,this,openGameScore);
    connect(quitButton,&QPushButton::clicked,this,quitGame);
    //    std::shared_ptr<QPushButton> startButton (  new QPushButton(tr("&Start")));
    //    std::shared_ptr<QPushButton> scoreButton ( new QPushButton(tr("&GameScore")));
    //    std::shared_ptr<QPushButton> optionButton ( new QPushButton(tr("&Start")));
    //    std::shared_ptr<QPushButton> quitButton ( new QPushButton(tr("&Quit")));

    startButton->setStyleSheet(styleSheet);
    scoreButton->setStyleSheet(styleSheet);
    quitButton->setStyleSheet(styleSheet);
    QLabel *lab=new QLabel("made by danilapal and DarkNoys");
    lab->setStyleSheet(styleSheet);

    //    QPushButton *toggleButton = new QPushButton(tr("&Toggle Button"));
    //    toggleButton->setCheckable(true);
    //    toggleButton->setChecked(true);
    //    QPushButton *flatButton = new QPushButton(tr("&Flat Button"));
    //    flatButton->setFlat(true);

    //    QPushButton *popupButton = new QPushButton(tr("Pop&up Button"));
    //    QMenu *menu = new QMenu(this);
    //    menu->addAction(tr("&First Item"));
    //    menu->addAction(tr("&Second Item"));
    //    menu->addAction(tr("&Third Item"));
    //    menu->addAction(tr("F&ourth Item"));
    //    popupButton->setMenu(menu);

    //    QAction *newAction = menu->addAction(tr("Submenu"));
    //    QMenu *subMenu = new QMenu(tr("Popup Submenu"));
    //    subMenu->addAction(tr("Item 1"));
    //    subMenu->addAction(tr("Item 2"));
    //    subMenu->addAction(tr("Item 3"));
    //    newAction->setMenu(subMenu);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(startButton);
    vbox->addWidget(scoreButton);
    vbox->addWidget(quitButton);

    vbox->addWidget(lab);

    //    vbox->addWidget(toggleButton);
    //    vbox->addWidget(flatButton);
    //    vbox->addWidget(popupButton);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Widget::createScoreMenu()
{
    QGroupBox *groupBox = new QGroupBox();

    QString styleSheet ="background-color:rgb(0, 0, 0);color:white;"
                        "border: 5px solid white;border-style: outset;border-width: 2px; border-radius: 10px; border-color: beige; "
                        " font: bold 14px;min-width: 10em;padding: 6px;";
    QPushButton *backButton=new QPushButton(tr("&Back"));
    backButton->setStyleSheet(styleSheet);
    connect(backButton,&QPushButton::clicked,this,backToMaintMenu);
    QLabel *lab=new QLabel("1.");
    lab->setStyleSheet(styleSheet);

    QVBoxLayout *vbox = new QVBoxLayout;

    vbox->addWidget(lab);
    vbox->addWidget(backButton);


    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

void Widget::startGame()
{
    qDebug()<<"STARTS";
    newGame();
    //em1->hide();
    //em2->hide();
    _menu->hide();
    _menu->setEnabled(false);
    timer->start(1000 / 50);
}

void Widget::openGameScore()
{
    qDebug()<<"OpenGameScore";
    _menu->hide();
    _menu->setEnabled(false);
    _score->show();
    _score->setEnabled(true);

    // _score.reset();
    // _score.;




}

void Widget::quitGame()
{
    exit(0);
}

void Widget::backToMaintMenu()
{
    _score->setEnabled(false);
    _score->hide();
    _menu->setEnabled(true);
    _menu->show();
    QFile file("gameScore.txt") ;
   // file.open("/:gameScore.txt");
    if(file.isOpen())
    {
    qDebug() << "File is open";
    } else { qDebug() << "FAIL";}
    if(QFile::exists("gameScore.txt"))
    {
    qDebug() << "Файл существует";
    }

}

QWidget *Widget::EmptyMenu()
{
    QWidget *groupBox = new QWidget();
    // groupBox->setFlat(true);


    QVBoxLayout *vbox = new QVBoxLayout;

    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    return groupBox;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    _objectPainter->paint(&painter, nullptr, this);

}

#include "widget.h"
#include "ui_widget.h"
#include <typeinfo>
#include <QSignalMapper>
#include <QDebug>
#include <QCheckBox>
#include <QLineEdit>
#include <QMenu>
#include <QTextBlock>
#include <iostream>
#include <fstream>
#include <QDesktopWidget>
#include <QDir>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    scene(new QGraphicsScene),
    _state(new State()),
    _controller(new Controller(_state.get(), 800, 600)),
    _objectPainter(new ObjectPainter(_state.get())),
    _grid(new  QGridLayout),
    _menu(createMenu()),
    _score(createScoreMenu()),
    //  _option(createOptionMenu()),
    _gameOverScreen(createGameOverMenu()),
    pause(false),
    start(false),
    fullScr(false)


{

    QWidget *em1 =EmptyMenu();
    QWidget *em2 =EmptyMenu();

    _grid->addWidget(_menu.get(),1,1);
    _grid->addWidget(em1,0,0);
    _grid->addWidget(em2,2,2);
    _grid->addWidget(_score.get(),1,1);
    _grid->addWidget(_gameOverScreen.get(),1,1);
    em1->show();
    em2->show();
    em1->setEnabled(false);
    em2->setEnabled(false);
    _gameOverScreen->hide();
    _gameOverScreen->setEnabled(false);
    _score->hide();
    _score->setEnabled(false);
    _menu->show();
    _menu->setEnabled(true);


    setLayout(_grid.get());
    QRect rec = QApplication::desktop()->screenGeometry();
    double height = rec.height();
    double width = rec.width();
    _w=width;
    _h=height;
    this->resizeScreen(_w,_h);


    timer = std::shared_ptr<QTimer>(new QTimer());
    connect(timer.get(), &QTimer::timeout, _controller.get(), &Controller::update);
    connect(timer.get(), &QTimer::timeout,  _objectPainter.get(), [this] { update();});

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() ==Qt::Key_Escape){
        if (start) {
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

        }
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
    QString styleSheet ="background-color:rgb(0, 0, 0);color:white;"
                        "border: 5px solid white;border-style: outset;border-width: 2px; border-radius: 10px; border-color: beige; "
                        " font: bold 14px;min-width: 10em;padding: 6px;";
    QPushButton *startButton=new QPushButton(tr("&Start"));
    QPushButton *scoreButton=new QPushButton(tr("&Game Score"));

    QPushButton *quitButton=new QPushButton(tr("&Quit"));


    QRect rec = QApplication::desktop()->screenGeometry();
    double height = rec.height();
    double width = rec.width();

    QPushButton *toggleButton = new QPushButton(tr("&Full Screen off"));

    toggleButton->setStyleSheet(styleSheet);
    connect(toggleButton,&QPushButton::clicked,[this,toggleButton,height,width](){resizeScreen(width,height,toggleButton);});

    connect(startButton,&QPushButton::clicked,this, [this](){startGame();});
    connect(scoreButton,&QPushButton::clicked,this, [this](){openGameScore();});

    connect(quitButton,&QPushButton::clicked,this, [this](){quitGame();});

    startButton->setStyleSheet(styleSheet);
    scoreButton->setStyleSheet(styleSheet);
    quitButton->setStyleSheet(styleSheet);
    QPushButton *lab=new QPushButton(tr("&Made by danilapal and DarkNoys"));
    lab->setStyleSheet(styleSheet);


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(startButton);
    vbox->addWidget(scoreButton);
    //vbox->addWidget(optionButon);
    vbox->addWidget(toggleButton);
    vbox->addWidget(quitButton);
    vbox->addWidget(lab);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    groupBox->setStyleSheet(styleSheet);
    return groupBox;
}

QGroupBox *Widget::createScoreMenu()
{
    std::vector<std::pair<int, int> > players;

    std::sort(players.begin(), players.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });

    QGroupBox *groupBox = new QGroupBox();

    QString styleSheet ="background-color:rgb(0, 0, 0);color:white;"
                        "border: 5px solid white;border-style: outset;border-width: 2px; border-radius: 10px; border-color: beige; "
                        " font: bold 14px;min-width: 10em;padding: 6px;";
    QPushButton *backButton=new QPushButton(tr("&Back"));
    backButton->setStyleSheet(styleSheet);
    connect(backButton,&QPushButton::clicked, this, [this](){backToMaintMenu();});
    QLabel *lab=new QLabel("1.");

    connect(this,&Widget::openScore,this, [this,lab] (){updateScore(lab);});
    lab->setStyleSheet(styleSheet);

    QVBoxLayout *vbox = new QVBoxLayout;

    vbox->addWidget(lab);
    vbox->addWidget(backButton);

    vbox->addStretch(1);
    groupBox->setStyleSheet(styleSheet);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *Widget::createOptionMenu()
{
    QGroupBox *groupBox = new QGroupBox();

    QString styleSheet ="background-color:rgb(0, 0, 0);color:white;"
                        "border: 5px solid white;border-style: outset;border-width: 2px; border-radius: 10px; border-color: beige; "
                        " font: bold 14px;min-width: 10em;padding: 6px;";
    QPushButton *backButton=new QPushButton(tr("&Back"));
    backButton->setStyleSheet(styleSheet);
    connect(backButton,&QPushButton::clicked, this, [this](){backFromOptionToMaintMenu();});

    QPushButton *toggleButton = new QPushButton(tr("&Sound on"));

    toggleButton->setStyleSheet(styleSheet);
    QPushButton *popupButton = new QPushButton(tr("Resoulution"));
    QMenu *menu = new QMenu(this);
    QAction *ac1 = new QAction(tr("&800 x 600 "));
    menu->addAction(ac1);

    QAction *ac2 = new QAction(tr("&1280 x 1024"));
    menu->addAction(ac2);

    QAction *ac3 = new QAction(tr("&1920 x 1080"));
    menu->addAction(ac3);

    QAction *ac4 = new QAction(tr("&Full screen off"));
    menu->addAction(ac4);

    popupButton->setMenu(menu);
    popupButton->setStyleSheet(styleSheet);
    menu->setStyleSheet(styleSheet);
    QRect rec = QApplication::desktop()->screenGeometry();
    double height = rec.height();
    double width = rec.width();

    connect(toggleButton,&QPushButton::clicked,[this,toggleButton](){changeSoundPresence(toggleButton);});
    connect(ac1,&QAction::triggered,this,[this] () {resizeScreen(800,600);});
    connect(ac2,&QAction::triggered,this,[this] () {resizeScreen(1280,1024);});
    connect(ac3,&QAction::triggered,this,[this] () {resizeScreen(1920,1080);});
    connect(ac4,&QAction::triggered,this,[this,height,width] ( ) {resizeScreen(1366,768);});
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(toggleButton);
    vbox->addWidget(popupButton);
    vbox->addWidget(backButton);
    vbox->addStretch(1);
    groupBox->setStyleSheet(styleSheet);
    groupBox->setLayout(vbox);
    return groupBox;
}

QGroupBox *Widget::createGameOverMenu()
{
    QGroupBox *groupBox = new QGroupBox();

    QString styleSheet ="background-color:rgb(0, 0, 0);color:white;"
                        "border: 5px solid white;border-style: outset;border-width: 2px; border-radius: 10px; border-color: beige; "
                        " font: bold 14px;min-width: 10em;padding: 6px;";

    QPushButton *lab=new QPushButton(tr("&GAME OVER"));
    QPushButton *lab2=new QPushButton(tr("&It was a good game.Please enter your name!"));
    QLineEdit *line=new QLineEdit;
    //connect(backButton,&QPushButton::clicked,this, [this] (){updateScore(lab);});
    line->setStyleSheet(styleSheet);
    connect(line,&QLineEdit::returnPressed,this,[this,line] (){backToMaintMenuAfterGameOver(line);});
    lab->setStyleSheet(styleSheet);
    lab2->setStyleSheet(styleSheet);

    QVBoxLayout *vbox = new QVBoxLayout;

    groupBox->setStyleSheet(styleSheet);
    vbox->addWidget(lab);
    vbox->addWidget(lab2);
    vbox->addWidget(line);

    groupBox->setLayout(vbox);

    return groupBox;
}

void Widget::openGameOverScreen()
{
    _menu->hide();
    _menu->setEnabled(false);

    _gameOverScreen->show();
    _gameOverScreen->setEnabled(true);
}

void Widget::updateScore(QLabel *lab)
{
    std::vector<std::pair<QString,int>> ScoreTable=gTools::readScore();
    //upd score
    QString scoreText="";
    for  (size_t i=0; i < ScoreTable.size();i++) {
        scoreText+=ScoreTable[i].first+" "+QString::number(ScoreTable[i].second);
        if (i != ScoreTable.size()-1)
            scoreText += "\n";
    }
    lab->setText(scoreText);
    lab->update();
}

void Widget::backToMaintMenuAfterGameOver(QLineEdit *line)
{

    _controller->writeScore(line->text());
    _gameOverScreen->setEnabled(false);
    _gameOverScreen->hide();
    _menu->setEnabled(true);
    _menu->show();
    start=false;

}

void Widget::changeSoundPresence(QPushButton *button)
{
    if (start) {
        start=false;
        button->setText(tr("&Sound off"));

    } else {
        start=true;
        button->setText(tr("&Sound on"));

    }

}

void Widget::resizeScreen(size_t w, size_t h, bool fullScr)
{

    _w=w;
    _h=h;
    this->resize(_w,_h);
    _controller->resize(_w,_h);
    QRect rec = QApplication::desktop()->screenGeometry();
    double height = rec.height();
    double width = rec.width();

    if (fullScr) {

        this->fullScr=true;
        this->setWindowState( Qt::WindowFullScreen );
    }
    else {
        this->fullScr=false;
        this->setWindowState(Qt::WindowMaximized);
    }
    update();
}

void Widget::resizeScreen(size_t w, size_t h, QPushButton *button)
{
    fullScr=!fullScr;
    if (fullScr) {
        button->setText(tr("&Full Screen on"));

    }
    else {
        button->setText(tr("&Full Screen off"));

    }

    resizeScreen(w,h,fullScr);

}

void Widget::startGame()
{  if (!start) {
        start=true;

        _menu->hide();
        _menu->setEnabled(false);
        pause=false;
        newGame();

        timer->start(1000 / 50);
    }
}

void Widget::openGameScore()
{

    _menu->hide();
    _menu->setEnabled(false);
    emit openScore();
    _score->update();
    _score->show();
    _score->setEnabled(true);

}

void Widget::openOption()
{
    _menu->hide();
    _menu->setEnabled(false);
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
}

void Widget::backFromOptionToMaintMenu()
{
    _menu->setEnabled(true);
    _menu->show();
}

QWidget *Widget::EmptyMenu()
{
    QWidget *groupBox = new QWidget();
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    return groupBox;
}

void Widget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    _objectPainter->paint(&painter, nullptr, this);

    if ((_state->flags.at("isGameOver")) && (!pause)) {
        pause=true;
        timer->stop();
        openGameOverScreen();
        update();
    }

}

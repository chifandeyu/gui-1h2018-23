#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),_widget(nullptr),_gamescore(nullptr)
{

    ui->setupUi(this);
    _gamescore = std::shared_ptr<gameScore>  (new gameScore);
    connect(_gamescore.get(),&gameScore::firstWindow,this,&MainWindow::show);
   // ui->widget->hide();
  //  ui->
//    _main_menu.setGeometry(0,0,100,100);
 //   _main_menu.addAction(ui->pushButton);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{   if (_widget==nullptr)
       // _widget.reset();
    _widget = std::shared_ptr<Widget> (new Widget);

    _widget->newGame();
    connect(_widget.get(),&Widget::firstWindow,this,&MainWindow::show);
    _widget->show();
    this->close();


}

void MainWindow::on_pushButton_2_clicked()
{

    _gamescore->show();
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}

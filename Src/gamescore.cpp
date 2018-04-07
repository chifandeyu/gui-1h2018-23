#include "gamescore.h"
#include "ui_gamescore.h"

gameScore::gameScore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameScore)
{
    ui->setupUi(this);

}

gameScore::~gameScore()
{
    delete ui;
}

void gameScore::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

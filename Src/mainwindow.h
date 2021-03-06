#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <widget.h>
#include <gamescore.h>
#include <QGroupBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Widget> _widget =nullptr ;
    std::shared_ptr <gameScore> _gamescore;
    QGroupBox _main_menu;
    QGroupBox _gameScore;

};

#endif // MAINWINDOW_H

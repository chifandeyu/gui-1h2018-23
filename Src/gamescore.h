#ifndef GAMESCORE_H
#define GAMESCORE_H

#include <QWidget>

namespace Ui {
class gameScore;
}

class gameScore : public QWidget
{
    Q_OBJECT

public:
    explicit gameScore(QWidget *parent = 0);
    ~gameScore();

private slots:
    void on_pushButton_clicked();

private:
   Ui::gameScore *ui;

signals:
    void firstWindow();


};

#endif // GAMESCORE_H

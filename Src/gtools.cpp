#include "gtools.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>
namespace gTools {
  double SHIP_DEF_ACC_VAL = 0.18;
  double SHIP_DEF_ROTATE_ANGLE_SPEED = 0.09;
  double SHIP_DEF_MAX_SPEED = 8;
  double SHIP_DEF_LIFE = 3;
  double STRIKE_BREAK = 150;
  double DEATH_BREAK = 2000;
  double BULLET_MASS = 0.9;



  double random(double left, double right) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(left, right);
    return dist(gen);
  }

  int timeLeft(time t) {
    return std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now()
                                                      - t).count();
  }
// not using (see backToMaintMenuAfterGameOver)
  void writeScore(std::vector<std::pair<QString,int>> scoreVec) {
   // QFile file("score.txt");
   // QFile file("SS.txt");
      #ifdef Q_OS_LINUX
      QFile file (QDir::homePath() + "/.asteroid_game_score");
      #else
      QFile file (QDir::currentPath()+"/gameScore.txt");
      #endif



    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QTextStream fileS(&file);
      for(int i = 0 ; i < scoreVec.size(); i++) {
          auto p = scoreVec[i];
          if (p.first.size()!=0) {
              fileS << p.first << " " << p.second;
              if (i != scoreVec.size()-1)
                  fileS << endl;
          }

      }
      file.close();
    }



  }

  std::vector<std::pair<QString,int>> readScore() {
    std::vector<std::pair<QString,int>> a;
   // QFile file(":/score/score.txt");
     // QFile file("SS.txt");
    #ifdef Q_OS_LINUX
    QFile file (QDir::homePath() + "/.asteroid_game_score");
    #else
    QFile file (QDir::currentPath()+"/gameScore.txt");
    #endif

    if (file.exists()) {
      if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
          QTextStream fileS(&file);
          QString name;
          int score;

          while(!fileS.atEnd()) {
            fileS >> name >> score;
            a.push_back(std::pair<QString,int>(name, score));
          }
          file.close();
      }

    }

    std::sort(a.begin(),a.end(),[](std::pair<QString,int> a,std::pair<QString,int> b) {return (a.second>b.second);});
    return a;
  }


}



#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "bio.h"
#include "cell.h"
#include "enemy.h"
#include "virus.h"
#include "feed.h"

class Bio;
class Cell;
class Enemy;
class Virus;
class Feed;

class Game : public QObject
{
    Q_OBJECT
private:
    Bio * player;
    QList<Bio *> bios;

    QGraphicsScene * s;
    QTimer * makeTimer;
//    QTimer * overTimer;
public:
    Game(QGraphicsScene * s);
    void playGame();
public slots:
    void makeBios();
};

#endif // GAME_H


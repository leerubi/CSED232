#include "game.h"

Game::Game(QGraphicsScene * s)
{
    this->s = s;
}

void Game::makeBios()
{
    // 5개의 생명체 생성.
    for (int i = 0; i < 5; i++)
    {
        int prob = rand() % 100 + 1;
        if (prob >= 0 && prob <= 70)    // 70%의 확률로 Feed 생성.
        {
            bios.push_back(dynamic_cast<Bio*>(new Feed(s)));
        }
        else if (prob > 70 && prob <= 85)   // 15%의 확률로 Virus 생성.
        {
            bios.push_back(dynamic_cast<Bio*>(new Virus(s)));
        }
        else    // 15%의 확률로 Enemy 생성.
        {
            bios.push_back(dynamic_cast<Bio*>(new Enemy(s)));
        }
    }
}

void Game::playGame()
{
    // player와 30개의 생명체 생성.
    player = dynamic_cast<Bio*>(new Cell(s));
    for (int i = 0; i < 6; i++)
        makeBios();
    // 15초마다 5개의 생명체 생성.
    makeTimer = new QTimer();
    connect(makeTimer, SIGNAL(timeout()), this, SLOT(makeBios()));
    makeTimer->start(15000);
//    // 50ms마다 game over 체크.
//    overTimer = new QTimer();
//    connect(overTimer, SIGNAL(timeout()), this, SLOT(gameOver()));
//    overTimer->start(50);
}

#include "virus.h"

Virus::Virus() : Bio()
{

}

Virus::Virus(QGraphicsScene * s) : Bio(s)
{
    velocity = VIRUS_VELOCITY;
    moveCnt = 0;
    sizeCnt = 0;

    setSize(rand() % (VIRUS_MAX_SIZE-VIRUS_MIN_SIZE+1) + VIRUS_MIN_SIZE);
    setAxisX(rand() % (WIDTH+1));
    setAxisY(rand() % (HEIGHT+1));
    Draw();

    moveTimer = new QTimer();
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(Move()));
    moveTimer->start(1000);

    sizeTimer = new QTimer();
    connect(sizeTimer, SIGNAL(timeout()), this, SLOT(Shrink()));
    sizeTimer->start(4000);
}

Virus::~Virus()
{
    delete moveTimer;
    delete sizeTimer;
}

void Virus::Draw()
{
    setBrush(QBrush(Qt::black));
    setRect(getAxisX(),getAxisY(),getSize(),getSize());
    getS()->addItem(this);
}

void Virus::Move()
{
    // 방향 설정.
    changeDir();
    // 방향에 따른 움직임.
    switch (direction) {
    case LEFT:
        setRect(getAxisX()-velocity, getAxisY(), getSize(), getSize());
        setAxisX(getAxisX()-velocity);
        break;
    case RIGHT:
        setRect(getAxisX()+velocity, getAxisY(), getSize(), getSize());
        setAxisX(getAxisX()+velocity);
        break;
    case UP:
        setRect(getAxisX(), getAxisY()-velocity, getSize(), getSize());
        setAxisY(getAxisY()-velocity);
        break;
    case DOWN:
        setRect(getAxisX(), getAxisY()+velocity, getSize(), getSize());
        setAxisY(getAxisY()+velocity);
        break;
    }
    // 화면 밖을 벗어나면 사망.
    if(getAxisX() < 0 || getAxisX() > 800 || getAxisY() < 0 || getAxisY() > 800)
    {
        scene()->removeItem(this);
        delete this;
    }
    // 4번째로 크기가 감소할 때 바이러스 소멸.
    if(sizeCnt == 4)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Virus::Shrink()
{
    sizeCnt++;
    setSize(getSize()*0.75);
}

void Virus::changeDir()
{
    moveCnt++;
    if (moveCnt == 4)
    {
        moveCnt = 0;
    }
    switch (moveCnt) {
    case 0:
        direction = DOWN;
        break;
    case 1:
        direction = RIGHT;
        break;
    case 2:
        direction = UP;
        break;
    case 3:
        direction = LEFT;
        break;
    }
}

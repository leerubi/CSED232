#include "enemy.h"

Enemy::Enemy() : Bio()
{

}

Enemy::Enemy(QGraphicsScene * s) : Bio(s)
{
    velocity = ENEMY_VELOCITY;

    setSize(rand() % (ENEMY_MAX_SIZE-ENEMY_MIN_SIZE+1) + ENEMY_MIN_SIZE);
    setAxisX(rand() % (WIDTH+1));
    setAxisY(rand() % (HEIGHT+1));
    Draw();

    moveTimer = new QTimer();
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(Move()));
    moveTimer->start(50);

    dirTimer = new QTimer();
    connect(dirTimer, SIGNAL(timeout()), this, SLOT(changeDir()));
    dirTimer->start(3000);
}

Enemy::~Enemy()
{
    delete moveTimer;
    delete dirTimer;
}

void Enemy::Draw()
{
    setBrush(QBrush(Qt::red));
    setRect(getAxisX(),getAxisY(),getSize(),getSize());
    getS()->addItem(this);
}

void Enemy::Move()
{
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
    // 화면 밖으로 나가면 사망.
    if (getAxisX() < 0 || getAxisX() > 800 || getAxisY() < 0 || getAxisY() > 800)
    {
        scene()->removeItem(this);
        delete this;
    }
    // 크기가 0 이하가 되면 사망.
    if (getSize() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
    // 충돌 체크.
    QList<QGraphicsItem *> collided = collidingItems();
    for (int i=0; i<collided.size(); i++)
    {
        if( dynamic_cast<Bio*>(collided[i]) )
        {
            if( (*this) > ( dynamic_cast<Bio*>(collided[i]) ) )
            {
                (*this) + ( dynamic_cast<Bio*>(collided[i]) );
                scene()->removeItem(collided[i]);
                delete collided[i];
            }
            else if( (*dynamic_cast<Bio*>(collided[i])) > (this) )
            {
                scene()->removeItem(this);
                delete this;
            }
        }
    }
}

void Enemy::changeDir()
{
    int num = rand() % 4;
    switch (num) {
    case 0:
        direction = LEFT;
        break;
    case 1:
        direction = RIGHT;
        break;
    case 2:
        direction = UP;
        break;
    case 3:
        direction = DOWN;
        break;
    }
}

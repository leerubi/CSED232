#include "cell.h"

Cell::Cell() : Bio()
{

}

Cell::Cell(QGraphicsScene * s) : Bio(s)
{
    boost = false;
    velocity = CELL_VELOCITY;

    setSize(CELL_SIZE);
    setAxisX(WIDTH/2-CELL_SIZE/2);
    setAxisY(HEIGHT/2-CELL_SIZE/2);
    Draw();

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    moveTimer = new QTimer();
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(Move()));
    moveTimer->start(50);

    boostTimer = new QTimer();
    connect(boostTimer, SIGNAL(timeout()), this, SLOT(Boost()));
}

Cell::~Cell()
{
    delete moveTimer;
    delete boostTimer;
}

void Cell::Draw()
{
    setBrush(QBrush(Qt::blue));
    setRect(getAxisX(),getAxisY(),getSize(),getSize());
    getS()->addItem(this);
}

void Cell::Move()
{
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
        exit(0);
    }
    // 크기가 0 이하가 되면 사망.
    if (getSize() < 0)
    {
        scene()->removeItem(this);
        delete this;
        exit(0);
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
                exit(0);

            }
        }
    }
}

void Cell::Boost()
{
    setSize(getSize()*0.95);
}

void Cell::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
        direction = LEFT;
    else if (event->key() == Qt::Key_Right)
        direction = RIGHT;
    else if (event->key() == Qt::Key_Up)
        direction = UP;
    else if (event->key() == Qt::Key_Down)
        direction = DOWN;
    else if (event->key() == Qt::Key_Space)
    {
        boost = !boost;
        if (boost)  // booster on
        {
            velocity = velocity * 1.5;
            boostTimer->start(500);
        }
        else        // booster off
        {
            velocity = velocity / 1.5;
            boostTimer->stop();
        }
    }
}

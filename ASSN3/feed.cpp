#include "feed.h"

Feed::Feed() : Bio()
{

}

Feed::Feed(QGraphicsScene * s) : Bio(s)
{

    setSize(rand() % (FEED_MAX_SIZE-FEED_MIN_SIZE+1) + FEED_MIN_SIZE);
    setAxisX(rand() % (WIDTH+1));
    setAxisY(rand() % (HEIGHT+1));
    Draw();
}

Feed::~Feed()
{

}

void Feed::Draw()
{
    setBrush(QBrush(Qt::green));
    setRect(getAxisX(),getAxisY(),getSize(),getSize());
    getS()->addItem(this);
}

void Feed::Move()
{

}

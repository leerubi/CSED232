#ifndef FEED_H
#define FEED_H

#include <QObject>
#include <QGraphicsRectItem>
#include "bio.h"

class Feed : public QObject, public QGraphicsRectItem, public Bio
{
    Q_OBJECT
public:
    Feed();
    Feed(QGraphicsScene * s);
    ~Feed();
    void Draw();
    void Move();
};

#endif // FEED_H

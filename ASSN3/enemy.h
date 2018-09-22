#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include "bio.h"

class Enemy : public QObject, public QGraphicsEllipseItem, public Bio
{
    Q_OBJECT
private:
    enum Direction {LEFT, RIGHT, UP, DOWN};
    enum Direction direction;

    float velocity;

    QTimer * moveTimer;
    QTimer * dirTimer;
public slots:
    void Move();
    void changeDir();
public:
    Enemy();
    Enemy(QGraphicsScene * s);
    ~Enemy();

    void Draw();
};

#endif // ENEMY_H

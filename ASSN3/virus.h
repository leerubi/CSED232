#ifndef VIRUS_H
#define VIRUS_H

#include <QObject>
#include <QGraphicsRectItem>
#include "bio.h"

class Virus : public QObject, public QGraphicsRectItem, public Bio
{
    Q_OBJECT
private:
    enum Direction {LEFT, RIGHT, UP, DOWN};
    enum Direction direction;

    float velocity;
    int moveCnt;
    int sizeCnt;

    QTimer * moveTimer;
    QTimer * sizeTimer;
public slots:
    void Move();
    void Shrink();
public:
    Virus();
    Virus(QGraphicsScene * s);
    ~Virus();

    void Draw();
    void changeDir();
};

#endif // VIRUS_H

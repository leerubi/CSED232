#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include "bio.h"

class Cell : public QObject, public QGraphicsEllipseItem, public Bio
{
    Q_OBJECT
private:
    enum Direction {LEFT, RIGHT, UP, DOWN};
    enum Direction direction;

    bool boost;
    float velocity;

    QTimer * moveTimer;
    QTimer * boostTimer;
public slots:
    void Move();
    void Boost();
public:
    Cell();
    Cell(QGraphicsScene * s);
    ~Cell();

    void Draw();
    void keyPressEvent(QKeyEvent* event);
};

#endif // CELL_H

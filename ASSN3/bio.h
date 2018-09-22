#ifndef BIO_H
#define BIO_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QKeyEvent>
#include <QTimer>
#include <QList>

#define WIDTH 800
#define HEIGHT 800

#define CELL_VELOCITY 2     // 50ms 간격으로 2 이동
#define CELL_SIZE 20

#define ENEMY_VELOCITY 1    // 50ms 간격으로 2 이동
#define ENEMY_MIN_SIZE 10
#define ENEMY_MAX_SIZE 40

#define VIRUS_VELOCITY 20   // 1s 간격으로 20 이동
#define VIRUS_MIN_SIZE 15
#define VIRUS_MAX_SIZE 20

#define FEED_MIN_SIZE 7
#define FEED_MAX_SIZE 15

class Bio
{
private:
    float size;
    float axisX;
    float axisY;
    QGraphicsScene * s;
public:
    Bio();
    Bio(QGraphicsScene * s);
    void operator+(Bio* bio);
    bool operator>(Bio* bio);
    virtual void Draw();
    virtual void Move();
    float getSize();
    void setSize(float size);
    float getAxisX();
    void setAxisX(float axisX);
    float getAxisY();
    void setAxisY(float axiyY);
    QGraphicsScene * getS();
};

#endif // BIO_H

#include "bio.h"
#include "virus.h"

Bio::Bio()
{

}

Bio::Bio(QGraphicsScene * s)
{
    this->s = s;
}

bool Bio::operator>(Bio* bio)
{
    return (this->size > bio->size);
}

void Bio::operator+(Bio* bio)
{
    // 바이러스와 충돌한 경우 크기 감소
    if(dynamic_cast<Virus*>(bio))
        this->size -= bio->size*0.8;
    // 다른 생명체와 충돌한 경우 크기 증가
    else
        this->size += bio->size*0.8;
}

void Bio::Draw()
{

}

void Bio::Move()
{

}

float Bio::getSize()
{
    return this->size;
}

void Bio::setSize(float size)
{
    this->size = size;
}

float Bio::getAxisX()
{
    return this->axisX;
}

void Bio::setAxisX(float axisX)
{
    this->axisX = axisX;
}

float Bio::getAxisY()
{
    return this->axisY;
}

void Bio::setAxisY(float axisY)
{
    this->axisY = axisY;
}

QGraphicsScene * Bio::getS()
{
    return this->s;
}

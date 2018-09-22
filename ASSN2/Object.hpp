//
//  Object.hpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <iostream>

class Object {
private:
    int x, y;
    int boundX, boundY;
protected:
    void moveUp() {
        this->y = y - 1;
    }
    void moveDown() {
        this->y = y + 1;
    }
public:
    Object(){}
    Object(int startX, int startY) { this->x = startX; this->y = startY; }
    ~Object() {}
    void moveLeft() {
        this->x = x - 1;
    }
    void moveRight(){
        this->x = x + 1;
    }
    void move();
    char getShape();
    bool collide(Object* p) {
        if (this->x == p->getX() && this->y == p->getY()) return true;
        else return false;
    }
    int getX() { return x; }
    int getY() { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void set_boundX(int boundX) { this->boundX = boundX; }
    void set_boundY(int boundY) { this->boundY = boundY; }
};

#endif /* Object_hpp */

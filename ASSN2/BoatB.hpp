//
//  BoatB.hpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef BoatB_hpp
#define BoatB_hpp

#include <iostream>
#include "Boat.hpp"

class BoatB : public Boat {
    BoatB * next;
    double standardX, standardY;
public:
    BoatB(){}
    BoatB(int startX, int startY) : Boat(startX, startY) {
        next = NULL;
        standardX = startX + 0.5;
        standardY = startY + 0.5;
        int variationX = rand()%2;
        int variationY = rand()%2;
        setX(startX + variationX);
        setY(startY + variationY);
    }
    ~BoatB() {}
    BoatB * get_next() { return next; }
    void set_next(BoatB * next) { this->next = next; }
    void move();
    char getShape() { return 'B'; }
};

#endif /* BoatB_hpp */

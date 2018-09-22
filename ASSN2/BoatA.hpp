//
//  BoatA.hpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef BoatA_hpp
#define BoatA_hpp

#include <iostream>
#include "Boat.hpp"

class BoatA : public Boat {
    BoatA * next;
    int standardX;
    bool fromLeft;
public:
    BoatA(){}
    BoatA(int startX, int startY) : Boat(startX, startY) {
        next = NULL;
        standardX = startX;
        int variation = rand()%3 - 1;
        setX(startX + variation);
        int type = rand()%2;
        switch (type) {
            case 0: fromLeft = true;  break;
            case 1: fromLeft = false; break;
        }
    }
    ~BoatA() {}
    BoatA * get_next() { return next; }
    void set_next(BoatA * next) { this->next = next; }
    void move();
    char getShape() { return 'A'; }
};

#endif /* BoatA_hpp */

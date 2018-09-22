//
//  BoatC.hpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef BoatC_hpp
#define BoatC_hpp

#include <iostream>
#include "Boat.hpp"

class BoatC : public Boat {
    BoatC * next;
    int loopCnt;
    int variation;
public:
    BoatC(){}
    BoatC(int startX, int startY) : Boat(startX, startY) {
        next = NULL;
        variation = rand()%3;
    }
    ~BoatC() {}
    BoatC * get_next() { return next; }
    void set_next(BoatC * next) { this->next = next; }
    void set_loopCnt(int loopCnt) { this->loopCnt = loopCnt; }
    void move();
    char getShape() { return 'C'; }
};

#endif /* BoatC_hpp */

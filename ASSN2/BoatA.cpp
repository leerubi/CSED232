//
//  BoatA.cpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "BoatA.hpp"

void BoatA::move() {
    if (standardX > getX()) {
        moveRight();
        fromLeft = true;
    }
    else if (standardX < getX()) {
        moveLeft();
        fromLeft = false;
    }
    else if (standardX == getX()) {
        if (fromLeft)
            moveRight();
        else
            moveLeft();
    }
}

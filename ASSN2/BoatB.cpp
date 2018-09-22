//
//  BoatB.cpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "BoatB.hpp"

void BoatB::move() {
    if (getX() > standardX && getY() > standardY) moveLeft();
    else if (getX() < standardX && getY() > standardY) moveUp();
    else if (getX() > standardX && getY() < standardY) moveDown();
    else if (getX() < standardX && getY() < standardY) moveRight();
    
}

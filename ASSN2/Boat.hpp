//
//  Boat.hpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef Boat_hpp
#define Boat_hpp

#include <iostream>
#include "Object.hpp"
using namespace std;

class Boat : public Object {
private:
    bool hasShot;
    int crtX, crtY;
public:
    Boat(){}
    Boat(int startX, int startY) : Object(startX, startY) {}
    ~Boat() {}
    bool visibility();
    bool get_hasShot() { return hasShot; }
    void move();
    char getShape() { return 'U'; }
};

#endif /* Boat_hpp */

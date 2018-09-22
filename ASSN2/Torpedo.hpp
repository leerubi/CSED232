//
//  Torpedo.hpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef Torpedo_hpp
#define Torpedo_hpp

#include <iostream>
#include "Object.hpp"

class Torpedo : public Object {
public:
    Torpedo(){}
    Torpedo(int startX, int startY) : Object(startX, startY) {}
    ~Torpedo() {}
    void move();
    char getShape() { return 'T'; }
};

#endif /* Torpedo_hpp */

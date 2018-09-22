//
//  Edge.cpp
//  TEST
//
//  Created by ruby on 2017. 10. 13..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "Edge.hpp"

void Edge::add_mousse(string mousse){
    for (int i = 0; i < 3; i++) {
        if (this->mousse[i] == "") {
            this->mousse[i] = mousse;
            break;
        }
    }
}

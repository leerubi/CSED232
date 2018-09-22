//
//  BoatBList.cpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "BoatBList.hpp"
#include "BoatB.hpp"

void BoatBList::add(BoatB * new_BoatB){
    if (head == NULL) { // BoatB가 아직 없는 경우
        head = new_BoatB;
        size++;
    } else {
        BoatB * t = head;
        for (int i = 0; i < size - 1; i++)
            t = t->get_next();
        t->set_next(new_BoatB);
        size++;
    }
}


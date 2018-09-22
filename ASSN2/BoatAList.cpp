//
//  BoatAList.cpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "BoatAList.hpp"
#include "BoatA.hpp"

void BoatAList::add(BoatA * new_BoatA){
    if (head == NULL) { // BoatA가 아직 없는 경우
        head = new_BoatA;
        size++;
    } else {
        BoatA * t = head;
        for (int i = 0; i < size - 1; i++)
            t = t->get_next();
        t->set_next(new_BoatA);
        size++;
    }
}

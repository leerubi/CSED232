//
//  BoatCList.cpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "BoatCList.hpp"
#include "BoatC.hpp"

void BoatCList::add(BoatC * new_BoatC){
    if (head == NULL) { // BoatC가 아직 없는 경우
        head = new_BoatC;
        size++;
    } else {
        BoatC * t = head;
        for (int i = 0; i < size - 1; i++)
            t = t->get_next();
        t->set_next(new_BoatC);
        size++;
    }
}


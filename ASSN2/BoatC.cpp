//
//  BoatC.cpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "BoatC.hpp"

void BoatC::move() {
    // BoatC가 3번 중 1번은 잠수 혹은 밖으로 나옴
    if ((loopCnt+variation)%3 == 0)
        visibility();
}




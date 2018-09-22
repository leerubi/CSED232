//
//  main.cpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
#include "Object.hpp"
#include "Torpedo.hpp"
#include "BoatA.hpp"
#include "BoatB.hpp"
#include "BoatC.hpp"
#include "BoatAList.hpp"
#include "BoatBList.hpp"
#include "BoatCList.hpp"

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    while (true) {
        Game game;
        game.play_game();
        if (!game.get_again()) {
            game.delete_objects();
            break;
        }
    }
    return 0;
}

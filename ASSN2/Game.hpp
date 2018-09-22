//
//  Game.hpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
using namespace std;
class Boat;
class Torpedo;
class BoatAList;
class BoatBList;
class BoatCList;
class Game {
private:
    enum SCORE { TURN=500, TORPEDO=400, BOAT_A=100, BOAT_B=200, BOAT_C=300 };
    Boat* user;
    Boat* b_ptr[100];
    BoatAList* boatAList;
    BoatBList* boatBList;
    BoatCList* boatCList;
    Torpedo* t_ptr[300];
    int n_turn;
    int init_boat;
    int init_boatA;
    int init_boatB;
    int init_boatC;
    int init_torpedo;
    int n_boat;
    int n_boatA;
    int n_boatB;
    int n_boatC;
    int n_torpedo;
    int indexOfTorpedo;
    int score;
    int boundX;
    int boundY;
    bool again;
public:
    Game() {}
    bool isOverlapped();
    void checkHit();
    void show_initMenu();
    bool make_boats();
    void shot_torpedo();
    void show_result();
    void show_state();
    void play_game();
    bool get_again();
    void delete_objects();
};

#endif /* Game_hpp */

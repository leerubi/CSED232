//
//  BoatBList.hpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef BoatBList_hpp
#define BoatBList_hpp

#include <iostream>
using namespace std;

class BoatB;
class BoatBList{
    BoatB * head;
    int size;
public:
    // constructor
    BoatBList() {
        head = NULL;
        size = 0;
    }
    // get & set
    BoatB * get_head() {return head;}
    int get_size() {return size;};
    // method
    void add(BoatB * boatB);
};

#endif /* BoatBList_hpp */

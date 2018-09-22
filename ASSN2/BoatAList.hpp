//
//  BoatAList.hpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef BoatAList_hpp
#define BoatAList_hpp

#include <iostream>
using namespace std;

class BoatA;
class BoatAList{
    BoatA * head;
    int size;
public:
    // constructor
    BoatAList() {
        head = NULL;
        size = 0;
    }
    // get & set
    BoatA * get_head() {return head;}
    int get_size() {return size;};
    // method
    void add(BoatA * boatA);
};

#endif /* BoatAList_hpp */

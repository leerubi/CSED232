//
//  BoatCList.hpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef BoatCList_hpp
#define BoatCList_hpp

#include <iostream>
using namespace std;

class BoatC;
class BoatCList{
    BoatC * head;
    int size;
public:
    // constructor
    BoatCList() {
        head = NULL;
        size = 0;
    }
    // get & set
    BoatC * get_head() {return head;}
    int get_size() {return size;};
    // method
    void add(BoatC * BoatC);
};

#endif /* BoatCList_hpp */

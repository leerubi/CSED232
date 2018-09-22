//
//  DoughList.hpp
//  TEST
//
//  Created by ruby on 2017. 10. 14..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef DoughList_hpp
#define DoughList_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Dough;
class DoughList{
    Dough * head;
    int size;
public:
    // constructor
    DoughList() {
        head = NULL;
        size = 0;
    }
    // method
    void add(Dough * dough);
    void del(string name);
    Dough * pick(string name);
    void show_all_menu();
    void show_most_popular();
    void search_by_thick(float min_thick, float max_thick);
    // user defined method
    Dough * get_head() {return head;}
    int get_size() {return size;};
};

#endif /* DoughList_hpp */

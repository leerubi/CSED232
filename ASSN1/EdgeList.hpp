//
//  EdgeList.hpp
//  TEST
//
//  Created by ruby on 2017. 10. 14..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef EdgeList_hpp
#define EdgeList_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Edge;
class EdgeList{
    Edge * head;
    int size;
public:
    // constructor
    EdgeList() {
        head = NULL;
        size = 0;
    }
    // method
    void add(Edge * dough);
    void del(string name);
    Edge * pick(string name);
    void show_all_menu();
    void show_most_popular();
    void search_by_mousse(string mousse);
    // user defined method
    Edge * get_head() {return head;}
    int get_size() {return size;};
};

#endif /* EdgeList_hpp */

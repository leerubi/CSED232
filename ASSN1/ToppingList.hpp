//
//  ToppingList.hpp
//  TEST
//
//  Created by ruby on 2017. 10. 14..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef ToppingList_hpp
#define ToppingList_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Topping;
class ToppingList{
    Topping * head;
    int size;
public:
    // constructor
    ToppingList() {
        head = NULL;
        size = 0;
    }
    // method
    void add(Topping * topping);
    void del(string name);
    Topping * pick(string name);
    void show_all_menu();
    void show_most_popular();
    void search_by_ingred(string ingredient);
    void search_by_price(int min_price, int max_price);
    // user defined method
    Topping * get_head() {return this->head;}
    int get_size() {return size;};
};

#endif /* ToppingList_hpp */

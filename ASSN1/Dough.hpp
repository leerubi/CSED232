//
//  Dough.hpp
//  TEST
//
//  Created by ruby on 2017. 10. 13..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef Dough_hpp
#define Dough_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Dough{
    // node field
    Dough * next;
    // data field
    string name;
    float thickness;
    int extra_cost;
    int sell_count;
    string comment;
public:
    // constructor
    Dough(string name, float thickness, int extra_cost, string comment) {
        next = NULL;
        set_name(name);
        set_thickness(thickness);
        set_extra_cost(extra_cost);
        set_comment(comment);
        sell_count = 0;
     }
    // get method
    Dough * get_next() {return next;}
    string get_name() {return name;}
    float get_thickness() {return thickness;}
    int get_extra_cost() {return extra_cost;}
    int get_sell_count() {return sell_count;}
    string get_comment() {return comment;}
    // set method
    void set_next(Dough * next) {this->next = next;}
    void set_name(string name) {this->name = name;}
    void set_thickness(float thickness) {this->thickness = thickness;}
    void set_extra_cost(int extra_cost) {this->extra_cost = extra_cost;}
    void set_comment(string comment) {this->comment = comment;}
    // other method
    void inc_sellcount() {this->sell_count++;}
};

#endif /* Dough_hpp */


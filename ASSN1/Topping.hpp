//
//  Topping.hpp
//  TEST
//
//  Created by ruby on 2017. 10. 13..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef Topping_hpp
#define Topping_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Topping{
    // node field
    Topping * next;
    // data field
    string name;
    string ingredient[10];
    int price;
    int sell_count;
    string comment;
public:
    // constructor
    Topping(string name, string ingredient_all, int price, string comment) {
        next = NULL;
        set_name(name);
        set_price(price);
        set_comment(comment);
        sell_count = 0;
        
        int add_count = 0;
        int start_index = 0;
        int found_index = 0;
        for (int i = 0; i < ingredient_all.length(); i++) {
            if (ingredient_all[i] == ',') {
                found_index = i;
                add_ingredient(ingredient_all.substr(start_index, found_index-start_index)); add_count++;
                start_index = found_index + 1;
            }
        }
        add_ingredient(ingredient_all.substr(start_index, ingredient_all.length() - start_index)); add_count++;    // 마지막 ingredient 추가
        if (add_count > 10)
            cout << "입력받은 재료는 10개까지만 추가됩니다." << endl;
    }
    // get method
    Topping * get_next() {return next;}
    string get_name() {return name;}
    string* get_ingredient() {return ingredient;}
    int get_price() {return price;}
    int get_sell_count() {return sell_count;}
    string get_comment() {return comment;}
    // set method
    void set_next(Topping * next) {this->next = next;}
    void set_name(string name) {this->name = name;}
    void set_price(int price) {this->price = price;}
    void set_comment(string comment) {this->comment = comment;}
    // other method
    void add_ingredient(string ingredient);
    void inc_sellcount() {this->sell_count++;}
};

#endif /* Topping_hpp */

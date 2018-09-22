//
//  Edge.hpp
//  TEST
//
//  Created by ruby on 2017. 10. 13..
//  Copyright © 2017년 ruby. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Edge {
    // node field
    Edge * next;
    // data field
    string name;
    string mousse[3];
    int extra_cost;
    int sell_count;
    string comment;
public:
    // constructor
    Edge(string name, string mousse_all, int extra_cost, string comment) {
        next = NULL;
        set_name(name);
        set_extra_cost(extra_cost);
        set_comment(comment);
        sell_count = 0;
    
        int add_count = 0;
        if (mousse_all != " "){
            int start_index = 0;
            int found_index = 0;
            for (int i = 0; i < mousse_all.length(); i++) {
                if (mousse_all[i] == ',') {
                    found_index = i;
                    add_mousse(mousse_all.substr(start_index, found_index-start_index)); add_count++;
                    start_index = found_index + 1;
                }
            }
            add_mousse(mousse_all.substr(start_index, mousse_all.length() - start_index)); add_count++;   // 마지막 mousse 추가
        }
        if (add_count > 3)
            cout << "입력받은 무스는 3개까지만 추가됩니다." << endl;
    }
    // get method
    Edge * get_next() {return next;}
    string get_name() {return name;}
    string* get_mousse() {return mousse;}
    int get_extra_cost() {return extra_cost;}
    int get_sell_count() {return sell_count;}
    string get_comment() {return comment;}
    // set method
    void set_next(Edge * next) {this->next = next;}
    void set_name(string name) {this->name = name;}
    void add_mousse(string mousse);
    void set_extra_cost(int extra_cost) {this->extra_cost = extra_cost;}
    void inc_sellcount() {this->sell_count++;}
    void set_comment(string comment) {this->comment = comment;}
};

#endif /* Edge_hpp */

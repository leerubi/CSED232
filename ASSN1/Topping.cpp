//
//  Topping.cpp
//  TEST
//
//  Created by ruby on 2017. 10. 13..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "Topping.hpp"

void Topping::add_ingredient(string ingredient){
    for (int i = 0; i < 10; i++) {
        if (this->ingredient[i] == "") {
            this->ingredient[i] = ingredient;
            break;
        }
    }
}

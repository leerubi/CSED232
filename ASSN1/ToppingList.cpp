//
//  ToppingList.cpp
//  TEST
//
//  Created by ruby on 2017. 10. 14..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "ToppingList.hpp"
#include "Topping.hpp"


void ToppingList::add(Topping * new_topping){
    if (head == NULL) { // Topping가 아직 없는 경우
        head = new_topping;
        size++;
    } else {
        Topping * t = head;
        for (int i = 0; i < size - 1; i++)
            t = t->get_next();
        t->set_next(new_topping);
        size++;
    }
}

void ToppingList::del(string name){
    if (head == NULL) { // Topping이 아직 없는 경우
        return;
    }
    Topping * pre = head;
    Topping * crt = head;
    for (int i = 0; i < size ; i++) {
        if (name.compare(crt->get_name()) == 0) {
            if (crt == head)                     // 첫번째 Topping을 삭제하는 경우
                head = crt->get_next();
            else if (crt->get_next() == NULL)    // 마지막 Topping을 삭제하는 경우
                pre->set_next(NULL);
            else
                pre->set_next(crt->get_next());
            delete crt;
            size--;
            return;
        }
        pre = crt;
        crt = crt->get_next();
    }
    cout << "일치하는 Topping가 없습니다." << endl;
}

Topping * ToppingList::pick(string name){
    if (head == NULL) { // Topping이 아직 없는 경우
        cout << "아직 Topping이 없습니다." << endl;
        return NULL;
    }
    Topping * t = head;
    for (int i = 0; i < size; i++) {
        if (name.compare(t->get_name()) == 0)
            return t;
        t = t->get_next();
    }
    cout << "일치하는 Topping이 없습니다." << endl;
    return NULL;
}

void ToppingList::show_all_menu(){
    if (head == NULL) {
        cout << "Topping이 없습니다." << endl;
        return;
    }
    Topping * t = head;
    for (int i = 0; i < size ; i++) {
        cout<< "[이름:" << t->get_name() <<"]"
        << "[재료:";
        for (int j = 0; j < 10; j++) {
            if (*(t->get_ingredient()+j) == "")
                break;
            if (j != 0) cout << ",";
            cout << *(t->get_ingredient()+j);
        }
        cout << "]"
        << "[가격:" << t->get_price() << "원]"
        << "[소개말:" << t->get_comment() << "]" << endl;
        t = t->get_next();
    }
}

void ToppingList::show_most_popular(){
    Topping * tempPtr = this->head;
    Topping * highPtr = this->head;
    for (int i = 0; i < size-1; i++) {
        if (tempPtr->get_sell_count() < (tempPtr->get_next())->get_sell_count())
            highPtr = tempPtr->get_next();
        tempPtr = tempPtr->get_next();
    }
    
    cout << "-TOPPING 인기메뉴" << endl;
    if (head == NULL) {
        cout << "아직 Topping이 없습니다." << endl;
        return;
    }
    if (highPtr->get_sell_count() == 0) {
        cout << "주문 내역이 없습니다." << endl;
        return;
    }
    cout<< "[이름:" << highPtr->get_name() <<"]"
    << "[재료:";
    for (int j = 0; j < 10; j++) {
        if (*(highPtr->get_ingredient()+j) == "")
            break;
        if (j != 0) cout << ",";
        cout << *(highPtr->get_ingredient()+j);
    }
    cout << "]"
    << "[가격:" << highPtr->get_price() << "원]"
    << "[소개말:" << highPtr->get_comment() << "]" << endl;
}

void ToppingList::search_by_ingred(string ingredient){
    ToppingList tempList;
    Topping * tempPtr = this->head;
    for (int i = 0; i < this->size; i++) {
        int j = 0;
        while (*(tempPtr->get_ingredient()+j) != "") {
            if (*(tempPtr->get_ingredient()+j) == ingredient) {
                tempList.add(tempPtr);
                break;
            }
            j++;
        }
        tempPtr = tempPtr->get_next();
    }
    tempList.show_all_menu();
    cout << "이상 총 " << tempList.size << "개가 검색되었습니다." << endl;
}

void ToppingList::search_by_price(int min_price, int max_price){
    ToppingList tempList;
    Topping * tempPtr = this->head;
    while (true) {
        if(tempPtr->get_price() >= min_price && tempPtr->get_price() <= max_price)
            tempList.add(tempPtr);
        tempPtr = tempPtr->get_next();
        if(tempPtr == NULL)
            break;
    }
    tempList.show_all_menu();
    cout << "이상 총 " << tempList.size << "개가 검색되었습니다." << endl;
}

//
//  DoughList.cpp
//  TEST
//
//  Created by ruby on 2017. 10. 14..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "DoughList.hpp"
#include "Dough.hpp"

void DoughList::add(Dough * new_dough){
    if (head == NULL) { // Dough가 아직 없는 경우
        head = new_dough;
        size++;
    } else {
        Dough * t = head;
        for (int i = 0; i < size - 1; i++)
            t = t->get_next();
        t->set_next(new_dough);
        size++;
    }
}

void DoughList::del(string name){
    if (head == NULL) { // Dough가 아직 없는 경우
        return;
    }
    Dough * pre = head;
    Dough * crt = head;
    for (int i = 0; i < size ; i++) {
        if (name.compare(crt->get_name()) == 0) {
            if (crt == head)                     // 첫번째 Dough을 삭제하는 경우
                head = crt->get_next();
            else if (crt->get_next() == NULL)    // 마지막 Dough을 삭제하는 경우
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
    cout << "일치하는 Dough가 없습니다." << endl;
}

Dough * DoughList::pick(string name){
    if (head == NULL) { // Dough가 아직 없는 경우
        cout << "아직 Dough가 없습니다." << endl;
        return NULL;
    }
    Dough * t = head;
    for (int i = 0; i < size; i++) {
        if (name.compare(t->get_name()) == 0)
            return t;
        t = t->get_next();
    }
    cout << "일치하는 Dough가 없습니다." << endl;
    return NULL;
}

void DoughList::show_all_menu(){
    if (head == NULL) {
        cout << "Dough가 없습니다." << endl;
        return;
    }
    Dough * t = head;
    for (int i = 0; i < size ; i++) {
        cout<< "[이름:" << t->get_name() <<"]"
        << "[두께:" << t->get_thickness() << "mm]"
        << "[추가비용:" << t->get_extra_cost() << "원]"
        << "[소개말:" << t->get_comment() << "]" << endl;
        t = t->get_next();
    }
}

void DoughList::show_most_popular(){
    Dough * tempPtr = this->head;
    Dough * highPtr = this->head;
    for (int i = 0; i < size-1; i++) {
        if (tempPtr->get_sell_count() < (tempPtr->get_next())->get_sell_count())
            highPtr = tempPtr->get_next();
        tempPtr = tempPtr->get_next();
    }
    
    cout << "-DOUGH 인기메뉴" << endl;
    if (head == NULL) {
        cout << "아직 Dough가 없습니다." << endl;
        return;
    }
    if (highPtr->get_sell_count() == 0) {
        cout << "주문 내역이 없습니다." << endl;
        return;
    }
    cout<< "[이름:" << highPtr->get_name() <<"]"
    << "[두께:" << highPtr->get_thickness() << "mm]"
    << "[추가비용:" << highPtr->get_extra_cost() << "원]"
    << "[소개말:" << highPtr->get_comment() << "]" << endl;
}

void DoughList::search_by_thick(float min_thick, float max_thick){
    DoughList tempList;
    Dough * tempPtr = this->head;
    while (true) {
        if(tempPtr->get_thickness() >= min_thick && tempPtr->get_thickness() <= max_thick)
            tempList.add(tempPtr);
        tempPtr = tempPtr->get_next();
        if(tempPtr == NULL)
            break;
    }
    tempList.show_all_menu();
    cout << "이상 총 " << tempList.size << "개가 검색되었습니다." << endl;
}

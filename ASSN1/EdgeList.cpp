//
//  EdgeList.cpp
//  TEST
//
//  Created by ruby on 2017. 10. 14..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "EdgeList.hpp"
#include "Edge.hpp"

void EdgeList::add(Edge * new_edge){
    if (head == NULL) { // Edge가 아직 없는 경우
        head = new_edge;
        size++;
    } else {
        Edge * t = head;
        for (int i = 0; i < size - 1; i++)
            t = t->get_next();
        t->set_next(new_edge);
        size++;
    }
}

void EdgeList::del(string name){
    if (head == NULL) { // Edge가 아직 없는 경우
        return;
    }
    Edge * pre = head;
    Edge * crt = head;
    for (int i = 0; i < size ; i++) {
        if (name.compare(crt->get_name()) == 0) {
            if (crt == head)                     // 첫번째 Edge을 삭제하는 경우
                head = crt->get_next();
            else if (crt->get_next() == NULL)    // 마지막 Edge을 삭제하는 경우
                pre->set_next(NULL);
            else
                pre->set_next(crt->get_next());
            delete crt;
            size--;
            return;
        }
        pre = crt;
        crt = crt->get_next();
    }    cout << "일치하는 Edge가 없습니다." << endl;
}

Edge * EdgeList::pick(string name){
    if (head == NULL) { // Edge가 아직 없는 경우
        cout << "아직 Edge가 없습니다." << endl;
        return NULL;
    }
    Edge * t = head;
    for (int i = 0; i < size; i++) {
        if (name.compare(t->get_name()) == 0)
            return t;
        t = t->get_next();
    }
    cout << "일치하는 Edge가 없습니다." << endl;
    return NULL;
}

void EdgeList::show_all_menu(){
    if (head == NULL) {
        cout << "Edge가 없습니다." << endl;
        return;
    }
    Edge * t = head;
    for (int i = 0; i < size ; i++) {
        cout<< "[이름:" << t->get_name() <<"]"
        << "[무스:";
        for (int j = 0; j < 3; j++) {
            if (*(t->get_mousse()+j) == "" || *(t->get_mousse()+j) == " ")
                break;
            if (j != 0) cout << ",";
            cout << *(t->get_mousse()+j);
        }
        cout << "]"
        << "[추가비용:" << t->get_extra_cost() << "원]"
        << "[소개말:" << t->get_comment() << "]" << endl;
        t = t->get_next();
    }
}

void EdgeList::show_most_popular(){
    Edge * tempPtr = this->head;
    Edge * highPtr = this->head;
    for (int i = 0; i < size-1; i++) {
        if (tempPtr->get_sell_count() < (tempPtr->get_next())->get_sell_count())
            highPtr = tempPtr->get_next();
        tempPtr = tempPtr->get_next();
    }
    
    cout << "-EDGE 인기메뉴" << endl;
    if (head == NULL) {
        cout << "아직 Edge가 없습니다." << endl;
        return;
    }
    if (highPtr->get_sell_count() == 0) {
        cout << "주문 내역이 없습니다." << endl;
        return;
    }
    cout<< "[이름:" << highPtr->get_name() <<"]"
    << "[무스:";
    for (int j = 0; j < 10; j++) {
        if (*(highPtr->get_mousse()+j) == "" || *(highPtr->get_mousse()+j) == " ")
            break;
        if (j != 0) cout << ",";
        cout << *(highPtr->get_mousse()+j);
    }
    cout << "]"
    << "[추가비용:" << highPtr->get_extra_cost() << "원]"
    << "[소개말:" << highPtr->get_comment() << "]" << endl;
}
void EdgeList::search_by_mousse(string mousse){
    EdgeList tempList;
    Edge * tempPtr = this->head;
    for (int i = 0; i < this->size; i++) {
        int j = 0;
        while (*(tempPtr->get_mousse()+j) != "" || *(tempPtr->get_mousse()+j) == " ") {
            if (*(tempPtr->get_mousse()+j) == mousse) {
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

//
//  main.cpp
//  TEST
//
//  Created by ruby on 2017. 10. 13..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "ToppingList.hpp"
#include "DoughList.hpp"
#include "EdgeList.hpp"
#include "Topping.hpp"
#include "Dough.hpp"
#include "Edge.hpp"
using namespace std;
bool readInput(string inputName, ToppingList * toppingList, DoughList * doughList, EdgeList * edgeList);

int main(int argc, const char * argv[]) {
    ToppingList toppingList;
    DoughList doughList;
    EdgeList edgeList;
    
    string inputName = argv[1];
    if(!readInput(inputName, &toppingList, &doughList, &edgeList))
        return -1;
    
    while (true) {
        // 메인 메뉴 출력
        cout << "==============" << endl
        << "0: 모든 메뉴 보기" << endl
        << "1: 주문하기" << endl
        << "2: 메뉴 추가" << endl
        << "3: 메뉴 삭제" << endl
        << "4: 메뉴 검색" << endl
        << "5: 인기메뉴 추천" << endl
        << "6: 프로그램 종료" << endl
        << "==============" << endl
        << ">> ";
        int inputNum; cin >> inputNum;
        if (inputNum == 6) {
            // 프로그램을 종료하기 전 동적 할당받은 메모리 반환하기 위해 모든 메뉴를 삭제
//            Topping * tempT = toppingList.get_head();
//            Dough * tempD = doughList.get_head();
//            Edge * tempE = edgeList.get_head();
            for (int i = 0; i < toppingList.get_size(); i++) {
                toppingList.del((toppingList.get_head())->get_name());
            }
            for (int i = 0; i < doughList.get_size(); i++) {
                doughList.del((doughList.get_head())->get_name());
            }
            for (int i = 0; i < edgeList.get_size(); i++) {
                edgeList.del((edgeList.get_head())->get_name());
            }
//            while (true) {
//                doughList.del(tempD->get_name());
//                if (tempD->get_next() == NULL) {    // 리스트의 마지막 객체인 경우
//                    doughList.del(tempD->get_name());
//                    break;
//                }
//                tempD = tempD->get_next();
//            }
//            while (true) {
//                edgeList.del(tempE->get_name());
//                if (tempE->get_next() == NULL) {    // 리스트의 마지막 객체인 경우
//                    edgeList.del(tempE->get_name());
//                    break;
//                }
//                tempE = tempE->get_next();
//            }
            cout << "프로그램을 종료합니다..." << endl;
            break;
        }
        switch (inputNum) {
            case 0: {   // 모든 메뉴 보기
                cout << "-TOPPING <" << toppingList.get_size() << ">" << endl;
                toppingList.show_all_menu();
                cout << "-DOUGH <" << doughList.get_size() << ">" << endl;
                doughList.show_all_menu();
                cout << "-EDGE <" << edgeList.get_size() << ">" << endl;
                edgeList.show_all_menu();
                break;
            }
            case 1: {   // 주문 하기
                // Topping 선택
                cout << "-TOPPING <" << toppingList.get_size() << ">" << endl;
                toppingList.show_all_menu();
                cout << endl << "원하시는 토핑 이름을 입력하세요." << endl << ">> ";
                string toppingName; cin >> toppingName;
                toppingList.pick(toppingName)->inc_sellcount();
                // Dough 선택
                cout << "-DOUGH <" << doughList.get_size() << ">" << endl;
                doughList.show_all_menu();
                cout << endl << "원하시는 도우 이름을 입력하세요." << endl << ">> ";
                string doughName; cin >> doughName;
                doughList.pick(doughName)->inc_sellcount();
                // Edge 선택
                cout << "-EDGE <" << edgeList.get_size() << ">" << endl;
                edgeList.show_all_menu();
                cout << endl << "원하시는 에지 이름을 입력하세요." << endl << ">> ";
                string edgeName; cin >> edgeName;
                edgeList.pick(edgeName)->inc_sellcount();
                // 주문 결과 출력
                cout << endl << "주문하신 피자는 \""
                << doughName << " " << edgeName << " " << toppingName
                << "\" 입니다." << endl;
                cout << "가격은 \""
                << doughList.pick(doughName)->get_extra_cost()
                + edgeList.pick(edgeName)->get_extra_cost()
                + toppingList.pick(toppingName)->get_price()
                << "\"원 입니다." << endl;
                break;
            }
            case 2: {   // 메뉴 추가
                cout << "추가하고자 하는 메뉴의 종류를 선택하세요." << endl
                << "1: 토핑" << endl
                << "2: 도우" << endl
                << "3: 에지" << endl << ">> ";
                int inputAddNum; cin >> inputAddNum;
                
                string name, ingredient_all, mousse_all, comment, dummy;
                float thickness;
                int price, extra_cost;
                switch (inputAddNum) {
                    case 1: // 토핑 추가
                        cout << "이름" << endl << ">> "; cin >> name;
                        cout << "재료" << endl << ">> "; cin >> ingredient_all;
                        cout << "가격" << endl << ">> "; cin >> price;
                        cout << "소개말" << endl << ">> "; getline(cin, dummy); getline(cin, comment);
                        toppingList.add(new Topping(name, ingredient_all, price, comment));
                        cout << "메뉴 추가가 완료되었습니다." << endl << endl;
                        cout << "-TOPPING <" << toppingList.get_size() << ">" << endl;
                        toppingList.show_all_menu();
                        break;
                    case 2: // 도우 추가
                        cout << "이름" << endl << ">> "; cin >> name;
                        cout << "두께" << endl << ">> "; cin >> thickness;
                        cout << "추가비용" << endl << ">> "; cin >> extra_cost;
                        cout << "소개말" << endl << ">> "; getline(cin, dummy); getline(cin, comment);
                        doughList.add(new Dough(name, thickness, extra_cost, comment));
                        cout << "메뉴 추가가 완료되었습니다." << endl << endl;
                        cout << "-DOUGH <" << doughList.get_size() << ">" << endl;
                        doughList.show_all_menu();
                        break;
                    case 3: // 에지 추가
                        cout << "이름" << endl << ">> "; cin >> name;
                        cout << "무스" << endl << ">> "; getline(cin, dummy); getline(cin, mousse_all);
                        cout << "추가비용" << endl << ">> "; cin >> extra_cost;
                        cout << "소개말" << endl << ">> "; getline(cin, dummy); getline(cin, comment);
                        edgeList.add(new Edge(name, mousse_all, extra_cost, comment));
                        cout << "메뉴 추가가 완료되었습니다." << endl << endl;
                        cout << "-EDGE <" << edgeList.get_size() << ">" << endl;
                        edgeList.show_all_menu();
                        break;
                    default:
                        cout << "1~3 값을 입력하지 않았습니다. 메인화면으로 돌아갑니다." << endl;
                }
                break;
            }
            case 3: {   // 메뉴 삭제
                cout << "삭제하고자 하는 메뉴의 종류를 선택하세요." << endl
                << "1: 토핑" << endl
                << "2: 도우" << endl
                << "3: 에지" << endl << ">> ";
                int inputDelNum; cin >> inputDelNum;
                
                string inputDelName;
                switch (inputDelNum) {
                    case 1: // 토핑 삭제
                        toppingList.show_all_menu();
                        cout << "삭제하고자 하는 메뉴 이름을 입력하세요." << endl << ">> ";
                        cin >> inputDelName;
                        toppingList.del(inputDelName);
                        cout << "메뉴 삭제가 완료되었습니다." << endl << endl;
                        cout << "-TOPPING <" << toppingList.get_size() << ">" << endl;
                        toppingList.show_all_menu();
                        break;
                    case 2: // 도우 삭제
                        doughList.show_all_menu();
                        cout << "삭제하고자 하는 메뉴 이름을 입력하세요." << endl << ">> ";
                        cin >> inputDelName;
                        doughList.del(inputDelName);
                        cout << "메뉴 삭제가 완료되었습니다." << endl << endl;
                        cout << "-DOUGH <" << doughList.get_size() << ">" << endl;
                        doughList.show_all_menu();
                        break;
                    case 3: // 에지 삭제
                        edgeList.show_all_menu();
                        cout << "삭제하고자 하는 메뉴 이름을 입력하세요." << endl << ">> ";
                        cin >> inputDelName;
                        edgeList.del(inputDelName);
                        cout << "메뉴 삭제가 완료되었습니다." << endl << endl;
                        cout << "-EDGE <" << edgeList.get_size() << ">" << endl;
                        edgeList.show_all_menu();
                        break;
                    default:
                        cout << "1~3 값을 입력하지 않았습니다. 메인화면으로 돌아갑니다." << endl;
                }
                break;
            }
            case 4: {   // 메뉴 검색
                cout << "검색하고자 하는 메뉴의 종류를 선택하세요." << endl
                << "1: 토핑" << endl
                << "2: 도우" << endl
                << "3: 에지" << endl << ">> ";
                int inputSearchNum; cin >> inputSearchNum;
                
                int inputSearchBy;
                switch (inputSearchNum) {
                    case 1: // 토핑 검색
                        cout << "검색 기준을 선택하세요." << endl
                        << "1: 재료로 검색" << endl
                        << "2: 가격으로 검색" << endl << ">> ";
                        cin >> inputSearchBy;
                        
                        switch (inputSearchBy) {
                            case 1: {   // 재료 이름으로 검색
                                cout << "재료 이름을 입력해주세요." << endl << ">> ";
                                string ingredient; cin >> ingredient;
                                toppingList.search_by_ingred(ingredient);
                                break;
                            }
                            case 2: {   // 가격 범위로 검색
                                cout << "가격 범위 중 하한을 입력해주세요." << endl << ">> ";
                                int min_price; cin >> min_price;
                                cout << "가격 범위 중 상한을 입력해주세요." << endl << ">> ";
                                int max_price; cin >> max_price;
                                toppingList.search_by_price(min_price, max_price);
                                break;
                            }
                            default:
                                cout << "1~2 값을 입력하지 않았습니다. 메인화면으로 돌아갑니다." << endl;
                        }
                        break;
                    case 2: // 도우 검색
                        cout << "검색 기준을 선택하세요." << endl
                        << "1: 두께로 검색" << endl << ">> ";
                        cin >> inputSearchBy;
                        
                        switch (inputSearchBy) {
                            case 1: {   // 두께 범위로 검색
                                cout << "두께 범위 중 하한을 입력해주세요." << endl << ">> ";
                                float min_thick; cin >> min_thick;
                                cout << "두께 범위 중 상한을 입력해주세요." << endl << ">> ";
                                float max_thick; cin >> max_thick;
                                doughList.search_by_thick(min_thick, max_thick);
                                break;
                            }
                            default:
                                cout << "1 값을 입력하지 않았습니다. 메인화면으로 돌아갑니다." << endl;
                        }
                        break;
                    case 3: // 에지 검색
                        cout << "검색 기준을 선택하세요." << endl
                        << "1: 무스로 검색" << endl << ">> ";
                        cin >> inputSearchBy;
                        
                        switch (inputSearchBy) {
                            case 1: {   // 재료 이름으로 검색
                                cout << "무스 이름을 입력해주세요." << endl << ">> ";
                                string mousse; cin >> mousse;
                                edgeList.search_by_mousse(mousse);
                                break;
                            }
                            break;
                        }
                        break;
                    default:
                        cout << "1~3 값을 입력하지 않았습니다. 메인화면으로 돌아갑니다." << endl;
                }
                break;
            }
            case 5: {   // 인기메뉴 추천
                toppingList.show_most_popular();
                doughList.show_most_popular();
                edgeList.show_most_popular();
                break;
            }
            default: {
                cout << "0~6 값을 입력하지 않았습니다. 메인화면으로 돌아갑니다." << endl;
            }
        }
    }
    return 0;
    
}

bool readInput(string inputName, ToppingList * toppingList, DoughList * doughList, EdgeList * edgeList){
    // 텍스트 파일 읽어서 리스트에 객체 생성 및 리스트에 추가
    ifstream fin(inputName);
    if ( !fin.is_open() ) { // 파일 오픈 실패 시 오류 메시지 출력하고 프로그램 종료
        cout << inputName << " 이 열리지 않음" << endl;
        return false;
    }
    
    string name, ingredient_all, mousse_all, _price, _thickness, _extra_cost, comment, dummy;
    float thickness;
    int price, extra_cost;
    
    while ( !fin.eof() ) {
        getline(fin, dummy);
        int i = 3;
        while (i-- > 0) {
            // Topping 객체 생성 및 ToppingList에 추가
            getline(fin, name, '\t');            // name 임시 저장
            getline(fin, ingredient_all, '\t');  // 모든 ingredient 임시 저장
            getline(fin, _price, '\t');
            price = stoi(_price);                // price 임시 저장
            getline(fin, comment, '\r');         // comment 임시 저장
            getline(fin, dummy, '\n');
            toppingList->add(new Topping(name, ingredient_all, price, comment));
        }
        getline(fin, dummy);
        int j = 3;
        while (j-- > 0) {
            // Dough 객체 생성 및 DoughList에 추가
            getline(fin, name, '\t');            // name 임시 저장
            getline(fin, _thickness, '\t');
            thickness = stof(_thickness);        // thickness 임시 저장
            getline(fin, _extra_cost, '\t');
            extra_cost = stoi(_extra_cost);      // extra_cost 임시 저장
            getline(fin, comment, '\r');         // comment 임시 저장
            getline(fin, dummy, '\n');
            doughList->add(new Dough(name, thickness, extra_cost, comment));
        }
        getline(fin, dummy);
        int k = 4;
        while (k-- > 0) {
            // Edge 객체 생성 및 EdgeList에 추가
            getline(fin, name, '\t');            // name 임시 저장
            if (name == "")
                break;
            getline(fin, mousse_all, '\t');      // 모든 mousse 임시 저장
            getline(fin, _extra_cost, '\t');
            extra_cost = stoi(_extra_cost);      // extra_cost 임시 저장
            getline(fin, comment, '\r');         // comment 임시 저장
            getline(fin, dummy, '\n');
            edgeList->add(new Edge(name, mousse_all, extra_cost, comment));
        }
        break;
    }
    fin.close();
    return true;
}


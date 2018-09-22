//
//  Game.cpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "Game.hpp"
#include "Boat.hpp"
#include "BoatA.hpp"
#include "BoatB.hpp"
#include "BoatC.hpp"
#include "BoatAList.hpp"
#include "BoatBList.hpp"
#include "BoatCList.hpp"
#include "Torpedo.hpp"

// user와 보트들 생성, torpedo 기본 세팅
bool Game::make_boats() {  
    user = new Boat(boundX/2, boundY-1);
    boatAList = new BoatAList();
    boatBList = new BoatBList();
    boatCList = new BoatCList();
    init_torpedo = n_torpedo;
    indexOfTorpedo = -1;
    // BoatA, BoatB, BoatC의 개수 설정
    init_boat = n_boat;
    init_boatA = rand() % (n_boat+1);
    init_boatB = rand() % (n_boat-init_boatA+1);
    init_boatC = n_boat-init_boatA-init_boatB;
    n_boatA = init_boatA;
    n_boatB = init_boatB;
    n_boatC = init_boatC;
    // BoatA, BoatB, BoatC 생성
    for (int i = 0; i < init_boatA; i++)
        boatAList->add(new BoatA(rand() % (boundX-2) + 1, rand() % (boundY-1)));
    for (int i = 0; i < init_boatB; i++)
        boatBList->add(new BoatB(rand() % (boundX-1), rand() % (boundY-2)));
    for (int i = 0; i < init_boatC; i++)
        boatCList->add(new BoatC(rand() % boundX, rand() % (boundY-1)));
    // BoatA, BoatB, BoatC를 모두 Boat 타입 포인터 변수에 저장
    BoatA * boatA = boatAList->get_head();
    for (int i = 0; i < init_boatA; i++) {
        b_ptr[i]= boatA;
        boatA = boatA->get_next();
    }
    BoatB * boatB = boatBList->get_head();
    for (int i = 0; i < init_boatB; i++) {
        b_ptr[init_boatA+i] = boatB;
        boatB = boatB->get_next();
    }
    BoatC * boatC = boatCList->get_head();;
    for (int i = 0; i < init_boatC; i++) {
        b_ptr[init_boatA+init_boatB+i] = boatC;
        boatC = boatC->get_next();
    }
    // 보트끼리 겹치는지 확인
    if (!isOverlapped())
        return true;
    else
        return false;
}
// user가 어뢰를 쏨
void Game::shot_torpedo() {
    t_ptr[++indexOfTorpedo] = new Torpedo(user->getX(), user->getY());
    n_torpedo--;
}
// 보트끼리 겹치는지 확인
bool Game::isOverlapped() {
    // n_turn번 안에 Boat끼리 충돌하면 true 반환
    int loopCnt = 0;
    for(int cnt = 0; cnt < n_turn; cnt++) {
        for (int i = 0; i < n_boat; i++) {
            for (int j = i+1; j < n_boat; j++) {
                if(b_ptr[i]->collide(b_ptr[j]))
                    return true;
            }
        }
        // BoatA 움직임
        BoatA* boatA = boatAList->get_head();
        for (int i = 0; i < boatAList->get_size(); i++) {
            boatA->move();
            boatA = boatA->get_next();
        }
        // BoatB 움직임
        BoatB* boatB = boatBList->get_head();
        for (int i = 0; i < boatBList->get_size(); i++) {
            boatB->move();
            boatB = boatB->get_next();
        }
        // BoatC 움직임
        BoatC* boatC = boatCList->get_head();
        for (int i = 0; i < boatCList->get_size(); i++) {
            boatC->set_loopCnt(++loopCnt);
            boatC->move();
            boatC = boatC->get_next();
        }
    }
    return false;
}
// Boat가 Torpedo에 맞았는지 검사하고 처리
void Game::checkHit() {
    for (int i = 0; i < init_boat; i++) {
        for (int j = 0; j <= indexOfTorpedo; j++) {
            if(b_ptr[i]->collide(t_ptr[j])) {
                b_ptr[i]->setX(-200); b_ptr[i]->setY(-200);
                n_boat--;
                if (i < init_boat)
                    n_boatA--;
                else if (i < init_boatA+init_boatB)
                    n_boatB--;
                else
                    n_boatC--;
                t_ptr[j]->setX(-100); t_ptr[j]->setY(-100);
            }
        }
    }
}
// 메인 메뉴 출력 및 기본 값 설정
void Game::show_initMenu() {
    cout << "==========================" << endl
    << "welcome to torpedo game!" << endl << endl
    << "1. start default game!" << endl
    << "2. start custom game!" << endl << endl
    << "else. quit" << endl
    << "==========================" << endl << endl
    << "your command : ";
    int type; cin >> type;
    switch (type) {
        case 1:
            boundX = 5;
            boundY = 10;
            n_boat = 5;
            break;
        case 2:
            cout << "X Axis : "; cin >> boundX;
            cout << "Y Axis : "; cin >> boundY;
            cout << "Boats : "; cin >> n_boat;
            break;
        default:
            n_boat = -1;
            break;
    }
    // 난이도 세팅
    n_torpedo = n_boat*1.5;
    n_turn = n_boat*boundX + boundY;
}
// 사용자 상태 및 게임 화면 출력
void Game::show_state() {
    score = (init_boatA-n_boatA)*BOAT_A + (init_boatB-n_boatB)*BOAT_B + (init_boatC-n_boatC)*BOAT_C;
    cout << endl
    << "Boat(s) Remain : " << n_boat << endl
    << "Attempt(s) Remain : " << n_turn << endl
    << "Torpedo(s) Remain : " << n_torpedo << endl
    << "Score : " << score << endl;
    
    for (int k = 0; k < boundX*2 + 5; k++)
        cout << "=";
    cout << endl;
    for (int height = 0; height < boundY; height++) {
        cout << "|| ";
        for (int width = 0; width < boundX; width++) {
            // user, boatA, boatB, boatC의 위치에는 해당 문자를 출력하고 아닌 경우에는 바다를 출력
            bool isEmpty = true;
            if (user->getX() == width && user->getY() == height) {
                cout << user->getShape() << " ";
                isEmpty = false;
            }
            BoatA* boatA = boatAList->get_head();
            for (int i = 0; i < boatAList->get_size() ; i++) {
                if (boatA->getX() == width && boatA->getY() == height) {
                    cout << boatA->getShape() << " ";
                    isEmpty = false;
                }
                boatA = boatA->get_next();
            }
            BoatB* boatB = boatBList->get_head();
            for (int i = 0; i < boatBList->get_size() ; i++) {
                if (boatB->getX() == width && boatB->getY() == height) {
                    cout << boatB->getShape() << " ";
                    isEmpty = false;
                }
                boatB = boatB->get_next();
            }
            BoatC* boatC = boatCList->get_head();
            for (int i = 0; i < boatCList->get_size() ; i++) {
                if (boatC->getX() == width && boatC->getY() == height) {
                    cout << boatC->getShape() << " ";
                    isEmpty = false;
                }
                boatC = boatC->get_next();
            }
            for (int i = 0; i <= indexOfTorpedo; i++) {
                if (t_ptr[i]->getX() == width && t_ptr[i]->getY() == height) {
                    cout << t_ptr[i]->getShape() << " ";
                    isEmpty = false;
                }
            }
            if (isEmpty)
                cout << "~ ";
        }
        cout << "|| " << endl;
    }
    for (int k = 0; k < boundX*2 + 5; k++)
        cout << "=";
    cout << endl;
}
bool Game::get_again() {
    return again;
}
// 게임을 종료하기 전 동적 할당받은 메모리 반환
void Game::delete_objects() {
    delete user;
    for (int i = 0; i < init_boat; i++)
        delete b_ptr[i];
    for (int i = 0; i < init_torpedo; i++)
        delete t_ptr[i];
}
// 게임 결과 출력
void Game::show_result() {
    if (n_boat <= 0)
        score = init_boatA*BOAT_A + init_boatB*BOAT_B + init_boatC*BOAT_C + n_torpedo*TORPEDO + n_turn*TURN;
    else
        score = (init_boatA-n_boatA)*BOAT_A + (init_boatB-n_boatB)*BOAT_B + (init_boatC-n_boatC)*BOAT_C;
    cout << endl
    << "Boat(s) Remain : " << n_boat << endl
    << "Attempt(s) Remain : " << n_turn << endl
    << "Torpedo(s) Remain : " << n_torpedo << endl
    << "Score : " << score << endl;
    char type;
    bool iter = true;
    while (iter) {
        cout << "U want play again? Y/N"<< endl;
        cin >> type;
        switch (type) {
            case 'Y': case 'y':
                again = true;
                iter = false;
                break;
            case 'N': case 'n':
                again = false;
                iter = false;
                break;
            default:
                iter = true;
                break;
        }
    }
}
// 게임 진행
void Game::play_game() {
    // 메인 메뉴 출력 및 사용자 입력
    show_initMenu();
    // 게임 종료
    if (n_boat == -1)
        return;
    // user, 보트들 생성
    while (!make_boats()) {}
    // BoatC를 위한 count 변수
    int loopCnt = 0;
    while (true) {
        show_state();
        user->move(); n_turn--;
        if (user->get_hasShot())
            shot_torpedo();

        // BoatA 움직임
        BoatA* boatA = boatAList->get_head();
        for (int i = 0; i < boatAList->get_size(); i++) {
            boatA->move();
            boatA = boatA->get_next();
        }
        // BoatB 움직임
        BoatB* boatB = boatBList->get_head();
        for (int i = 0; i < boatBList->get_size(); i++) {
            boatB->move();
            boatB = boatB->get_next();
        }
        // BoatC 움직임
        BoatC* boatC = boatCList->get_head();
        for (int i = 0; i < boatCList->get_size(); i++) {
            boatC->set_loopCnt(++loopCnt);
            boatC->move();
            boatC = boatC->get_next();
        }
        // Torpedo 움직임
        for (int i = 0; i <= indexOfTorpedo; i++) {
            t_ptr[i]->move();
        }
        // 격추 확인
        checkHit();
        // 승패 조건 검사
        if (n_boat <= 0) {
            cout << endl;
            for (int k = 0; k < boundX*2 + 5; k++)
                cout << "=";
            cout << endl;
            for (int k = 0; k < boundX-2; k++)
                cout << " ";
            cout << "Victory!!!" << endl;
            for (int k = 0; k < boundX*2 + 5; k++)
                cout << "=";
            show_result();
            break;
        }
        else if (n_turn<=0 || n_torpedo<=0) {
            cout << endl;
            for (int k = 0; k < boundX*2 + 5; k++)
                cout << "=";
            cout << endl;
            for (int k = 0; k < boundX-2; k++)
                cout << " ";
            cout << "Lose!!!" << endl;
            for (int k = 0; k < boundX*2 + 5; k++)
                cout << "=";
            show_result();
            break;
        }
    }
}

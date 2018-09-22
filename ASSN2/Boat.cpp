//
//  Boat.cpp
//  GAME2
//
//  Created by ruby on 2017. 11. 11..
//  Copyright © 2017년 ruby. All rights reserved.
//

#include "Boat.hpp"

void Boat::move() {
    hasShot = false;
    char input;
    cout << "왼쪽(a), 오른쪽(d), 어뢰발사(w), 턴넘기기(s) : ";
    cin >> input;
    switch (input) { // 방향에 따라 user을 이동 시킴
        case 'A': case 'a': moveLeft(); break;
        case 'D': case 'd': moveRight(); break;
        case 'W': case 'w': hasShot = true; break;
        case 'S': case 's': break;
    }
}

bool Boat::visibility() {
    if (getX() == -1) { // 잠수 중인 경우 밖으로 나옴
        setX(crtX); setY(crtY);
        return true;
    }
    else {  // 나와있는 경우 잠수함
        crtX = getX(); crtY = getY();
        setX(-1); setY(-1);
        return false;
    }
}

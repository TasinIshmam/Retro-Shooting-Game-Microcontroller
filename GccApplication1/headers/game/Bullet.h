//
// Created by tasin on 8/18/19.
//

#ifndef ARCADESHOOTER_BULLET_H
#define ARCADESHOOTER_BULLET_H


#include "Position.h"
#include "../utils/Constants.h"

class Bullet {


    Position bulletPosition;
    bool isActiveOnBoard;
    unsigned int moveTimeMarker;


public:
    bool isActiveOnBoard1() const {
        return isActiveOnBoard;
    }

    Bullet() {

        isActiveOnBoard = false;
        bulletPosition = Position(0,0);
        moveTimeMarker = BULLET_MOVE_TIME;
    }

    Bullet(int x,int y, bool isActiveOnBoard) : isActiveOnBoard(isActiveOnBoard) {
        moveTimeMarker = BULLET_MOVE_TIME;
        bulletPosition = Position(x,y);

    }

    Bullet(int x,int y) {
        bulletPosition = Position(x,y);
        isActiveOnBoard = false;
        moveTimeMarker = BULLET_MOVE_TIME;

    }

    const Position getBulletPosition() const {
        return bulletPosition;
    }

    void setBulletPosition(const Position bulletPosition) {
        Bullet::bulletPosition = bulletPosition;
    }

    void setIsActiveOnBoard(bool isActiveOnBoard) {
        Bullet::isActiveOnBoard = isActiveOnBoard;
    }

    unsigned int getMoveTimeMarker() const {
        return moveTimeMarker;
    }

    void setMoveTimeMarker(unsigned int moveTimeMarker) {
        Bullet::moveTimeMarker = moveTimeMarker;
    }


    int getX() const {
        return bulletPosition.getX();
    }

    int getY() const {
        return bulletPosition.getY();
    }



    void setBulletPosition(int x,int y) {
        Bullet::bulletPosition.setX(x);
        Bullet::bulletPosition.setY(y);
    }

    void  resetBullet() {
        isActiveOnBoard = false;
        setBulletPosition(0,0);
    }

};


#endif //ARCADESHOOTER_BULLET_H

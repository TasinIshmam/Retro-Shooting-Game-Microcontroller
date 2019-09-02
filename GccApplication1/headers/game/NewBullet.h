//
// Created by hp on 9/1/2019.
//

#ifndef ARCADESHOOTER_NEWBULLET_H
#define ARCADESHOOTER_NEWBULLET_H


#include "Position.h"

class NewBullet {

    Position bulletPosition;
    bool isActiveOnBoard;
    unsigned int moveTimeCounter;
    unsigned int respawnTimeCounter;

public:

    NewBullet() {

        isActiveOnBoard = false;
        bulletPosition = Position(0, 0);
        moveTimeCounter = 0;
    }
    NewBullet(int spawnTimerCounter,int x,int y) {
        this->respawnTimeCounter = spawnTimerCounter;
        isActiveOnBoard = false;
        bulletPosition = Position(x, y);
        moveTimeCounter = 0;

    }

    int getX() const {
        return bulletPosition.getX();
    }

    int getY() const {
        return bulletPosition.getY();
    }

    const Position getBulletPosition() const {
        return bulletPosition;
    }

    void setBulletPosition(int x,int y) {
        NewBullet::bulletPosition.setX(x);
        NewBullet::bulletPosition.setY(y);
    }

    unsigned int getRespawnTimeCounter() const {
        return respawnTimeCounter;
    }

    void setRespawnTimeCounter(unsigned int respawnTimeCounter) {
        NewBullet::respawnTimeCounter = respawnTimeCounter;
    }

    bool IsAlive() const {
        return isActiveOnBoard;
    }

    void setIsAlive(bool isAlive) {
        NewBullet::isActiveOnBoard = isAlive;
    }

    unsigned int getMoveTimeCounter() const {
        return moveTimeCounter;
    }

    void setMoveTimeCounter(unsigned int spawnTimerCounter) {
        NewBullet::moveTimeCounter = spawnTimerCounter;
    }

};
#endif //ARCADESHOOTER_NEWBULLET_H

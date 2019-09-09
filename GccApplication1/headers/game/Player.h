//
// Created by Asus on 8/17/2019.
//

#ifndef ARCADESHOOTER_PLAYER_H
#define ARCADESHOOTER_PLAYER_H

//00 = calibratomg 01 = right 10 = left = 11 = nothing

class Player {

    Position playerPosition;
    bool readyToMove; 
    


public:
    Player() {
        playerPosition = Position(4,BOARD_HEIGHT-1);
        readyToMove = true;
    }

    int getX() const {
        return playerPosition.getX();
    }

    int getY() const {
        return playerPosition.getY();
    }

    const Position getPlayerPosition() const {
        return playerPosition;
    }

    void setPlayerPosition(int x,int y) {
        Player::playerPosition.setX(x);
        Player::playerPosition.setY(y);
    }


    bool isReadyToMove() const {
        return readyToMove;
    }

    void setIsReadyToMove(bool ready) {
        Player::readyToMove = ready;
    }
};

#endif //ARCADESHOOTER_PLAYER_H

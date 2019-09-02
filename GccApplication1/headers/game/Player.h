//
// Created by Asus on 8/17/2019.
//

#ifndef ARCADESHOOTER_PLAYER_H
#define ARCADESHOOTER_PLAYER_H

class Player {

    Position playerPosition;


public:
    Player() {
        playerPosition = Position(4,BOARD_HEIGHT-1);
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
};

#endif //ARCADESHOOTER_PLAYER_H

//
// Created by Asus on 8/17/2019.
//

#ifndef ARCADESHOOTER_ENEMY_H
#define ARCADESHOOTER_ENEMY_H


class Enemy {

    Position enemyPosition;
    bool isAlive;
    unsigned int spawnTimerCounter;

public:

    Enemy() {

        isAlive = true;
        enemyPosition = Position(0,0);
    }
    Enemy(int spawnTimerCounter,int x,int y) {
        this->spawnTimerCounter = spawnTimerCounter;
        isAlive = true;
        enemyPosition = Position(x,y);
    }

    int getX() const {
        return enemyPosition.getX();
    }

    int getY() const {
        return enemyPosition.getY();
    }

    const Position getEnemyPosition() const {
        return enemyPosition;
    }

    void setEnemyPosition(int x,int y) {
        Enemy::enemyPosition.setX(x);
        Enemy::enemyPosition.setY(y);
    }

    bool IsAlive() const {
        return isAlive;
    }

    void setIsAlive(bool isAlive) {
        Enemy::isAlive = isAlive;
    }

    unsigned int getSpawnTimerCounter() const {
        return spawnTimerCounter;
    }

    void setSpawnTimerCounter(unsigned int spawnTimerCounter) {
        Enemy::spawnTimerCounter = spawnTimerCounter;
    }
};

#endif //ARCADESHOOTER_ENEMY_H

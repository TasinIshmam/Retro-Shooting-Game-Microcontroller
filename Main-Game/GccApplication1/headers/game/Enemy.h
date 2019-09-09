#ifndef ARCADESHOOTER_ENEMY_H
#define ARCADESHOOTER_ENEMY_H


class Enemy {

    Position enemyPosition;
    bool alive;
    unsigned int spawnTimerCounter;
    unsigned int moveTimerCounter;

public:

    Enemy() {
        alive = true;
        enemyPosition = Position(0,0);
    }
	
    Enemy(int spawnTimerCounter,int x,int y) {
        this->spawnTimerCounter = spawnTimerCounter;
        alive = false;
        enemyPosition = Position(x,y);
        moveTimerCounter = 0;
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

    bool isAlive() const {
        return alive;
    }

    void setIsAlive(bool isalive) {
        Enemy::alive = isalive;
    }

    unsigned int getSpawnTimerCounter() const {
        return spawnTimerCounter;
    }

    void setSpawnTimerCounter(unsigned int spawnTimerCounter) {
        Enemy::spawnTimerCounter = spawnTimerCounter;
    }

    unsigned int getMoveTimeCounter() const {
        return moveTimerCounter;
    }

    void setMoveTimeCounter(unsigned int moveTimerCounterarg) {
        Enemy::moveTimerCounter = moveTimerCounterarg;
    }
};

#endif //ARCADESHOOTER_ENEMY_H

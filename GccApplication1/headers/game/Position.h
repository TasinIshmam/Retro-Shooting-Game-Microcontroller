//
// Created by hp on 8/16/2019.
//

#ifndef ARCADESHOOTER_POSITION_H
#define ARCADESHOOTER_POSITION_H




class Position {
    int x, y;

public:
    Position(int x, int y) : x(x), y(y) {

    }

    Position() {
        x = 0;
        y = 0;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Position::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Position::y = y;
    }
};

#endif //ARCADESHOOTER_POSITION_H

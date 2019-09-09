#ifndef ARCADESHOOTER_CONSTANTS
#define ARCADESHOOTER_CONSTANTS

const static char BOARD_X_PORT = 'A';
const static char BOARD_Y_PORT = 'B';

//const static int DEBUG = 1;
const static int BOARD_WIDTH = 8;
const static int BOARD_HEIGHT = 16;

//const static unsigned int DEBUG = 1;
const static unsigned int BULLET_POOL_SIZE = 20;
const static unsigned int ENEMY_POOL_SIZE = 3;
// const static unsigned int ENEMY1_INIT_TIME = 300;
// const static unsigned int ENEMY2_INIT_TIME = 400;
// const static unsigned int ENEMY3_INIT_TIME = 500;
// const static unsigned int ENEMY1_MOVE_TIME = 1200;
// const static unsigned int ENEMY2_MOVE_TIME = 1500;
// const static unsigned int ENEMY3_MOVE_TIME = 1800;


const static int PLAYER_STATUS_IN_BOARD = 1;
const static int ENEMY_STATUS_IN_BOARD = 2;
const static int BULLET_STATUS_IN_BOARD = 3;

const static unsigned int ENEMY_MOVE_TIME_NEW = 400;
const static unsigned int ENEMY_SPAWN_TIME_NEW = 3000;


const static unsigned int BULLET_MOVE_TIME = 150;
const static unsigned int BULLET_SPAWN_TIME = 1000;


const static unsigned int BULLET_SHOOT_DELAY = 1500;//2500;//5500;
const static unsigned int BULLET_INIT_TIME = 200;

const static unsigned int PLAYER_MOVE_SPEED = 2700;
const static unsigned int PLAYER_MOVE_SPEED_GYRO =300; //700;

const static unsigned int GYRO_CALIBRATING = 0;
const static unsigned int GYRO_MOVE_RIGHT = 1;
const static unsigned int GYRO_MOVE_LEFT = 2;
const static unsigned int GYRO_STAY_STILL = 3;
const static unsigned int GYRO_INVALID = 5;

const static unsigned int SHOOTING_BUZZER_LOOP_CNT = 10;
const static unsigned int ENEMY_BULLET_CONFLICT_BUZZER_LOOP_CNT = 20;
const static unsigned int ENEMY_PLAYER_CONFLICT_BUZZER_LOOP_CNT = 30;

#endif //ARCADESHOOTER_CONSTANTS
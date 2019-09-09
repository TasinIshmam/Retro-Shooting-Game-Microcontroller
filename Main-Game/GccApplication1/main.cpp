#include "headers/game/GameController.h"
#include "headers/utils/HardwareController.h"

GameController gameController;

void softwareSetup() {
    gameController = GameController();
    gameController.initializePlayerPosition();
}


void setup() {
    softwareSetup();
	HardwareController::hardWareSetup();
}


void loop(unsigned loopNo) {
	gameController.setLoopNo(loopNo);
	gameController.updateEnemyPositions();
	gameController.playerMovementUpdateWithGyro();  //turn on and comment out simulate when ready to connect gyro.
	gameController.bulletPoll();
	gameController.updateNewBulletPositions();
	gameController.updateBasedOnCollisions();
	
	HardwareController::displayBoardMatrixBackup(gameController.displayBoard);
}

int main() {
	setup();
	unsigned int loopCount = 0;
	
	while (true) {
		loopCount++;
	    loop(loopCount);
	}
}


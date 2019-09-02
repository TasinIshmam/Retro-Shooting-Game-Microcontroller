#include "headers/game/GameController.h"
#include "headers/utils/HardwareController.h"

GameController gameController;

void softwareSetup() {
    gameController = GameController();
    gameController.initializePlayerPosition();
   // gameController.initEnemyPositions();
}


void setup() {
    softwareSetup();
	HardwareController::hardWareSetup();
}


void loop(unsigned loopNo) {
	gameController.setLoopNo(loopNo);
	gameController.updateEnemyPositions();
	gameController.simulateRandomPlayerMovements();
	gameController.shootNewBullet();
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


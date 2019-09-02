/*
 * main.cpp
 *
 * Created: 7/30/2019 6:17:26 PM
 * Author : Ashiq-103
 */
#include "headers/game/GameController.h"
#include "headers/utils/HardwareController.h"

GameController gameController;

void softwareSetup() {
    gameController = GameController();
    gameController.initializePlayerPosition();
    gameController.initEnemyPositions();
}


void setup() {
    softwareSetup();
	HardwareController::hardWareSetup();
	//HardwareController::gyroSetup();
}

void loop(unsigned loopNo) {
    
	gameController.setLoopNo(loopNo);
	gameController.updateEnemyPositions();
	gameController.simulateRandomPlayerMovements();
	gameController.shootNewBullet();
	gameController.updateNewBulletPositions();
	
	HardwareController::displayBoardMatrixBackup(gameController.displayBoard);
	//HardwareController::gyroLoop();
}

int main() {
	setup();
	unsigned int loopCount = 0;
	while(1){
		loopCount++;
	    loop(loopCount);
		
	}
}


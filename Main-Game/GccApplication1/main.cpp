#include "headers/game/GameController.h"
#include "headers/utils/HardwareController.h"

GameController gameController;

void softwareSetup() {
    gameController = GameController();
    gameController.initializePlayerPosition();
   // gameController.initEnemyPositions();// int x
    
}


void setup() {
    softwareSetup();
	HardwareController::hardWareSetup();
	
}


void loop(unsigned loopNo) {
	gameController.setLoopNo(loopNo);
	gameController.updateEnemyPositions();
	//gameController.simulateRandomPlayerMovements();
	gameController.playerMovementUpdateWithGyro();  //turn on and comment out simulate when ready to connect gyro.
	gameController.bulletPoll();
	gameController.updateNewBulletPositions();
	gameController.updateBasedOnCollisions();//includes LCD updates
	
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


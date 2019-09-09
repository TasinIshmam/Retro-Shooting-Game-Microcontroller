

#ifndef ARCADESHOOTERCLION_GAMECONTROLLER_H
#define ARCADESHOOTERCLION_GAMECONTROLLER_H

#include "../utils/LogUtils.cpp"
#include "../utils/Constants.h"
#include "../utils/HardwareController.h"
#include "Position.h"
#include "Player.h"
#include "Enemy.h"
#include "NewBullet.h"
#include <stdlib.h>
#include <string.h>


class GameController {
	
	unsigned int enemyBulletCollisionCounter ;
	unsigned int enemyPlayerCollisionCounter ;
	char* score1,*score2;	
	bool bulletReadyToShoot;
	
	Player player;
	//Enemy enemy1, enemy2, enemy3;

	Enemy enemyPool[ENEMY_POOL_SIZE];

	 int getRandomBoardXCordinate() {
		 	return rand() % BOARD_WIDTH;
	}

	
	unsigned int loopNo;
//	  Bullet bullet1, bullet2, bullet3, bullet4;
//    NewBullet newBullet1, newBullet2, newBullet3, newBullet4;
	int randomPlayerMovementFlag;  //0 = move left, 1 = move right

	NewBullet bulletPool[BULLET_POOL_SIZE];

	void updateEnemy(Enemy &enemy) {

		// unsigned int moveTime=0;
		// if(enemyNo == 1)
		// moveTime = ENEMY1_MOVE_TIME;
		// else if(enemyNo == 2)
		// moveTime = ENEMY2_MOVE_TIME;
		// else if(enemyNo == 3)moveTime = ENEMY3_MOVE_TIME;

		unsigned int currentTime = enemy.getSpawnTimerCounter();
		enemy.setSpawnTimerCounter(currentTime + 1);

		if( enemy.getSpawnTimerCounter() % ENEMY_SPAWN_TIME_NEW == 0 ) {
			enemy.setSpawnTimerCounter(0);

			if ( !enemy.isAlive() ) {
				enemy.setEnemyPosition(getRandomBoardXCordinate(), 0);
				enemy.setIsAlive(true);
				setIndexInBoard(enemy.getX(), enemy.getY(),2);
			}
		}
		
		
		enemy.setMoveTimeCounter(enemy.getMoveTimeCounter() + 1);
	

		if (enemy.getMoveTimeCounter() >= ENEMY_MOVE_TIME_NEW && enemy.isAlive()) {
			Position p = enemy.getEnemyPosition();
			int prevX = p.getX(),prevY = p.getY();
			enemy.setEnemyPosition(prevX,(prevY+1)%BOARD_HEIGHT);
			////printStringToConsole("Enemy "+to_string(enemyNo)+"("+to_string(enemy.getX())+","+to_string(enemy.getY())+")");
			enemy.setMoveTimeCounter(0);
			resetIndexInBoard(prevX,prevY);

			if(prevY == BOARD_HEIGHT - 1) {
				enemy.setIsAlive(false);
			}
		
		if(enemy.isAlive())	setIndexInBoard(enemy.getX(),enemy.getY(), ENEMY_STATUS_IN_BOARD); // no need to display if dead

			// //printStringToConsole("\n\n");
			//            displayBoardDebug();
			//            //printStringToConsole("Enemy moved\n");
		}







		

		//if(enemy.getY() == 0)enemy.setIsAlive(true); // if enemy goes down the screenbounds


	}

	void activeBulletForShooting(NewBullet &newBullet) {
		
			newBullet.setRespawnTimeCounter(0);
			newBullet.setMoveTimeCounter(0);
	        newBullet.setIsAlive(true);
	        newBullet.setBulletPosition(player.getX(), player.getY() - 2);
            setIndexInBoard(newBullet.getX(), newBullet.getY(), BULLET_STATUS_IN_BOARD);
	}


    void updateNewBullet(NewBullet &newBullet) {

		//removed as moving to a different bullet spawn system
	    // unsigned  int respawnTime = BULLET_SPAWN_TIME;

	    // if(respawnTime <= newBullet.getRespawnTimeCounter() ) {

	    //     newBullet.setRespawnTimeCounter(0);
	    //     newBullet.setIsAlive(true);
	    //     newBullet.setBulletPosition(player.getX(), player.getY() - 2);
        //     setIndexInBoard(newBullet.getX(), newBullet.getY());

	    // }
		//newBullet.setRespawnTimeCounter( newBullet.getRespawnTimeCounter() + 1);


        unsigned int moveTime= BULLET_MOVE_TIME;
        unsigned int currentTime = newBullet.getMoveTimeCounter();
        newBullet.setMoveTimeCounter(currentTime + 1);

        if (newBullet.getMoveTimeCounter() >= moveTime) {
            Position p = newBullet.getBulletPosition();
            int prevX = p.getX(),prevY = p.getY();

            int newX = p.getX();
            int newY = p.getY() - 1;

            if(newY == -1) {
				if(newBullet.IsAlive()) resetIndexInBoard(prevX, prevY);
                newBullet.setIsAlive(false);
                newY = BOARD_HEIGHT - 1;
            }

            newBullet.setBulletPosition(newX, newY);

            ////printStringToConsole("Enemy "+to_string(enemyNo)+"("+to_string(enemy.getX())+","+to_string(enemy.getY())+")");
            newBullet.setMoveTimeCounter(0);

            if(newBullet.IsAlive()) resetIndexInBoard(prevX, prevY);

            if(newBullet.IsAlive())
				setIndexInBoard(newBullet.getX(),
					newBullet.getY(),
					BULLET_STATUS_IN_BOARD
				); // no need to display if dead

            // //printStringToConsole("\n\n");
            //            displayBoardDebug();
            //            //printStringToConsole("Enemy moved\n");
        }

        //if(newBullet.getY() == 0)newBullet.setIsAlive(true); // if newBullet goes down the screenbounds


    }

	public:
	int displayBoard[BOARD_HEIGHT][BOARD_WIDTH];



	GameController() {
		// enemy1 = Enemy(ENEMY1_INIT_TIME,0,0);
		// enemy2 = Enemy(ENEMY2_INIT_TIME,1,0);
		// enemy3 = Enemy(ENEMY3_INIT_TIME,2,0);
//
//		bullet1 = Bullet(0,0, false);
//		bullet2 = Bullet(0,0, false);
//		bullet3 = Bullet(0,0, false);
//		bullet4 = Bullet(0,0, false);

    //    newBullet1 = NewBullet(0, 0,0);
    //    newBullet2 = NewBullet(2000, 0,0);
    //    newBullet3 = NewBullet(4000, 0,0);
    //    newBullet4 = NewBullet(6000, 0,0);

	enemyBulletCollisionCounter = 0;
	enemyPlayerCollisionCounter = 0;
	bulletReadyToShoot = true;
	
	score1 = (char *)malloc(4*sizeof(char));
	score2 = (char *)malloc(4*sizeof(char));
	
	for(int i = 0; i < ENEMY_POOL_SIZE; i++) {

		enemyPool[i] = Enemy(i * 500, getRandomBoardXCordinate() , 0);
	}


	    for(int i = 0; i < BULLET_POOL_SIZE; i++) {
		    bulletPool[i] = NewBullet(0,0,0);
	    }




		int rows = BOARD_HEIGHT, cols = BOARD_WIDTH;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				displayBoard[i][j] = 0;
			}
		}
	}

	int getLoopNo() const {
		return loopNo;
	}

	void setLoopNo(int loopNo) {
		GameController::loopNo = loopNo;
	}

	void displayBoardDebug() {

		//string divider = "------------------------------------------------------------------";

		for (int row = 0; row < BOARD_HEIGHT; row++) {
			for (int col = 0; col < BOARD_WIDTH; col++) {
				//string print = to_string(displayBoard[row][col]) + " ";
				////printStringToConsole(print);
			}
			////printStringToConsole("\n");
		}
	}

	bool checkIfConflict(int x, int y) {
		if (displayBoard[x][y] == 1) {
			//todo add conflict resolution logic

			//string printString =
			//       "Conflict detected. Some object already in position (" + to_string(x) + "," + to_string(y) + ")\n";
			return true;

		}
		return false;
	}


	void setIndexInBoard(int x, int y) {
		checkIfConflict(x, y);
		displayBoard[y][x] = 1;
	}

	void setIndexInBoard(int x, int y,int val) {
		checkIfConflict(x, y);
		displayBoard[y][x] = val;
	}

	void resetIndexInBoard(int x, int y) {
		checkIfConflict(x, y);
		displayBoard[y][x] = 0;
	}

	void initializePlayerPosition(int x, int y) {
		setIndexInBoard(x, y,3);
		setIndexInBoard(x - 1, y,3);
		setIndexInBoard(x + 1, y,3);
		setIndexInBoard(x, y - 1,3);

	}

	void resetPlayerPosition(int x, int y) {
		resetIndexInBoard(x, y);
		resetIndexInBoard(x - 1, y);
		resetIndexInBoard(x + 1, y);
		resetIndexInBoard(x, y - 1);
	}

	void initializePlayerPosition() {
		initializePlayerPosition(player.getX(), player.getY());
	}

	void shiftPlayerLeft (int shiftPositions) {
		int prevX = player.getX();
		int prevY = player.getY();

		int maxLeftMovement = (prevX - 1);
		if(shiftPositions > maxLeftMovement) shiftPositions = maxLeftMovement;

		movePlayer( prevX - shiftPositions, prevY);

	}


	void shiftPlayerRight (int shiftPositions) {
		int prevX = player.getX();
		int prevY = player.getY();

		int maxRightMovement = (BOARD_WIDTH - prevX - 2);
		if(shiftPositions > maxRightMovement) shiftPositions = maxRightMovement;

		movePlayer( prevX + shiftPositions, prevY);

	}

	void movePlayer(int x, int y) {
		int prevX = player.getX();
		int prevY = player.getY();

		player.setPlayerPosition(x,y);
		resetPlayerPosition(prevX, prevY);
		initializePlayerPosition(x,y);


	}

	void updateEnemyPositions(){
		// updateEnemy(enemy1,1);
		// updateEnemy(enemy2,2);
		// updateEnemy(enemy3,3);

		for(int i = 0; i < ENEMY_POOL_SIZE; i++) {
			updateEnemy( enemyPool[i] );
		}
	}


    void updateNewBulletPositions() {
			// updateNewBullet(newBullet1);
			// updateNewBullet(newBullet2);
			// updateNewBullet(newBullet3);
			// updateNewBullet(newBullet4);

		for(int i = 0; i < BULLET_POOL_SIZE; i++) {
			updateNewBullet(bulletPool[i]);
		}
	}

	void shootNewBullet() {
		

		
			for(int i = 0; i < BULLET_POOL_SIZE; i++) {
			if(bulletPool[i].IsAlive() == false) {
				activeBulletForShooting(bulletPool[i]);
				bulletReadyToShoot = false;
				return;
			}
		}
	
	}


	void bulletPoll() {

		if(loopNo % BULLET_SHOOT_DELAY == 0) {
			bulletReadyToShoot = true;
		}

		if(bulletReadyToShoot && HardwareController::isShootButtonPressed()) {
			shootNewBullet();
		}
	}

	void initEnemyPositions(){
		//setIndexInBoard(enemy1.getX(),enemy1.getY(),ENEMY_STATUS_IN_BOARD);
	//	setIndexInBoard(enemy2.getX(),enemy2.getY(), ENEMY_STATUS_IN_BOARD);
	//	setIndexInBoard(enemy3.getX(),enemy3.getY(), ENEMY_STATUS_IN_BOARD);
	}

	
	bool doesCollide(const Enemy &enemy, const NewBullet &bullet) {
		
		if (!enemy.isAlive() || !bullet.IsAlive())
			return false;
		
		if (enemy.getEnemyPosition() == bullet.getBulletPosition()) {
			return true;
		}
		
		return false;
	}


	bool doesCollide(const Enemy &enemy) {
		if (!enemy.isAlive()) return false;
		
		// dx and dy contains the change in x and y co-ordinate from origin of player position to get all the 
		// points needed by player.
		const int dx[] = {0, 0, -1, 1};
		const int dy[] = {0, -1, 0, 0};
			
		const Position player_pos = player.getPlayerPosition();
		const Position enemy_pos = enemy.getEnemyPosition();
			
		for (int i = 0; i < 4; i++) {
			if (enemy_pos.getX() == player_pos.getX()+dx[i] && enemy_pos.getY() == player_pos.getY()+dy[i]) {
				return true;
			}
		}
		
		return false;
	}
	
	
	char* getScoreString(){
		//todo: score logic needs to be updated
		itoa (enemyBulletCollisionCounter,score1,10);
		itoa (enemyPlayerCollisionCounter,score2,10);
		strcat(score1, ", ");
		strcat(score1,score2);
		
		return score1;
	}
	
	// updates the values showed in the LCD display.
	// should be called after updatBased on collisions has been called.
	void updateLcdDisplay() {
		
		char healthStatus[16];
		if (enemyPlayerCollisionCounter < 5) {
			strcpy(healthStatus, "Great health!");
			} else if (enemyPlayerCollisionCounter < 10) {
			strcpy(healthStatus, "Good health!");
			} else if (enemyPlayerCollisionCounter < 15) {
			strcpy(healthStatus, "Critical health :(");
			} else {
			strcpy(healthStatus, "Dead :'(");
		}
		
		HardwareController::displayLcd(getScoreString(),healthStatus);
	}

	// for all objects, check for collision, update collision count and reset boards
	void updateBasedOnCollisions() {

		unsigned int lastEnemyBulletCollisionCounter = enemyBulletCollisionCounter;
		unsigned int lastEnemyPlayerCollisionCounter = enemyPlayerCollisionCounter;
	
		// checking for bullet and enemy collisions		
		for (unsigned int enemyCounter = 0; enemyCounter < ENEMY_POOL_SIZE; enemyCounter++) {
			for (unsigned int bulletCounter = 0; bulletCounter < BULLET_POOL_SIZE; bulletCounter++) {
				if (doesCollide(enemyPool[enemyCounter], bulletPool[bulletCounter])) {
					enemyBulletCollisionCounter++;
					
					const Position position = enemyPool[enemyCounter].getEnemyPosition();
					resetIndexInBoard(position.getX(), position.getY());
					
					bulletPool[bulletCounter].setIsAlive(false);
					enemyPool[enemyCounter].setIsAlive(false);
				}
			}
		}

		// checking for collision of enemy with the player
		for (unsigned int enemyCounter = 0; enemyCounter < ENEMY_POOL_SIZE; enemyCounter++) {
			if (doesCollide(enemyPool[enemyCounter])) {
				enemyPlayerCollisionCounter++;
				enemyPool[enemyCounter].setIsAlive(false);
			}
		}
		
		if (lastEnemyPlayerCollisionCounter != enemyPlayerCollisionCounter 
			|| lastEnemyBulletCollisionCounter != enemyBulletCollisionCounter) {
				updateLcdDisplay();
			}
			
	}

//	void launchBullet () {
//
//		Position bulletPos = player.getPlayerPosition();
//		bulletPos.setY( bulletPos.getY() - 2);
//
//		switch (lastBulletReleased) {
//			case 0 : case 4 : {
//				bullet1.setBulletPosition(bulletPos);
//				bullet1.setIsActiveOnBoard(true);
//				lastBulletReleased = 1;
//				break;
//			}
//			case 1 : {
//				bullet2.setBulletPosition(bulletPos);
//				bullet2.setIsActiveOnBoard(true);
//				lastBulletReleased++;
//				break;
//			}
//			case 2 : {
//				bullet3.setBulletPosition(bulletPos);
//				bullet3.setIsActiveOnBoard(true);
//				lastBulletReleased++;
//				break;
//			}
//			case 3 : {
//				bullet4.setBulletPosition(bulletPos);
//				bullet4.setIsActiveOnBoard(true);
//				lastBulletReleased++;
//				break;
//			}
//		}
//	}

//	void moveBullet(Bullet &bullet) {
//
//		//        Position p = enemy.getEnemyPosition();
//		//        int prevX = p.getX(),prevY = p.getY();
//		//
//		//        enemy.setEnemyPosition(prevX,(prevY+1)%BOARD_HEIGHT);
//		//        //printStringToConsole("Enemy "+to_string(enemyNo)+"("+to_string(enemy.getX())+","+to_string(enemy.getY())+")");
//		//        enemy.setSpawnTimerCounter(0);
//		//        resetIndexInBoard(prevX,prevY);
//		//        if(enemy.isAlive())setIndexInBoard(enemy.getX(),enemy.getY()); // no need to display if dead
//		//        //printStringToConsole("\n\n");
//		//        displayBoardDebug();
//
//		Position prevPos = bullet.getBulletPosition();
//		int prevX = prevPos.getX();
//		int prevY = prevPos.getY();
//
//		int newY = prevY - 1;
//		resetIndexInBoard(prevX, prevY);
//
//		if(newY == -1) {
//			bullet.resetBullet();
//			//printStringToConsole("Reset Bullet\n");
//			return;
//		}
//
//		bullet.setBulletPosition(prevX, newY);
//		setIndexInBoard(prevX, newY, 2);
//
//
//
//
//	}

//	void updateBulletPositions() {
//		if(loopNo % BULLET_SHOOT_DELAY == 0) {
//			launchBullet();
//			////printStringToConsole("Bullet" + to_string(lastBulletReleased+1)+" Launched\n");
//		}
//
//
//		if(loopNo % BULLET_MOVE_TIME == 0) {
//			//printStringToConsole("\n");
//			if(bullet1.isActiveOnBoard1()) {
//
//				moveBullet(bullet1);
//				//printStringToConsole("1, ");
//			}
//
//			if(bullet2.isActiveOnBoard1()) {
//				moveBullet(bullet2);
//				//printStringToConsole("2, ");
//			}
//			if(bullet3.isActiveOnBoard1()) {
//				moveBullet(bullet3);
//				//printStringToConsole("3, ");
//			}
//			if(bullet4.isActiveOnBoard1()) {
//				moveBullet(bullet4);
//				//printStringToConsole("4, ");
//			}
//			//printStringToConsole("Bullets moved\n\n");
//
//			//printStringToConsole("\n\n");
//			displayBoardDebug();
//
//		}
//
//	}

	void simulateRandomPlayerMovements() {

		if(loopNo % PLAYER_MOVE_SPEED != 0) {
			return;
		}

		if(player.getX() == 1) {
			randomPlayerMovementFlag = 1;
			} else if ( player.getX() == BOARD_WIDTH - 2){
			randomPlayerMovementFlag = 0;
		}

		if(randomPlayerMovementFlag == 0) {
			shiftPlayerLeft(1);
			} else {
			shiftPlayerRight(1);
		}

		//printStringToConsole("Player Moved\n");

	}

	void playerMovementUpdateWithGyro() {

		if(loopNo % PLAYER_MOVE_SPEED_GYRO == 0) {
			player.setIsReadyToMove(true);
		}


		if(player.isReadyToMove()) {
			int movement = HardwareController::getGyroReading();

			if(movement == GYRO_MOVE_LEFT) {
				shiftPlayerLeft(1);
				player.setIsReadyToMove(false);
			} else if(movement == GYRO_MOVE_RIGHT) {
				shiftPlayerRight(1);
				player.setIsReadyToMove(false);
			}
		}
	}




};

#endif //ARCADESHOOTERCLION_GAMECONTROLLER_H
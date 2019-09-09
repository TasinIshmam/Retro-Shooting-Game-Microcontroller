//////
////// Created by Asus on 8/17/2019.
//////
////
#ifndef ARCADESHOOTER_HARDWAREINTERFACE_H
#define ARCADESHOOTER_HARDWAREINTERFACE_H

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

#include "LED.h"
/**LCD**/
#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTC6
#define EN eS_PORTC7
#include "LCD.h"
#include "Constants.h"
/** ** **/

#define delay 100

class HardwareController
{
public:
	static void displayBoardMatrix(int board[BOARD_HEIGHT][BOARD_WIDTH])
	{
		int rows = BOARD_HEIGHT, cols = BOARD_WIDTH;

		for (int i = 0; i < rows; i++)
		{
			PORTB = 0xFF;	 //Turning the columns off
			PORTA = (1 << i); //Enabling the ith row

			unsigned char temp = 0xFF;
			for (int j = 0; j < cols; j++)
			{
				if (board[i][j] == 1 || board[i][j] == 2 || board[i][j] == 3)
				{
					temp &= ~(1 << j); //Putting 0 to the corresponding column
				}
			}

			PORTB = temp;
			_delay_us(10);
		}
	}

	static int getGyroReading() {
		char rawInput = PINA; 

		char inputLSB = rawInput & 0b00000011 ;
		

		switch(inputLSB) {
			case 0: return GYRO_CALIBRATING;
			case 1: return GYRO_MOVE_RIGHT;
			case 2: return GYRO_MOVE_LEFT;
			case 3: return GYRO_STAY_STILL;
			default: return GYRO_INVALID;
		}
		

		 

	}

	static void hardWareSetup()
	{
		//LED MATRIX OUTPUT
		DDRA = 0b11111100;
		DDRB = 255;
		//LCD DISPLAY
		DDRD = 0xFF;
		DDRC = 0xFF;
		Lcd4_Init();

		// MCUCSR = (1<<JTD);
		// MCUCSR = (1<<JTD);// We need to do this twice in order to use PORTC directly for IO

		//Gyro
		// DDRA = 0xFF;
		// DDRB = 0xFF;

		// PORTA = 0xAA;
		// PORTB = 0xAA;
	}

	//point by point scan
	static void displayBoardMatrixBackup(int board[BOARD_HEIGHT][BOARD_WIDTH])
	{
		int rows = BOARD_HEIGHT, cols = BOARD_WIDTH;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (board[i][j])
				{
					//   ledPrint(j, 'B', i, 'A');  Moving to decoder printing
					//   //ledPrint(j, 'B', i, 'A');
					
					// if(board[i][j] == ENEMY_STATUS_IN_BOARD) {
					// ledPrintUsingTwoDecoder(j, i, 'A','R');
					// } else {
					// 	ledPrintUsingTwoDecoder(j, i, 'A','G');
					// }

					voidLedPrintUsingOneDecoder(j,i);

					
					//ledPrintUsingDecoder(6, 13, 'A');
					_delay_us(delay);
					//ledPrintUsingDecoder(3, 4, 'A');
					//_delay_us(delay);
				}
			}
		}
	}

	static void displayLcdUpper(char *str)
	{
		Lcd4_Clear();
		Lcd4_Set_Cursor(1, 0);
		Lcd4_Write_String(str);
		_delay_us(delay);
	}

	static void displayLcdLower(char *str)
	{
		Lcd4_Clear();
		Lcd4_Set_Cursor(2, 0);
		Lcd4_Write_String(str);
		_delay_us(delay);
	}
	
	//00 = calibratomg ,01 = right, 10 = left, 11 = nothing

	

	/* static void gyroLoop(){
		gyroLibLoop();
	}
	static void gyroSetup(){
		gyroInit();
	}  */
};

#endif //ARCADESHOOTER_HARDWAREINTERFACE_H

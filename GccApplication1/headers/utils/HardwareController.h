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
/** ** **/


class HardwareController
{
public:
	
	
	static void displayBoardMatrix(int board[BOARD_HEIGHT][BOARD_WIDTH])
    {
		    int rows = BOARD_HEIGHT, cols = BOARD_WIDTH;

		    for(int i = 0; i < rows; i++)
		    {
			    PORTB = 0xFF;		//Turning the columns off
			    PORTA = (1 << i);	//Enabling the ith row

			    unsigned char temp = 0xFF;
			    for(int j = 0; j < cols; j++)
			    {
				    if(board[i][j] == 1 || board[i][j]==2 || board[i][j]==3)
				    {
					    temp &= ~(1 << j);	//Putting 0 to the corresponding column
				    }
			    }

			    PORTB = temp;
			    _delay_us(10);
		    }
	    }
	
	static void hardWareSetup()
    {
        //LED MATRIX OUTPUT
        DDRA = 255;
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
					ledPrintUsingDecoderOnPortA(j,i);
					  _delay_us(100);
				  }
			  }
		  }
	 }
	static void displayLcd(char * str){
		Lcd4_Clear();
		Lcd4_Set_Cursor(1, 0);
		Lcd4_Write_String(str);
		//TODO: possible delay	 	
	}
	
	/* static void gyroLoop(){
		gyroLibLoop();
	}
	static void gyroSetup(){
		gyroInit();
	}  */
};

#endif //ARCADESHOOTER_HARDWAREINTERFACE_H

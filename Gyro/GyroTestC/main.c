#define F_CPU 1000000

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <math.h>  //include libm

#include "mpu6050.h"

#define UART_BAUD_RATE 4800
#include "uart.h"
#define PI 3.14159


volatile uint32_t tot_overflow;

void timer1_init() {
    //TCNT1, TCCR1A, TCCR1B, TIMSK, TIFR, ICR1, TIMER1_OVF_vect
    
    TCCR1B = 1 << CS10;
    TIMSK = 1 << TOIE1;
    TCNT1 = 0;
    tot_overflow = 0;
}

ISR(TIMER1_OVF_vect)
{
    // keep a track of number of overflows
    tot_overflow++;
}

uint32_t getElapsedTime() {
    //return tot_overflow * (255 - TCNT0);
    return (tot_overflow * 65536 + (uint32_t) TCNT1) / 1000  ; //time returned in micro seconds / 1000 = millis
    //return TCNT0;
}

int main(void) {
    
	DDRB = 0x0F;
	
    uint32_t elapsedTime  = 0;
    
    double rollError = 0;
    double pitchError = 0;
    double yawError = 0;
    
    int calibrationState = 0;     //0 means not calibrated
    int delay = 200;

    double qw = 1.0f;
	double qx = 0.0f;
	double qy = 0.0f;
	double qz = 0.0f;
	double roll = 0.0;
	double pitch = 0.0;
	double yaw = 0.0;

    //init uart
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU));

	//init interrupt
	sei();

	//init mpu6050
	mpu6050_init();
	_delay_ms(50);

	//init mpu6050 dmp processor
	mpu6050_dmpInitialize();
	mpu6050_dmpEnable();
	_delay_ms(10);
	
    timer1_init();

	while(1) {
		
		//quaternion
		char itmp[10];
		
		
		uart_puts("Starting Reading Data");
		
		if(mpu6050_getQuaternionWait(&qw, &qx, &qy, &qz)) {
			mpu6050_getRollPitchYaw(qw, qx, qy, qz, &roll, &pitch, &yaw);
		}
		_delay_ms(10);
		
		
		double roll1 = roll * 180 / PI;
		double pitch1 = pitch * 180 / PI;
		double yaw1 = yaw * 180 / PI;
                
        //error correction
        elapsedTime = getElapsedTime() / 1000; 
        
        if(calibrationState == 0 && elapsedTime > 15) {
            rollError = roll1;
            pitchError = pitch1;
            yawError = yaw1;
            calibrationState = 1;
        }
        else if(calibrationState == 1) {
            uart_puts("Done Reading Data");
			PORTB = 0x00;
			_delay_us(10);
			
			roll1 -= rollError;
            pitch1 -= pitchError;
            yaw1 -= yawError;
            
            uart_puts("R:");
            dtostrf(roll1, 3, 0, itmp); uart_puts(itmp); uart_puts("  ");
			if(roll1 <= -5){
				uart_puts("L");
				PORTB = 0b00000010;
				_delay_us(10);
			}else if(roll1 >= 5){
				uart_puts("R");
				PORTB = 0b00000001;
				_delay_us(10);
			}
			else
			{
				PORTB = 0b00000011;
				uart_puts("S");
				_delay_us(10);
			}
            //uart_puts("P:");
			//dtostrf(pitch1, 3, 0, itmp); uart_puts(itmp); uart_putc('-');
            
			//uart_puts("Y:");
            //dtostrf(yaw1, 3, 0, itmp); uart_puts(itmp); uart_putc('-');

        }
        else {
           
           uart_puts("calibrating...");
		   PORTB = 0x00;

        }
        
        
        uart_putc('\n');
        
        uart_putc('\n');
        
        
      
	}

}

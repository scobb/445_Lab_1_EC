// main.c
// Runs on LM4F120/TM4C123
// UART runs at 115,200 baud rate 
// Daniel Valvano
// May 23, 2014

/* This example accompanies the books
  "Embedded Systems: Introduction to ARM Cortex M Microcontrollers",
  ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2014

"Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2014
 
 Copyright 2014 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

#include <stdio.h>
#include <stdint.h> // C99 variable types
#include "UART.h"
#include "inc/tm4c123gh6pm.h"
#include "PLL.h"
void Output_Init(void);
float T; // temperature in C
uint32_t N; // 12-bit ADC value
void test_1(void){
	 for(N=0; N<4096; N++){
	     T = 10.0+ 0.009768*N;
	 }
} 
void Test2(void){
 for(N=0; N<4096; N++){
 T = 1000 + (125*N+64)>>7;
	}
 }

// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;               // disable SysTick during setup
  NVIC_ST_RELOAD_R = 0x00FFFFFF;    // maximum reload value
  NVIC_ST_CURRENT_R = 0;            // any write to current clears it
  NVIC_ST_CTRL_R = 0x05;            // enable SysTick with core clock
  
}
int main(void){
  PLL_Init();                      // bus clock at 80 MHz
  //Output_Init();              // initialize output device
		
	SysTick_Init();
	//printf("Hello world\n");
	//printf("Running test 1...\n");
	
  unsigned long before = NVIC_ST_CURRENT_R;
	test_1();
  unsigned long elapsed = (before-NVIC_ST_CURRENT_R)&0x00FFFFFF;
	int x = 5;
	//printf("Test one complete\n");
	//printf(" in %lu ms.\n", elapsed);
}

// version 1: C floating point
// run with compiler options selected for floating-point hardware
#include <stdint.h>
volatile float T; // temperature in C
volatile uint32_t N; // 12-bit ADC value
void Test1(void){
 for(N=0; N<4096; N++){
 T = 10.0+ 0.009768*N;
 }
} 
void Test2(void){
 for(N=0; N<4096; N++){
 T = 1000 + (125*N+64)>>7;
	}
 }
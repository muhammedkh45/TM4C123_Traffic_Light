/*
 * File:   SysTick.c
 * Author: Muhammed khalid
 * Created on June 10, 2024, 1:52 PM
 */
#include "stdint.h"
#include "tm4c123gh6pm.h"

/*TM4C123GH6PM using maximum frequency 80MHz*/

void SysTick_Init(long delay){
NVIC_ST_CTRL_R = 0;
NVIC_ST_RELOAD_R = delay-1;
NVIC_ST_CURRENT_R = 0;
NVIC_ST_CTRL_R = 0x05;
while((NVIC_ST_CTRL_R&0x00010000)==0);

}
void SysTick_Delay_1ms(int delay) {
int i=0;
	for(;i<delay;++i){
	SysTick_Init(80000);
	}
}

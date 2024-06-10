/*
 * File:   DIO.c
 * Author: Muhammed khalid
 * Created on June 10, 2024, 1:52 PM
 */

#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "Bit_Utilies.h"
void GPIO_Init(void){
	  //initialize port A
		SET_BIT(SYSCTL_RCGCGPIO_R,0);
		while(GET_BIT(SYSCTL_PRGPIO_R,0)==0){}
		SET(GPIO_PORTA_DEN_R,0xE0);
		SET(GPIO_PORTA_DIR_R,0xE0);		
		
		//initialize port B
   		SET_BIT(SYSCTL_RCGCGPIO_R,1);
	 	while(GET_BIT(SYSCTL_PRGPIO_R,1)==0){}
    		SET(GPIO_PORTB_DEN_R,0x13);	
		SET(GPIO_PORTB_DIR_R,0x13);
		
		//initialize port D
		SET_BIT(SYSCTL_RCGCGPIO_R,3); 
	  	while(GET_BIT(SYSCTL_PRGPIO_R,3)==0){}
		SET(GPIO_PORTD_DEN_R,0x07);	
		SET(GPIO_PORTD_DIR_R,0x07);
		
		//initialize port E
        SET_BIT(SYSCTL_RCGCGPIO_R,4);
	  	while(GET_BIT(SYSCTL_PRGPIO_R,4)==0){}
        SET(GPIO_PORTE_DEN_R,0x30);
	   	SET(GPIO_PORTE_DIR_R,0x30); 

				 // PORTF initialization
				SYSCTL_RCGCGPIO_R |= 0x20;
        while((SYSCTL_PRGPIO_R & 0x20) == 0);
				GPIO_PORTF_CR_R |= 0xFF;
				GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY ;
        GPIO_PORTF_AFSEL_R &= ~0xFF;
        GPIO_PORTF_AMSEL_R &=~0xFF;
        GPIO_PORTF_PCTL_R&=~0xFFFFFFFF;
        GPIO_PORTF_DEN_R |= 0x0E;
        GPIO_PORTF_DIR_R |= 0x0E;
}

/*
 * File:   APPLICATION.c
 * Author: Muhammed khalid
 * Created on June 10, 2024, 1:52 PM
 */
#include <stdint.h>
#include <stdio.h>
#include "MCAL/Systick.h"
#include "MCAL/DIO.h"
#include "MCAL/LCD.h"
#include <string.h>
#include "tm4c123gh6pm.h"

#define LED_RED 0x02
#define LED_YELLOW 0x0A
#define LED_GREEN 0x08

void delaySeconds(int seconds);

int main(void) {
    GPIO_Init();
    char Message_Stop[16] = "      Stop     ";
    char Message_Prepare[16] = "   Slow down   ";
    char Message_Go[15] = "   Proceed    ";
    char buffering[16];
    int i;

    while (1) {
        // Red light phase
        GPIO_PORTF_DATA_R = LED_RED;
        for (i = 55; i >= 0; --i) {
            LCD_Init();
            LCD_CMD(0x80);
            LCD_String_First_line(Message_Stop, strlen(Message_Stop));
            sprintf(buffering, "      %d      ", i);
            LCD_CMD(0xC0);
            LCD_String_Second_line(buffering, strlen(buffering));
            SysTick_Delay_1ms(800);
        }

        // Yellow light phase
        GPIO_PORTF_DATA_R = LED_YELLOW;
        for (i = 5; i >= 0; --i) {
            LCD_Init();
            LCD_CMD(0x80);
            LCD_String_First_line(Message_Prepare, strlen(Message_Prepare) );
            sprintf(buffering, "      %d      ", i);
            LCD_CMD(0xC0);
            LCD_String_Second_line(buffering, strlen(buffering) );
            SysTick_Delay_1ms(800);
        }

        // Green light phase
        GPIO_PORTF_DATA_R = LED_GREEN;
        for (i = 30; i >= 0; --i) {
            LCD_Init();
            LCD_CMD(0x80);
            LCD_String_First_line(Message_Go, strlen(Message_Go));
            sprintf(buffering, "      %d      ", i);
            LCD_CMD(0xC0);
            LCD_String_Second_line(buffering, strlen(buffering));
            SysTick_Delay_1ms(800);
        }
    }
}




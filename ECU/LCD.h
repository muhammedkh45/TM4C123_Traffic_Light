/*
 * File:   LCD.h
 * Author: Muhammed khalid
 * Created on June 10, 2024, 1:52 PM
 */
#ifndef LCD_H_
#define LCD_H_
#include<stdint.h>

void Print_Data(char data);
void LCD_Data (char data);
void LCD_CMD (char data);
void LCD_String_First_line (char* str ,char len);
void LCD_String_Second_line (char* str , char len);
void LCD_Init (void);
void myDelay(long  d);

#endif

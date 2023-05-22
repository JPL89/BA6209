// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		21/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#pragma config FOSC = HS        
#pragma config WDTE = OFF      
#pragma config PWRTE = OFF      
#pragma config MCLRE = ON       
#pragma config BOREN = OFF      
#pragma config LVP = OFF        
#pragma config CPD = OFF        
#pragma config CP = OFF  
#define _XTAL_FREQ 20000000

#include <xc.h>

#define BUTTON_1 PORTBbits.RB0
#define BUTTON_1_TRIS TRISBbits.TRISB0

#define BUTTON_2 PORTBbits.RB1
#define BUTTON_2_TRIS TRISBbits.TRISB1

#define FIN PORTBbits.RB2
#define FIN_TRIS TRISBbits.TRISB2

#define RIN PORTBbits.RB3
#define RIN_TRIS TRISBbits.TRISB3

unsigned char Status = 0;
unsigned char Direction = 0;

int main(void) 
{
    __delay_ms(250);        
    
    PORTA = 0x00;
    PORTB = 0x00;    
    
    CMCON = 0x07;
        
    BUTTON_1_TRIS = 1;
    BUTTON_2_TRIS = 1;
    RIN_TRIS = 0;
    FIN_TRIS = 0;
    
    while(1)
    {
        // ON - OFF
        if(!BUTTON_1){            
            if(Status) Status = 0;
            else Status = 1; 
            __delay_ms(250);
        }
        // DIRECTION
        if(!BUTTON_2){
            if(Direction) Direction = 0;
            else Direction = 1;
            
            if(Status){
                RIN = 0;
                FIN = 0;
            }
            else
            {
                if(Direction){
                RIN = 1;
                FIN = 0;
                }
                else{
                    RIN = 0;
                    FIN = 1;
                }
            }
            __delay_ms(250);
        }
    }
}

/*
 program to control a 7-segment using keypad
 requirements:
 - 4x3 | 4x4 keypad is connected at PORTA
 - use internal pull up resistors with keypad
 - 7 segment is connected at PORTC
 - get number from keypad and display it on 7-segment
*/

#include "keypad_driver.h"

int main(void)
{
	uint8_t keyNumber;
	DDRC  |= 0x0F;            
	PORTC &= (~(0xFF));       
    
	for(;;)
    {
        keyNumber = KeyPad_getPressedKey(); 

	    if((keyNumber >= 0) && (keyNumber <= 9))
		{ 
			 PORTC = keyNumber;
		}						
    }
}

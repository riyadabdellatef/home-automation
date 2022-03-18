/*
 * Keypad_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: riyad
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include<avr/io.h>
#include"Keypad_int.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
void Keypad_vidInit(void)
{
	DDRC=0b00001111; //nos el keypad input we nos output
	PORTC=0b11111111; //out put 5 v and input with pull resistance
}
u8 Keypad_u8GetKey(void)
{
	u8 temp;
	CLR_BIT(PORTC,0);
	SET_BIT(PORTC,1);
	SET_BIT(PORTC,2);
	SET_BIT(PORTC,3);
	//kda ktbt 1110
	temp = PINC&0b11110000; /*lw ana days 3la awl zorara fe al colum da m3naha
PINA 01111111 fkda natg al drb hykon 01110000 we dh awl zorara f3ln*/
	switch(temp)
	{
	case 0b11100000: return 1;
	case 0b11010000: return 2;
	case 0b10110000: return 3;
	case 0b01110000: return '+';
	}
	//hnkrr nfs al klam ll rows al b2ya
	SET_BIT(PORTC,0); // 3mlt set lly kan clear
	CLR_BIT(PORTC,1); // clear lly b3do
	temp = PINC&0b11110000; //read the new patern
	switch(temp)
	{
	case 0b11100000: return 4;
	case 0b11010000: return 5;
	case 0b10110000: return 6;
	case 0b01110000: return '-';
	}
	SET_BIT(PORTC,1);
	CLR_BIT(PORTC,2);
	temp = PINC&0b11110000;
	switch(temp)
	{
	case 0b11100000: return 7;
	case 0b11010000: return 8;
	case 0b10110000: return 9;
	case 0b01110000: return '*';
	}
	SET_BIT(PORTC,2);
	CLR_BIT(PORTC,3);
	temp = PINC&0b11110000;
	switch(temp)
	{
	case 0b11100000: return '#';
	case 0b11010000: return 0;
	case 0b10110000: return '=';
	case 0b01110000: return '/';
	}
	return KEYPAD_u8NO_KEY;
}
u8 Keypad_u8GetConstKey(void)
{u8 i=0;
u8 key ;
while(i==0)
{
while(key!=KEYPAD_u8NO_KEY )
	{
		key =Keypad_u8GetKey();
	}
_delay_ms(50);
while(key !=KEYPAD_u8NO_KEY )
	{key =Keypad_u8GetKey();
	}
key =Keypad_u8GetKey();
if((key>=0 && key<=9) || (key=='#') )
		{
			i++;
		}
}
return key ;
}

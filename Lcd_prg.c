/*
 * Lcd_prg.c
 *
 *  Created on: ??�/??�/????
 *      Author: riyad
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include"Dio_int.h"
#include"Lcd_cfg.h"
#include"Lcd_int.h"
void Lcd_vidSendCommand(u8 Cmd)
{
	Dio_vidSetPinVal(LCD_u8RS_PIN,DIO_u8LOW); //RS
	Dio_vidSetPinVal(LCD_u8RW_PIN,DIO_u8LOW); //RW
	//PORTD=Cmd;
	Dio_vidSetPinVal(LCD_u8D0_PIN,GET_BIT(Cmd,0));
	Dio_vidSetPinVal(LCD_u8D1_PIN,GET_BIT(Cmd,1));
	Dio_vidSetPinVal(LCD_u8D2_PIN,GET_BIT(Cmd,2));
	Dio_vidSetPinVal(LCD_u8D3_PIN,GET_BIT(Cmd,3));
	Dio_vidSetPinVal(LCD_u8D4_PIN,GET_BIT(Cmd,4));
	Dio_vidSetPinVal(LCD_u8D5_PIN,GET_BIT(Cmd,5));
	Dio_vidSetPinVal(LCD_u8D6_PIN,GET_BIT(Cmd,6));
	Dio_vidSetPinVal(LCD_u8D7_PIN,GET_BIT(Cmd,7));

	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8HIGH);; //EN
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8LOW) ; //EN
}

void Lcd_vidWriteChar(u8 Char)
{

	Dio_vidSetPinVal(LCD_u8RS_PIN,DIO_u8HIGH); //RS
	Dio_vidSetPinVal(LCD_u8RW_PIN,DIO_u8LOW); //RW
	//PORTD=Char;
	Dio_vidSetPinVal(LCD_u8D0_PIN,GET_BIT(Char,0));
	Dio_vidSetPinVal(LCD_u8D1_PIN,GET_BIT(Char,1));
	Dio_vidSetPinVal(LCD_u8D2_PIN,GET_BIT(Char,2));
	Dio_vidSetPinVal(LCD_u8D3_PIN,GET_BIT(Char,3));
	Dio_vidSetPinVal(LCD_u8D4_PIN,GET_BIT(Char,4));
	Dio_vidSetPinVal(LCD_u8D5_PIN,GET_BIT(Char,5));
	Dio_vidSetPinVal(LCD_u8D6_PIN,GET_BIT(Char,6));
	Dio_vidSetPinVal(LCD_u8D7_PIN,GET_BIT(Char,7));

	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8HIGH);; //EN
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN_PIN,DIO_u8LOW) ; //EN
}
void Lcd_vidInit(void)
{
	//DDRC=0xff; kol dol out put
	//DDRD=0xff; kol dol out put m3 any 3ayz 3 bs
	Dio_vidSetPinDir(LCD_u8RS_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RW_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8EN_PIN,DIO_u8OUTPUT);

	Dio_vidSetPinDir(LCD_u8D0_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D1_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D2_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D3_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D4_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D5_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D6_PIN,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D7_PIN,DIO_u8OUTPUT);

	Lcd_vidSendCommand(LCD_u8CMD_8_BIT_2x16_5x7);
	_delay_ms(2); //for give the command take it time before another command
	Lcd_vidSendCommand(LCD_u8CMD_DISP_ON_CURS_OFF);
	_delay_ms(2);
	Lcd_vidSendCommand(LCD_u8CMD_CLR_DISPLAY);
	_delay_ms(2);
}

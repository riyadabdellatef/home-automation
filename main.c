/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: riyad
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#include"Keypad_int.h"
#include"Lcd_int.h"
#include"secrt_int.h"
#include"Dio_int.h"
#include"Stepper_int.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
int main(void)
{
	u8 IDch;
	Keypad_vidInit(); //intialize
	u8 user[3];
	u8 key ;
	u8 mflag ;
	Stepper_vidInit();//dol kano any bkhly d5l al daling output
	//dol kano any bkhly d5l al daling output
	Dio_vidSetPinDir(DIO_u8PIN_14 ,DIO_u8OUTPUT);

	while(1)
	{IDch=0;
	mflag=0;
	while(mflag==0)
	{Lcd_vidInit();
	u8 i;
	u8 arr[8]="UserID:";
	for(u8 in=0;in<7;in++)
	{
		Lcd_vidWriteChar(arr[in]);
	}

	Lcd_vidSendCommand(0x88);
	for(i=0;i<=3 ;i++)
	{
		key =Keypad_u8GetConstKey();
		if(key=='#')
		{i=4;
		}
		else
		{
	Lcd_vidWriteChar(key+'0');
	user[i]=key;
		}
	}
	while(key!='#')
	{
		key =Keypad_u8GetConstKey();
	}
	if(user[0] == 0 && user[1] ==0 && user[2]==0 &&user[3]==0)
	{IDch =0;
	check_pas(0);
	mflag++;
	}
	else if(user[0] == 1 && user[1] ==1 && user[2]==1 &&user[3]==1)
	{IDch=0;
	check_pas(1);
	mflag++;
	}
	else if(user[0] == 2 && user[1] ==2 && user[2]==2 &&user[3]==2)
	{IDch=0;
	check_pas(2);
	mflag++;
	}
	else
	{
		Lcd_vidInit();
		u8 a[16]="invalid user ID";
		for(u8 in=0;in<15;in++)
		{
			Lcd_vidWriteChar(a[in]);
		}
		Bazz_vidTurn(2,0 );
		IDch++;

	}
	if(IDch==3)
	{Lcd_vidInit();
	u8 arr[19]="invalid ID 3 times";
	for(u8 in=0;in<18;in++)
	{
		Lcd_vidWriteChar(arr[in]);
	}
	Lcd_vidSendCommand(0xc0);
	u8 arr1[13]="System close";
		for(u8 in=0;in<12;in++)
		{
			Lcd_vidWriteChar(arr1[in]);
		}

	while(1){Bazz_vidTurn(2,1 );}
	}
	}

}
	return 0;
}
void welcome(void)
{
	Lcd_vidInit();
	Lcd_vidSendCommand(0x85);
	u8 arrr[8]="Welcome";
	for(u8 in=0;in<7;in++)
	{
		Lcd_vidWriteChar(arrr[in]);
	}

}



void check_pas(u8 ID)
{  u8 pwch=0;
u8 	Pas[3];
u8 key;
u8 j;
u8 flag =0;
while(flag==0)
{

	for(u8 i=0xc0;i<=0xcf ;i++)
	{	Lcd_vidSendCommand(i);
	Lcd_vidWriteChar(' ');
	}
	Lcd_vidSendCommand(0xc0);
	u8 ar[10]="Password:";
	for(u8 in=0;in<9;in++)
	{
		Lcd_vidWriteChar(ar[in]);
	}

	for(j=0;j<=3 ;j++)
	{key =Keypad_u8GetConstKey();
	if(key=='#')
			{j=4;
			}
	else
	{
	Lcd_vidWriteChar(key+'0');
	Pas[j]=key;
	}
	}
	while(key!='#')
	{
		key =Keypad_u8GetConstKey();
	}

	if(Pas[0] == 0 && Pas[1] ==0 && Pas[2]==0 &&Pas[3]==0 &&ID==0)
	{
		welcome();
		Stepper_vidRight(180);
		_delay_ms(1000);
		Stepper_vidLeft(180);
		pwch=0;
		flag++;
	}
	else if(Pas[0] == 1 && Pas[1] ==1 && Pas[2]==1 &&Pas[3]==1 &&ID==1)
	{
		welcome();
		Stepper_vidRight(180);
			_delay_ms(1000);
			Stepper_vidLeft(180);
		pwch=0;
		flag++;
	}
	else if(Pas[0] == 2 && Pas[1] ==2 && Pas[2]==2 &&Pas[3]==2 &&ID==2)
	{
		welcome();
		Stepper_vidRight(180);
			_delay_ms(1000);
			Stepper_vidLeft(180);
	pwch=0;
	flag++;
	}
	else
	{Lcd_vidSendCommand(0xc0);
	u8 arr[17]="Invalid Password";
	for(u8 in=0;in<16;in++)
	{
		Lcd_vidWriteChar(arr[in]);
	}
	Bazz_vidTurn(3,0 );
	pwch++;
	}

if(pwch==3)
{Lcd_vidInit();
u8 arr[17]="Wrong PW 3 times";
for(u8 in=0;in<16;in++)
{
	Lcd_vidWriteChar(arr[in]);

}

Lcd_vidSendCommand(0xc0);
 u8 arr1[13]="System close";
	for(u8 in=0;in<12;in++)
	{
		Lcd_vidWriteChar(arr1[in]);
	}

while(1)
{
	Bazz_vidTurn(2,1 );
}
}
}
}

/*
 * Stepper_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: riyad
 */
#include"../Lib/Std_types.h"
#include"../Lib/Bit_math.h"
#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include"Dio_int.h"
#include"Stepper_int.h"
#include"Stepper_cfg.h"

void Stepper_vidRight(u16 angle)
{
	u16 j;
	j=0;
	while(j<(1.42 *angle))
	{
		Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8HIGH);
		Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
		//awl step b3dha n3ml delay 3la ma ywsl ltnay step
		_delay_us(1300);
		Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8HIGH);
		Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
		//tani step
		_delay_us(1300);
		Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8HIGH);
		Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
		_delay_us(1300);
		Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8HIGH);
		_delay_us(1300);
		j++;
	}

}
void Stepper_vidLeft(u16 angle)
{
	u16 j;
	j=0;
	while(j<(1.42 *angle))
	{


		Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8HIGH);
		_delay_us(1300);
		Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8HIGH);
		Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
		_delay_us(1300);
		Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8HIGH);
		Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
		//tani step
		_delay_us(1300);
		Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8HIGH);
		Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
		Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
		//awl step b3dha n3ml delay 3la ma ywsl ltnay step
		_delay_us(1300);

		j++;
	}

}
void Stepper_vidTurnOnLeft(void)
{
	Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8HIGH);
			_delay_us(1300);
			Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
			_delay_us(1300);
			Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
			//tani step
			_delay_us(1300);
			Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
			//awl step b3dha n3ml delay 3la ma ywsl ltnay step
			_delay_us(1300);

}
void Stepper_vidTurnOnRight(void)
{

	Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
			//awl step b3dha n3ml delay 3la ma ywsl ltnay step
			_delay_us(1300);
			Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
			//tani step
			_delay_us(1300);
			Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
			_delay_us(1300);
			Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8HIGH);
			_delay_us(1300);

}
void Stepper_vidTurnOff(void)
{

	       Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_3,DIO_u8LOW);
}
void Stepper_vidInit(void)
{
	Dio_vidSetPinDir(ULN2003_u8PIN_0,DIO_u8OUTPUT);
	Dio_vidSetPinDir(ULN2003_u8PIN_1,DIO_u8OUTPUT);
	Dio_vidSetPinDir(ULN2003_u8PIN_2,DIO_u8OUTPUT);
	Dio_vidSetPinDir(ULN2003_u8PIN_3,DIO_u8OUTPUT);
}


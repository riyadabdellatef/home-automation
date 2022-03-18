/*
 * Stepper.c
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
#include"secrt_int.h"

void Bazz_vidTurn(u8 secondtimeon,u8 secondtimeoff)
	{

    Dio_vidSetPinVal(DIO_u8PIN_14 ,DIO_u8HIGH);
		_delay_ms(secondtimeon*1000);
		Dio_vidSetPinVal(DIO_u8PIN_14 ,DIO_u8LOW);
		_delay_ms(secondtimeoff*1000);

	}




/*
 * main.c
 *
 *  Created on: Feb 1, 2024
 *      Author: Raghad Islam
 */
#include "STDTypes.h"
#include "errorState.h"
#include <util/delay.h>

#include "DIO_int.h"

#include"Seven_segment_config.h"
#include "Seven_segment_int.h"

extern SEG_t SEVSEG_AstrConfig[NUM_OF_SEG];


int main()
{
	/* initialize 7 seg */

	Seven_segment_enuInit(SEVSEG_AstrConfig);
	Seven_segment_enuDisableCommon(0);
	Seven_segment_enuDisableCommon(1);

	while(1)
	{
		/* disable seg 1 */
		Seven_segment_enuDisableCommon(0);

		/* put number */
		Seven_segment_enuDisplayNum(0,3);

		/* enable seg 2 */
		Seven_segment_enuEnableCommon(1);

		//TIMER_enuSetDesiredTime_us(TIMER0,15000);
		_delay_ms(15);

		/* disable seg 2*/
		Seven_segment_enuDisableCommon(1);


		/* put number */
		Seven_segment_enuDisplayNum(1,7);

		/* enable seg 1 */
		Seven_segment_enuEnableCommon(0);

		//TIMER_enuSetDesiredTime_us(TIMER0,15000);
		_delay_ms(15);


	}
	return 0;
}













//int main()
//{
//	/* set pins as output */
//	DIO_enuSetPortDir(DIO_u8PORTC, 0xff);
//	DIO_enuSetPinDir(DIO_u8PORTD,DIO_u8PIN0,DIO_u8OUTPUT);
//	DIO_enuSetPinDir(DIO_u8PORTD,DIO_u8PIN1,DIO_u8OUTPUT);
//
//
//	DIO_enuSetPinVal(DIO_u8PORTD,DIO_u8PIN0,DIO_u8HIGH);  // disable seg 1
//	DIO_enuSetPinVal(DIO_u8PORTD,DIO_u8PIN1,DIO_u8HIGH); // disable seg 2
//
//
//	u8 SEVEN_SEG [] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
//
//	while(1)
//	{
//		/* disable seg 1 */
//		DIO_enuSetPinVal(DIO_u8PORTD,DIO_u8PIN0,DIO_u8HIGH);
//
//		/* put number */
//		DIO_enuSetPortVal(DIO_u8PORTC,SEVEN_SEG[3]);
//
//		/* enable seg 2 */
//		DIO_enuSetPinVal(DIO_u8PORTD,DIO_u8PIN1,DIO_u8LOW);
//
//		_delay_ms(15);
//
//		/* disable seg 2*/
//		DIO_enuSetPinVal(DIO_u8PORTD,DIO_u8PIN1,DIO_u8HIGH);
//
//		/* put number */
//		DIO_enuSetPortVal(DIO_u8PORTC,SEVEN_SEG[5]);
//
//		/* enable seg 1 */
//		DIO_enuSetPinVal(DIO_u8PORTD,DIO_u8PIN0,DIO_u8LOW);
//		_delay_ms(15);
//	}
//	return 0;
//}


/*
 * main.c
 *
 *  Created on: ١٩‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */
#define F_CPU 16000000UL

#include<math.h>
#include<string.h>
#include<util/delay.h>
#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_int.h"
#include"LCD_int.h"

#if(1)



void main()
{

	H_LCD_void_Init();
	H_LCD_void_sendString("HELLO Muhsen ");
	_delay_ms(500);
	H_LCD_void_clear();
	H_LCD_void_gotXY(1,0);
	H_LCD_void_sendIntNum(125);
	_delay_ms(500);
	H_LCD_void_clear();

	while(1)
	{

	}
}

#endif

#if (0)
void main (void)
{
   u16 readAdc = 0;
	H_LCD_void_Init();
	M_ADC_voidInit(prescaler_2, vref_Avcc);
	while(1)
	{
		readAdc = M_ADC_voidRead(channel0);
		      H_LCD_void_sendData(((readAdc/100)%10)+48);
				H_LCD_void_sendData(((readAdc/10)%10)+48);
				H_LCD_void_sendData((readAdc%10)+48);
				_delay_ms(400);
				H_LCD_void_clear();
	}
}


#endif

#if (0)
static u16 Reading1=0;
static u16 Reading2=0;
static u8 stateCounter=0;
//u16 NumberOfTicks;


void ICU_HW(void);

void main()
{
	    u16 NumberOfTicks=0;
		f32 time =0;
	    u32 Distance =0;
	// LCD INIT
	H_LCD_void_Init();
	//SET DIR FOR PWM PIN TO BE OUT
	M_DIO_void_setPinDir(PORTB_ID,PIN3, OUT);
	//SET DIR FOR ICU PIN TO BE IN
	M_DIO_void_setPinDir(PORTD_ID,PIN6, IN);
	//SET DIR FOR trigger PIN TO BE out
	M_DIO_void_setPinDir(PORTC_ID,PIN5, OUT);
	//ICU INIT
	M_TIMER1_ICU_void_Init();
	// ENABLE INTERRUPT
	M_TIMER1_ICU_void_INTEnable();
	M_TIMER1_ICU_void_setCallback(ICU_HW);
	//TIMER0 INIT

	// GIE ENABLE
	M_GIE_void_enable();
	 //TIMER 1 INITIALIZAION
		M_TIMER1_void_Init();

	while(1)
	{
		  //send trigger
			M_DIO_void_setPinValue(PORTC_ID,PIN5, HIGH);
			_delay_ms(10);
			M_DIO_void_setPinValue(PORTC_ID,PIN5, LOW);

			while (stateCounter<=1);//busy waitind untill all reading are ready
			stateCounter=0;
			 NumberOfTicks=Reading2-Reading1;
			 time =(NumberOfTicks*16)/1000000.0;
		     Distance =ceil((time/2)*34300);

		/*//display reading 1
		//H_LCD_void_sendString("Reading1");
		//(1,5);
		//H_LCD_void_sendIntNum(Reading1);
		//_delay_ms(2000);
		H_LCD_void_clear();
		display reading 2
		H_LCD_void_sendString("Reading2");
		H_LCD_void_gotXY(1,5);
		H_LCD_void_sendIntNum(Reading2);
		_delay_ms(2000);
		H_LCD_void_clear();*/
		//display distance
		H_LCD_void_sendString("Distance");
		H_LCD_void_gotXY(1,5);
		H_LCD_void_sendIntNum(Distance);
		_delay_ms(200);
		H_LCD_void_clear();


	}
}
void ICU_HW(void)
{
	if (stateCounter==0)
	{
		//take reading 1
		Reading1=M_TIMER1_ICU_u16_takeReading();
		//change trigger to fallin edge
		M_TIMER1_ICU_void_setTrigg(TIMER1_ICU_FALL_TRIGG);
	}
	else if (stateCounter==1)
	{
		//take reading 2
		Reading2=M_TIMER1_ICU_u16_takeReading();
		//M_TIMER1_ICU_void_INTDisable();
		M_TIMER1_ICU_void_setTrigg(TIMER1_ICU_RISING_TRIGG);
	}

	stateCounter++;
}


#endif

#if(0)
 u8 kvalue;
int main (void){

	H_LCD_void_Init();
    H_KEYPAD_void_init();
	while(1)
	{
		kvalue=H_KEYPAD_void_getPressedKey();
		if(kvalue!=NUM_PRESSED_KEY)
		{
			H_LCD_void_sendData(kvalue) ;
			_delay_ms(500) ;
		   H_LCD_void_clear() ;
		}

		//H_LCD_void_sendString("ahmed1") ;

	}
}

#endif

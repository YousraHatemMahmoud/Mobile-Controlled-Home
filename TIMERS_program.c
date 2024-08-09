#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include"DIO_interface.h"

#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
void (*Global_pvCTCFunction)(void)=NULL;
void (*Global_pvICUFunction)(void)=NULL;
void (*Global_pvTimer1OvfFunction)(void)=NULL;
void (*Global_pvTimer0CTCFunction)(void)=NULL;

u8 Global_u8SingleFlag=0;

//-----------------------Timer0 Functions------------------------------------------

void TIMERS_voidTimer0Init(void)
{

#if TIMER0_MODE==CTC
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

#if TIMER0_CTC_MODE==NORMAL
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);

#endif

#elif TIMER0_MODE==FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

#if FAST_PWM_MODE==CLEAR_ON_COMPARE_SET_AT_TOP
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#endif



#endif



#if TIMER0_PRESCALLER==DIVIDE_BY_1
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

#elif TIMER0_PRESCALLER==DIVIDE_BY_8
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif  TIMER0_PRESCALLER==DIVIDE_BY_64
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);


#endif



#if TIMER0_COMPARE_MATCH_INTERRUPT_ENABLE==ENABLE

	SET_BIT(TIMSK,TIMSK_OCIE0);

#elif TIMER0_COMPARE_MATCH_INTERRUPT_ENABLE==DISABLE

	CLR_BIT(TIMSK,TIMSK_OCIE0);
#endif



}


void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue)
{
	OCR0=Copy_u8CompareMatchValue;
}


void TIMERS_voidTimer0SetIntervalPeriodic(u8 Copy_u8Ticks, void(*CallbackFunction)(void))
{     // Set call back
	Global_pvTimer0CTCFunction=CallbackFunction;
	Global_u8SingleFlag=0;

	//reset timer value and clear flag
	TIMERS_voidTimer0SetPreLoadValue(0);

	//load CTC
	TIMERS_voidTimer0SetCompareMatchValue(Copy_u8Ticks);

	//start the timer
	SET_BIT(TIMSK,TIMSK_OCIE0);

}

void TIMERS_voidTimer0SetPreLoadValue(u8 Copy_u8PreLoadValue)
{
	TCNT0=Copy_u8PreLoadValue;
}

void TIMERS_voidTimer0CTCSetCallBackFunction(void (*Copy_pvCTCFunction)(void))
{
	Global_pvTimer0CTCFunction =Copy_pvCTCFunction;
}

void TIMERS_voidSetBusyWaitTimer0_ms(u32 Copy_u32Time_ms)
{
	u32 Local_counter1;
	u32 Local_counter2;
	TIMERS_voidTimer0SetCompareMatchValue(250);
	for(Local_counter1=1; Local_counter1<=Copy_u32Time_ms;Local_counter1++ )
	{
		for(Local_counter2=1; Local_counter2<=4;Local_counter2++ )
		{
			while(GET_BIT(TIFR,TIFR_OCF0)==0)
			{
				//do nothing
			}
			SET_BIT(TIFR,TIFR_OCF0);

		}
	}


}
void __vector_10 (void)  __attribute__((signal));
void __vector_10 (void)
{
	if(Global_pvTimer0CTCFunction!=NULL)
	{

		Global_pvTimer0CTCFunction();


	}
	else
	{
		/*Do Nothing*/
	}

}



//----------------------------Timer1 Functions-------------------------------


void TIMERS_voidTimer1Init(void)
{
	//set prescaller div by 8
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

}
void TIMERS_voidTimer1SetNormalMode(void)
{

	//Normal mode
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	//enable interrupt
	SET_BIT(TIMSK,TIMSK_TOIE1);
}
void TIMERS_voidTimer1DisableNormalMode(void)
{

	//Disable interrupt
	CLR_BIT(TIMSK,TIMSK_TOIE1);
}

void TIMERS_voidTimer1SetMode14(void)
{
	//Set PWM non inverting Mode
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	//set mode 14--Wave form Generation
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
}
void TIMERS_voidTimer1DisableMode14(void)
{
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	//set mode 14--Wave form Generation
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
}



void TIMERS_voidTimer1ChannelASetCompareMatchValue(u16 Copy_u16CompareMatchValue)
{
	OCR1A=Copy_u16CompareMatchValue;
}

void TIMERS_voidTimer1SetOverFlowValue(u16 Copy_16OverFlowValue )
{
	ICR1=Copy_16OverFlowValue;
}

void TIMERS_voidTimer1SetPreloadValue(u16 Copy_u16Value)
{
	TCNT1=Copy_u16Value;
}
u16  TIMERS_voidGetTimer1Value(void)
{
	return TCNT1;
}



void TIMERS_voidTimer1OVFSetCallBackFunction(void (*Copy_pvOvfFunction)(void))
{
	Global_pvTimer1OvfFunction =*Copy_pvOvfFunction;
}


void TIMERS_voidTimer1ClearOverFlowFlag(void)
{
	SET_BIT(TIFR,TIFR_ICF1);
}
void ICU_voidClearICPFlag(void)
{
	SET_BIT(TIFR,TIFR_TOV1);
}

void __vector_9 (void)  __attribute__((signal));
void __vector_9 (void)
{
	if(Global_pvTimer1OvfFunction!=NULL)
	{
		Global_pvTimer1OvfFunction();
	}
	else
	{
		/*Do Nothing*/
	}


}


//-----------------------Timer2 Functions--------------------------

void TIMERS_voidTimer2Init(void)
{
#if TIMER2_MODE==CTC
	CLR_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

#if TIMER2_CTC_MODE==NORMAL
	CLR_BIT(TCCR2,TCCR2_COM20);
	CLR_BIT(TCCR2,TCCR2_COM21);

#endif

#elif TIMER2_MODE==FAST_PWM
	SET_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

#if TIMER2_FAST_PWM_MODE==CLEAR_ON_COMPARE_SET_AT_TOP
	CLR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);
#endif



#endif



#if TIMER2_PRESCALLER==DIVIDE_BY_1
	SET_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);

#elif TIMER2_PRESCALLER==DIVIDE_BY_8
	CLR_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);
#elif  TIMER2_PRESCALLER==DIVIDE_BY_64
	SET_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);


#endif



#if TIMER2_COMPARE_MATCH_INTERRUPT_ENABLE==ENABLE

	SET_BIT(TIMSK,TIMSK_OCIE2);

#elif TIMER2_COMPARE_MATCH_INTERRUPT_ENABLE==DISABLE

	CLR_BIT(TIMSK,TIMSK_OCIE2);
#endif





}

void TIMERS_voidTimer2SetCompareMatchValue(u8 Copy_u8CompareMatchValue)
{
	OCR2=Copy_u8CompareMatchValue;
}



void TIMERS_voidTimer2SetPreLoadValue(u8 Copy_u8PreLoadValue)
{
	TCNT2=Copy_u8PreLoadValue;
}

void TIMERS_voidSetBusyWaitTimer2_ms(u32 Copy_u32Time_ms)
{
	u32 Local_counter1;
	u32 Local_counter2;
	TIMERS_voidTimer2SetCompareMatchValue(250);
	for(Local_counter1=1; Local_counter1<=Copy_u32Time_ms;Local_counter1++ )
	{
		for(Local_counter2=1; Local_counter2<=4;Local_counter2++ )
		{
			while(GET_BIT(TIFR,TIFR_OCF2)==0)
			{
				//do nothing
			}
			SET_BIT(TIFR,TIFR_OCF2);

		}
	}


}


//----------------------ICU Functions---------------------------------



void ICU_voidSetSenseControl(u8 Copy_u8SenseControl)
{
	switch(Copy_u8SenseControl)
	{
	case FALLING_EDGE:
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
		break;

	case RISING_EDGE:
		SET_BIT(TCCR1B,TCCR1B_ICES1);
		break;
	}
}

void ICU_voidSetCallBackFunction(void (*Copy_pvNotificationFunction)(void))
{
	Global_pvICUFunction=Copy_pvNotificationFunction;
}


u16 ICU_u16ReadInputCapture(void)
{
	return ICR1;
}

void ICU_voidInterruptControl(u8 Copy_u8InterruptState)
{
	switch(Copy_u8InterruptState)
	{
	case ENABLE:
		SET_BIT(TIMSK,TIMSK_TICIE1);

		break;
	case DISABLE:
		CLR_BIT(TIMSK,TIMSK_TICIE1);
		break;

	}
}


void __vector_6 (void)  __attribute__((signal));
void __vector_6 (void)
{
	if(Global_pvICUFunction!=NULL)
	{
		Global_pvICUFunction();
	}
	else
	{
		/*Do Nothing*/
	}


}





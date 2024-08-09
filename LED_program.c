/**********************************************************/
/**********************************************************/
/**************		Author	: Yousra Hatem		***********/ 
/**************		Layer	: HAL				***********/ 
/**************		SWC		: LED				***********/ 
/**************		Version	: 1.00				***********/ 
/**********************************************************/
/**********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"



void LED_voidInit()
{
	DIO_voidSetPinDirection(LED_PORT,LED_PIN,OUTPUT);
}

void LED_voidTurnOn()
{
	DIO_voidSetPinValue(LED_PORT,LED_PIN,HIGH);
}

void LED_voidTurnOff()
{
	DIO_voidSetPinValue(LED_PORT,LED_PIN,LOW);
}



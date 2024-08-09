
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "BUZZER_config.h"
#include "BUZZER_interface.h"
#include "BUZZER_private.h"



void BUZZER_voidInit()
{
	DIO_voidSetPinDirection(BUZZER_PORT,BUZZER_PIN,OUTPUT);
}

void BUZZER_voidTurnON()
{
	DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,HIGH);
}

void BUZZER_voidTurnOFF()
{
	DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,LOW);
}

#include"STD_TYPES.h"

#include "DIO_interface.h"
#include "TIMERS_interface.h"

#include "SERVO_config.h"
#include "SERVO_interface.h"
#include "SERVO_private.h"

void HSERVO_voidInit(void)
{
	DIO_voidSetPinDirection(PORTD,PIN5,OUTPUT);
	TIMERS_voidTimer1SetOverFlowValue(20000);

}
void HSERVO_voidTurnRight(void)
{
	TIMERS_voidTimer1ChannelASetCompareMatchValue(SERVO_TURN_RIGHT);
}

void HSERVO_voidTurnLeft(void)
{
	TIMERS_voidTimer1ChannelASetCompareMatchValue(SERVO_TURN_LEFT);
}

void HSERVO_voidLookForward(void)
{
	TIMERS_voidTimer1ChannelASetCompareMatchValue(SERVO_LOOK_FORWARD);
}







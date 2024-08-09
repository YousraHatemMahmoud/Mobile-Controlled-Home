/*
 * main.c
 *
 *  Created on: Dec 29, 2023
 *      Author: Mohamed
 */
#include <util/delay.h>
#include <string.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "USART_interface.h"

#include "LCD_interface.h"
#include "LED_interface.h"
#include "SERVO_interface.h"
#include "BUZZER_interface.h"


#define MAX_NAME_LENGTH 20
#define NUM_NAMES 10
#define NUM_PASS  10

char names[NUM_NAMES][MAX_NAME_LENGTH] = {"omar","ali","mohamed","mahmoud","yousra","soad","malak","hana","fatma","hanan"};
u32 Passwords[NUM_PASS] = {1234,1234,1234,1234,1234,1234,1234,1234,1234,1234};


void main()
{
	/*Local variable to receive the user name*/
	char receivedName[MAX_NAME_LENGTH];

	/*Local variable to receive the user password*/
	u32 receivedNumber,option_num;

	/*Local variables*/
	u8 name_index=-1,i,pass_index=-1;

	/*Initiate MCAL Functions*/
	TIMERS_voidTimer1Init();
	TIMERS_voidTimer1SetMode14();
	USART_voidInit();

	/*Initiate HAL Functions*/
	HSERVO_voidInit();
	BUZZER_voidInit();
	LCD_voidInit();
	LED_voidInit();


	while(1)
	{
		u8 Name_Counter=0,Pass_Counter=0,Option_Flag=1;
		name_index=-1;
		pass_index=-1;

		USART_voidTransmitString("Welcome");
		USART_TransmitData(0x0D);
		_delay_ms(500);

		while(Name_Counter != 3)
		{
			USART_voidTransmitString("Enter Your name");
			USART_TransmitData(0x0D);

			USART_voidReceiveString(receivedName);

			/*Check if the name is correct*/
			USART_voidTransmitString("Checking Name... ");
			USART_TransmitData(0x0D);
			_delay_ms(1000);
			for(i=0;i<NUM_NAMES;i++)
			{
				if (strcmp(names[i], receivedName) == 0)
				{
					USART_voidTransmitString("Name Match Found!\n");
					USART_TransmitData(0x0D);
					_delay_ms(500);
					name_index = i;
					break;
				}
			}

			if(name_index > -1 && name_index < NUM_NAMES)
			{
				Name_Counter = 3;
				USART_voidTransmitString("Welcome, ");
				USART_voidTransmitString(receivedName);
				USART_TransmitData(0x0D);
				_delay_ms(500);

				while(Pass_Counter != 3)
				{
					USART_voidTransmitString("Enter Your Password");
					USART_TransmitData(0x0D);
					receivedNumber = USART_u32ReceiveNumber();

					/*Check if the password is correct*/
					USART_voidTransmitString("Checking Password... ");
					USART_TransmitData(0x0D);
					_delay_ms(1000);
					for(i=0;i<NUM_PASS;i++)
					{
						if(receivedNumber == Passwords[i])
						{
							pass_index = i;
							USART_voidTransmitString("Correct Password!\n");
							USART_TransmitData(0x0D);
							_delay_ms(500);
							break;
						}
					}
					if(pass_index > -1 && pass_index < NUM_PASS)
					{
						Pass_Counter = 3;
						while(Option_Flag)
						{
							USART_voidTransmitString("1- Open the Door");
							USART_TransmitData(0x0D);

							USART_voidTransmitString("2- Close the Door");
							USART_TransmitData(0x0D);

							USART_voidTransmitString("3- Turn On the Light");
							USART_TransmitData(0x0D);

							USART_voidTransmitString("4- Turn Off the Light");
							USART_TransmitData(0x0D);

							USART_voidTransmitString("5- End the session");
							USART_TransmitData(0x0D);

							option_num = USART_u32ReceiveNumber();

							switch(option_num)
							{
							case 1:
								LCD_voidClear();
								LCD_voidSendString("Door is open");
								HSERVO_voidTurnLeft();
								break;

							case 2:
								LCD_voidClear();
								LCD_voidSendString("Door is closed");
								HSERVO_voidTurnRight();
								break;

							case 3:
								LCD_voidClear();
								LCD_voidSendString("light is turnOn");
								LED_voidTurnOn();
								break;

							case 4:
								LCD_voidClear();
								LCD_voidSendString("light is turnOff");
								LED_voidTurnOff();
								break;

							case 5:
								Option_Flag=0;
								LCD_voidClear();
								LCD_voidSendString("Session is Ended");
								break;

							default :
								USART_voidTransmitString("Wrong Option");
							}
						}

					}
					else
					{
						Pass_Counter++;
						if(Pass_Counter == 3)
						{
							USART_voidTransmitString("Wrong Password");
							BUZZER_voidTurnON();
							_delay_ms(2000);
							BUZZER_voidTurnOFF();
						}
						else
						{
							USART_voidTransmitString("Wrong Password, Try again");
							USART_TransmitData(0x0D);
							_delay_ms(500);
						}
					}
				}
			}
			else
			{
				Name_Counter++;
				if(Name_Counter == 3)
				{
					USART_voidTransmitString("Wrong Name");
					LCD_voidClear();
					LCD_voidSendString("Buzzer is turnOn");
					BUZZER_voidTurnON();
					_delay_ms(2000);
					LCD_voidClear();
					LCD_voidSendString("Buzzer is turnOff");
					BUZZER_voidTurnOFF();
				}
				else
				{
					USART_voidTransmitString("Wrong Name, Try again");
					USART_TransmitData(0x0D);
					_delay_ms(500);

				}
			}
		}
		USART_TransmitData(0x0D);
		USART_TransmitData(0x0D);
		_delay_ms(1500);
	}
}






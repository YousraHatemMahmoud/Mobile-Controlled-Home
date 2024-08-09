#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void USART_voidInit(void)
{//set URSEL to write on UCSRC

u8 Local_u8UCSRC_value=0;
 SET_BIT( Local_u8UCSRC_value, UCSRC_URSEL);

	// Data size=8 bit

  #if USART_DATA_SIZE==BIT_5
	CLR_BIT(Local_u8UCSRC_value,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRC_value,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

  #elif USART_DATA_SIZE==BIT_6
	SET_BIT(Local_u8UCSRC_value,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRC_value,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

  #elif USART_DATA_SIZE==BIT_7
	CLR_BIT(Local_u8UCSRC_value,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC_value,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

  #elif USART_DATA_SIZE==BIT_8
	SET_BIT(Local_u8UCSRC_value,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC_value,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

  #elif USART_DATA_SIZE==BIT_9
	SET_BIT(Local_u8UCSRC_value,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC_value,UCSRC_UCSZ1);
	SET_BIT(UCSRB,UCSRB_UCSZ2);

  #else
    #error  "DATA_SIZE ERROR Configuration"
  #endif
	//stop bit=1
 #if USART_STOP_BIT_SELECT== BIT_1
	CLR_BIT(Local_u8UCSRC_value,UCSRC_USBS);

 #elif USART_STOP_BIT_SELECT==BIT_2
	SET_BIT(Local_u8UCSRC_value,UCSRC_USBS);

#else
    #error  "STOP_BIT_SELECT ERROR Configuration"
 #endif

	//parity Mode=disable
  #if USART_PARITY_MODE==DISABLED
	CLR_BIT(Local_u8UCSRC_value,UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRC_value,UCSRC_UPM1);

  #elif USART_PARITY_MODE==RESERVED
	    SET_BIT(Local_u8UCSRC_value,UCSRC_UPM0);
		CLR_BIT(Local_u8UCSRC_value,UCSRC_UPM1);

  #elif  USART_PARITY_MODE==ENABLED_ENEN_PARITY
	    CLR_BIT(Local_u8UCSRC_value,UCSRC_UPM0);
		SET_BIT(Local_u8UCSRC_value,UCSRC_UPM1);

  #elif  USART_PARITY_MODE==ENABLED_ODD_PARITY
	    SET_BIT(Local_u8UCSRC_value,UCSRC_UPM0);
		SET_BIT(Local_u8UCSRC_value,UCSRC_UPM1);
 #else
    #error  "PARITY_MODE_SELECT ERROR Configuration"

 #endif


	//USART mode= Asychnronous
   #if USART_MODE_SELECT==ASYNCHRONOUS
	CLR_BIT(Local_u8UCSRC_value,UCSRC_UMSEL);

   #elif USART_MODE_SELECT==SYNCHRONOUS
	SET_BIT(Local_u8UCSRC_value,UCSRC_UMSEL);

   #else
     #error  "USART_MODE_SELECT ERROR Configuration"
  #endif

#if RX_Complete_Interrupt==DISABLED

	CLR_BIT(UCSRB,UCSRB_RXCIE);

#elif RX_Complete_Interrupt==ENABLED

	SET_BIT(UCSRB,UCSRB_RXCIE);

#endif

#if TX_Complete_Interrupt==DISABLED

	CLR_BIT(UCSRB,UCSRB_TXCIE);

#elif TX_Complete_Interrupt==ENABLED

	SET_BIT(UCSRB,UCSRB_TXCIE);

#endif

#if USART_Data_Register_Empty_Interrupt==DISABLED
	CLR_BIT(UCSRB,UCSRB_UDRIE);


#elif USART_Data_Register_Empty_Interrupt==ENABLED
	SET_BIT(UCSRB,UCSRB_UDRIE);

#endif

	UCSRC=Local_u8UCSRC_value;


	//Baud Rate =9600

	//u32 Local_u32UBRR_Value=((CPU_CLK)/(16*USART_BAUD_RATE))-1;

		UBRRL=51;//Local_u32UBRR_Value;



	//Transmitter and enable circuit enable
#if USART_TRANSMIT_ENABLE==ENABLE
	SET_BIT(UCSRB,UCSRB_TXEN);

#elif USART_TRANSMIT_ENABLE==DISABLE
	CLR_BIT(UCSRB,UCSRB_TXEN);

#endif

#if USART_RECIEVE_ENABLE==ENABLE
	SET_BIT(UCSRB,UCSRB_RXEN);

#elif USART_RECIEVE_ENABLE==DISABLE
	CLR_BIT(UCSRB,UCSRB_RXEN);

#endif






}

void USART_TransmitData(u8 Copy_u8Data)
{   /*polling on the UDR flag*/
	//wait until transmit data buffer in empty
	 while(GET_BIT(UCSRA,UCSRA_UDRE)==0);

	  //clear flag
	 SET_BIT(UCSRA,UCSRA_UDRE);

	/*copy the data to be transmitted to the UDR register*/
	UDR = Copy_u8Data;

}

u8 USART_u8ReceiveData(void)
{
	/*polling(Busy Wait) on the RXC flag */
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);

	return  UDR;

}

void USART_TransmitNumber(u32 Copy_u32Number)
{   u8 Local_u8Digit;

	while(Copy_u32Number>0)
	{
		Local_u8Digit=Copy_u32Number%10;
		Local_u8Digit+=48;
		USART_TransmitData(Local_u8Digit);
		Copy_u32Number/=10;
	}
}

u32 USART_u32ReceiveNumber()
{
    u32 Copy_u32Number = 0; // Initialize the number to store the received value

    // Receive characters until a newline character '\n' is encountered
    char receivedChar;
    while (1)
    {
        receivedChar = USART_u8ReceiveData(); // Receive a character

        // Check for numerical digits (0-9)
        if (receivedChar >= '0' && receivedChar <= '9')
        {
            Copy_u32Number = (Copy_u32Number * 10) + (receivedChar - '0');
        }
        else
        {
            break; // Exit the loop if newline character is received
        }
    }

    return Copy_u32Number;
}

void USART_voidTransmitString(const char* Copy_pcString)
{
  u8 Local_u8Counter=0;
  while(Copy_pcString[Local_u8Counter]!='\0')
  {
	  USART_TransmitData(Copy_pcString[Local_u8Counter]);
	  Local_u8Counter++;
  }
}

void USART_voidReceiveString(char* Copy_pcString)
{
    u8 Local_u8Counter = 0;
    Copy_pcString[Local_u8Counter] = USART_u8ReceiveData();
    while (Copy_pcString[Local_u8Counter] != '\r' && Copy_pcString[Local_u8Counter] != '\n')
    {
        Local_u8Counter++;
        Copy_pcString[Local_u8Counter] = USART_u8ReceiveData();
    }
    Copy_pcString[Local_u8Counter] = '\0'; // Null-terminate the received string
}


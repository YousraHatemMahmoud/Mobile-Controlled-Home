#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#define BIT_1  0
#define BIT_2  1
#define BIT_3  2
#define BIT_4  3
#define BIT_5  4
#define BIT_6  5
#define BIT_7  6
#define BIT_8  7
#define BIT_9  8

#define DISABLED             0
#define RESERVED             1
#define ENABLED_EVEN_PARITY  2
#define ENABLED_ODD_PARITY   3

#define ASYNCHRONOUS  0
#define SYNCHRONOUS   1

void USART_voidInit(void);

void USART_TransmitData(u8 Copy_u8Data);

u8 USART_u8ReceiveData();

void USART_TransmitNumber(u32 Copy_u32Number);

u32 USART_u32ReceiveNumber();

void USART_voidTransmitString(const char* Copy_pcString);

void USART_voidReceiveString(char* Copy_pcString);

#endif

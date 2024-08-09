#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
 
#define PORTA      0
#define PORTB      1
#define PORTC      2
#define PORTD      3

#define PIN0       0
#define PIN1       1
#define PIN2       2
#define PIN3       3
#define PIN4       4
#define PIN5       5
#define PIN6       6
#define PIN7       7

#define INPUT      0
#define OUTPUT     1

#define LOW        0
#define HIGH       1

#define NO_PULLUP  0
#define PULLUP     1

#define ALL_INPUT  0x00
#define ALL_OUTPUT 0xFF

#define ALL_LOW    0x00
#define ALL_HIGH   0xFF


void DIO_voidSetPinDirection (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinState);
void DIO_voidSetPinValue     (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
u8   DIO_u8GetPinValue       (u8 Copy_u8PortName, u8 Copy_u8PinNumber);

void DIO_voidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortState);
void DIO_voidSetPortValue    (u8 Copy_u8PortName, u8 Copy_u8PortValue);
u8   DIO_u8GetPortValue      (u8 Copy_u8PortName);

void DIO_voidSetSpecificPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortState);
void DIO_voidSetSpecificPortValue (u8 Copy_u8PortName, u8 Copy_u8PortValue);

       
#endif

#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

/********************** TIMER 0 REGISTERS **********************/
#define TCCR0        *((volatile u8*)0x53)
#define TCCR0_CS00   0
#define TCCR0_CS01   1
#define TCCR0_CS02   2
#define TCCR0_WGM01  3
#define TCCR0_COM00  4
#define TCCR0_COM01  5
#define TCCR0_WGM00  6
#define TCCR0_FOC0   7

#define TCNT0        *((volatile u8*)0x52)

#define OCR0         *((volatile u8*)0x5C)

#define TIMSK        *((volatile u8*)0x59)
#define TIMSK_TOIE0  0
#define TIMSK_OCIE0  1

#define TIFR        *((volatile u8*)0x58)
#define TIFR_TOV0    0
#define TIFR_OCF0    1

/********************** TIMER 1 REGISTERS **********************/
#define     TCCR1A          *((volatile u8 *)(0x4F))	// Timer/Counter 1A Control Register
#define     TCCR1A_WGM10    0   // Wave Generation Mode bit 0
#define     TCCR1A_WGM11    1   // Wave Generation Mode bit 1
#define     TCCR1A_FOC1B    2   // Force Output Compare Channel B
#define     TCCR1A_FOC1A    3   // Force Output Compare Channel A
#define     TCCR1A_COM1B0   4   // Channel B bit 0
#define     TCCR1A_COM1B1   5   // Channel B bit 1
#define     TCCR1A_COM1A0   6   // Channel A bit 0
#define     TCCR1A_COM1A1   7   // Channel A bit 1

#define     TCCR1B          *((volatile u8 *)(0x4E))	// Timer/Counter 1B Control Register
#define     TCCR1B_CS10     0                           // Clock Selection bit 0
#define     TCCR1B_CS11     1                           // Clock Selection bit 1
#define     TCCR1B_CS12     2                           // Clock Selection bit 2
#define     TCCR1B_WGM12    3                           // Wave Generation Mode bit 2
#define     TCCR1B_WGM13    4                           // Wave Generation Mode bit 3
#define     TCCR1B_ICES1    6                           // Input Capture Edge Selection
#define     TCCR1B_ICNC1    7                           // Input Capture Noise Cancelation

#define     TCNT1L          *((volatile u8 *)(0x4C))	// Timer/Counter 1 Counter Register Low Byte
#define     TCNT1H          *((volatile u8 *)(0x4D))	// Timer/Counter 1 Counter Register High Byte
#define     TCNT1           *((volatile u16 *)(0x4C))	// Timer/Counter 1 Counter Register.

#define     OCR1AH          *((volatile u8 *)(0x4B))	// Timer/Counter 1 Channel A Compare Match Value High Byte
#define     OCR1AL          *((volatile u8 *)(0x4A))	// Timer/Counter 1 Channel A Compare Match Value Low Byte
#define     OCR1A           *((volatile u16 *)(0x4A))	// Timer/Counter 1 Channel A Compare Match Value

#define     OCR1BH          *((volatile u8 *)(0x49))	// Timer/Counter 1 Channel B Compare Match Value High Byte
#define     OCR1BL          *((volatile u8 *)(0x48))	// Timer/Counter 1 Channel B Compare Match Value Low Byte
#define     OCR1B           *((volatile u16 *)(0x48))	// Timer/Counter 1 Channel B Compare Match Value

#define     ICR1L           *((volatile u8 *)(0x46))	// Input Capture Register Timer 1 Low Byte
#define     ICR1H           *((volatile u8 *)(0x47))	// Input Capture Register Timer 1 High Byte
#define     ICR1            *((volatile u16 *)(0x46))	// Input Capture Register Timer 1

#define 	TIFR_TOV1	    2							// Timer 1 Overflow Flag
#define 	TIFR_OCF1B	    3							// Timer 1 Output Compare Flag Channel B
#define 	TIFR_OCF1A	    4							// Timer 1 Output Compare Flag Channel A
#define     TIFR_ICF1       5                           // Timer 1 Input Capture Flag


#define 	TIMSK_TOIE1	    2					        // Timer 1 Overflow Interrupt Enable
#define 	TIMSK_OCIE1B	3					        // Timer 1 Channel B Output Compare Interrupt Enable
#define 	TIMSK_OCIE1A	4					        // Timer 1 Channel A Output Compare Interrupt Enable
#define     TIMSK_TICIE1    5                           // Timer 1 Input Capture Interrupt Enable


/*************************TIMER 2 REGISTERS**************************/


#define TCCR2       *((volatile u8*)0x45)
#define TCCR2_CS20   0
#define TCCR2_CS21   1
#define TCCR2_CS22   2
#define TCCR2_WGM21  3
#define TCCR2_COM20  4
#define TCCR2_COM21  5
#define TCCR2_WGM20  6
#define TCCR2_FOC2   7

#define TCNT2        *((volatile u8*)0x44)

#define OCR2         *((volatile u8*)0x43)

#define TIMSK_TOIE2  6
#define TIMSK_OCIE2  7

#define TIFR_TOV2    6
#define TIFR_OCF2    7

#define NULL    (void *)0

#define PRESCALER_MASK		0b11111000

#endif

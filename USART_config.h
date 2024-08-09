#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define CPU_CLK   8000000
/*
 * This bit selects between ASYNCHRONOUS and SYNCHRONOUS mode of operation.
 */
#define USART_MODE_SELECT  ASYNCHRONOUS


/*  PARITY_MODE
 *  DISABLED
    RESERVED
    ENABLED_EVEN_PARITY
    ENABLED_ODD_PARITY
 */
#define USART_PARITY_MODE  DISABLED


/*Stop Bit Select
 * 1_BIT
 * 2_BIT
 */
#define USART_STOP_BIT_SELECT  BIT_1

/*Data size
 *
 *  5_bit
 *  6_bit
 *  7_bit
 *  8_bit
 *  9_bit
 *
 *
 */
#define USART_DATA_SIZE BIT_8

/*
 *
 * ENABLED
 * DISABLED
 */

#define RX_Complete_Interrupt    DISABLED
/*
 *
 * ENABLED
 * DISABLED
 */

#define TX_Complete_Interrupt    DISABLED

/*
 *
 * ENABLED
 * DISABLED
 */

#define USART_Data_Register_Empty_Interrupt DISABLED
/*
 *
 * ENABLED
 * DISABLED
 */

#define USART_TRANSMIT_ENABLE  ENABLE
/*
 *
 * ENABLED
 * DISABLED
 */

#define USART_RECIEVE_ENABLE ENABLE

#define USART_BAUD_RATE    9600


#endif

#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H

/*
 *
 *1- NORMAL
 *2- CTC
 *3- FAST_PWM
 *
 */
#define TIMER0_MODE                                      CTC

/*
 *
 *
 *
 */
#define TIMER0_CTC_MODE                                  NORMAL

/*0- NO_TIMER
 * 1-DIVIDE_BY_1
 * 2-DIVIDE_BY_8
 * 3-DIVIDE_BY_32
 * 4-DIVIDE_BY_64
 * 5-DIVIDE_BY_128
 * 6-DIVIDE_BY_256
 * 7-DIVIDE_BY_1024
 *
 *
 *
 *
 */

#define TIMER0_PRESCALLER                          DIVIDE_BY_1

/*
 * 1-  CLEAR_ON_COMPARE_SET_AT_TOP
 *
 *
 *
 */
#define FAST_PWM_MODE              CLEAR_ON_COMPARE_SET_AT_TOP

#define TIMER0_COMPARE_MATCH_INTERRUPT_ENABLE      ENABLE

//------------------------Timer 2-------------------------------------
#define TIMER2_MODE                                      FAST_PWM

/*
 *
 *
 *
 */
#define TIMER2_CTC_MODE                                  NORMAL

/*0- NO_TIMER
 * 1-DIVIDE_BY_1
 * 2-DIVIDE_BY_8
 * 3-DIVIDE_BY_32
 * 4-DIVIDE_BY_64
 * 5-DIVIDE_BY_128
 * 6-DIVIDE_BY_256
 * 7-DIVIDE_BY_1024
 *
 *
 *
 *
 */

#define TIMER2_PRESCALLER                          DIVIDE_BY_8

/*
 * 1-  CLEAR_ON_COMPARE_SET_AT_TOP
 *
 *
 *
 */
#define TIMER2_FAST_PWM_MODE                   CLEAR_ON_COMPARE_SET_AT_TOP

#define TIMER2_COMPARE_MATCH_INTERRUPT_ENABLE      DISABLE

#endif

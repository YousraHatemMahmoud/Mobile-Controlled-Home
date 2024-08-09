#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

#define FALLING_EDGE       0
#define RISING_EDGE        1

#define ENABLE             1
#define DISABLE            0

#define CTC                0
#define FAST_PWM           1



#define CTC_NORMAL          0



#define DIVIDE_BY_1        1
#define DIVIDE_BY_8        2
#define DIVIDE_BY_32       3
#define DIVIDE_BY_64       4
#define DIVIDE_BY_128      5
#define DIVIDE_BY_256      6
#define DIVIDE_BY_1024     7

#define FAST_PWM_NORMAL                                 0
#define CLEAR_ON_COMPARE_SET_AT_TOP                     1

//-------------------------------TIMER 0----------------------------

void TIMERS_voidInit(void);

void TIMERS_voidTimer0Init(void);

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue);

void TIMERS_voidTimer0SetPreLoadValue(u8 Copy_u8PreLoadValue);

void TIMERS_voidTimer0CTCSetCallBackFunction(void(*Copy_pvCTCFunction)(void));

void TIMERS_voidTimer0SetIntervalPeriodic(u8 Copy_u8Ticks, void(*CallbackFunction)(void));



//-----------------TIMER 1 --------------------

void TIMERS_voidTimer1Init(void);

void TIMERS_voidTimer1ChannelASetCompareMatchValue(u16 Copy_u16CompareMatchValue);

void TIMERS_voidSetBusyWaitTimer0_ms(u32 Copy_u32Time_ms);

void TIMERS_voidTimer1SetOverFlowValue(u16 Copy_16OverFlowValue);

void TIMERS_voidTimer1SetPreloadValue(u16 Copy_u16Value);

u16  TIMERS_voidTimer1GetValue(void);

void TIMERS_voidTimer1ClearOverFlowFlag(void);

void TIMERS_voidTimer1SetNormalMode(void);

void TIMERS_voidTimer1SetMode14(void);

void TIMERS_voidTimer1OVFSetCallBackFunction(void (*Copy_pvOvfFunction)(void));

void ICU_voidClearICPFlag(void);

void ICU_voidSetSenseControl(u8 Copy_u8SenseControl);

void ICU_voidSetCallBackFunction(void (*Copy_pvNotificationFunction)(void));

u16 ICU_u16ReadInputCapture(void);

void ICU_voidInterruptControl(u8 Copy_u8InterruptState);

void TIMERS_voidTimer1DisableNormalMode(void);

void TIMERS_voidTimer1DisableMode14(void);
// ----------------------------TIMER 2 --------------------
void TIMERS_voidTimer2Init(void);

void TIMERS_voidSetBusyWaitTimer2_ms(u32 Copy_u32Time_ms);

void TIMERS_voidTimer2SetCompareMatchValue(u8 Copy_u8CompareMatchValue);

void TIMERS_voidTimer2SetPreLoadValue(u8 Copy_u8PreLoadValue);


#endif

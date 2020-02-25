#ifndef HSWITCH_INTERFACE_H
#define HSWITCH_INTERFACE_H

#include"STD_TYPES.h"
#include"GPIO_interface.h"

#define   MAX_SWITCHES_NO    2

#define   SWITCH_CH1         0
#define   SWITCH1_PIN     GPIO_PIN0
#define   SWITCH1_PORT    GPIO_PORTA

#define   SWITCH_CH2         1
#define   SWITCH2_PIN     GPIO_PIN1
#define   SWITCH2_PORT    GPIO_PORTA


/*
inputs:
          switch_ch_NO  >>      SWITCH_CH1 or SWITCH_CH2
output:
          ERROR_S       >>      ERROR_OK  or  ERROR_NOK
*/
extern ERROR_S  DoorSwitch_Init(u8 switch_ch_NO);

/*
inputs:
         1-  switch_ch_NO  >>   SWITCH_CH1 or SWITCH_CH2
         2-  ptr for the return value
output:
          ERROR_S       >>      ERROR_OK  or  ERROR_NOK
*/
extern ERROR_S  DoorSwitch_Read(u8 switch_ch_NO , u8* value);

#endif

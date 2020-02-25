#ifndef HLAMP_INTERFACE_H
#define HLAMP_INTERFACE_H

#include"STD_TYPES.h"
#include"GPIO_interface.h"


#define   LAMP1         0
#define   LAMP1_PIN     GPIO_PIN2
#define   LAMP1_PORT    GPIO_PORTA

/*
inputs:
          LAMP_ch_No  >>        LAMP1
output:
          ERROR_S       >>      ERROR_OK  or  ERROR_NOK
*/
extern ERROR_S Lamp_Init(u8 LAMP_ch_No);

/*
inputs:
          LAMP_ch_No  >>        LAMP1
output:
          ERROR_S       >>      ERROR_OK  or  ERROR_NOK
*/
extern ERROR_S Lamp_ON(u8  LAMP_ch_No);

/*
inputs:
          LAMP_ch_No  >>        LAMP1
output:
          ERROR_S       >>      ERROR_OK  or  ERROR_NOK
*/
extern ERROR_S Lamp_OFF(u8 LAMP_ch_No);


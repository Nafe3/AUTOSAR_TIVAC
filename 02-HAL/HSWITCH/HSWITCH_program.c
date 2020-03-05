/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#include "STD_TYPES.h"
#include "Rcc_TivaC.h"
#include "GPIO_interface.h"
#include "HSWITCH_interface.h"


typedef struct
{
  u32 port;
  u32 pin;

}switch_t;


switch_t  SWITCHES[MAX_SWITCHES_NO] = {

{ SWITCH1_PORT , SWITCH1_PIN },
{ SWITCH2_PORT , SWITCH2_PIN },

};

/*
 * Description : This API Shall initiate the DOOR switch on the selected channel
 * inputs:
 *         switch_ch_NO  >>      SWITCH_CH1 or SWITCH_CH2
 * output:
 *         ERROR_S       >>      ERROR_OK  or  ERROR_NOK
 */
ERROR_S  DoorSwitch_Init(u8 switch_ch_NO)
{
  u8 status; 
  if (switch_ch_NO < MAX_SWITCHES_NO )
  {
      RCC_EnableGpioClk(SWITCHES[switch_ch_NO].port);
      GPIO_Init(SWITCHES[switch_ch_NO].port , SWITCHES[switch_ch_NO].pin , GPIO_INPUT);
      GPIO_WritePin(SWITCHES[switch_ch_NO].port,SWITCHES[switch_ch_NO].pin ,GPIO_INPUT_PULLUP);
      status = ERROR_OK;
  }
  else
  {
      status = ERROR_NOK;
  }
  return status;
}

/*
 * Description : This API Shall get the DOOR switch value on the selected channel
 * inputs:
 *        1-  switch_ch_NO  >>   SWITCH_CH1 or SWITCH_CH2
 *        2-  ptr for the return value
 * output:
 *         ERROR_S       >>      ERROR_OK  or  ERROR_NOK
*/
ERROR_S  DoorSwitch_Read(u8 switch_ch_NO , u8* value)
{
  u8 status; 
  if (switch_ch_NO < MAX_SWITCHES_NO   &&  value != NULL )
  {
      GPIO_ReadPin( SWITCHES[switch_ch_NO].port  , SWITCHES[switch_ch_NO].pin, value);
      status = ERROR_OK;
  }
  else
  {
      status = ERROR_NOK;
  }
  return status;
}

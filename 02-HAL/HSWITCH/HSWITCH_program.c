#include"STD_TYPES.h"
#include"MACROS.h"
#include"GPIO_interface.h"
#include"HSWITCH_interface.h"

typedef struct
{
  u32 port;
  u32 pin;

}switch_t;

switch_t  SWITCHES[MAX_SWITCHES_NO] = {

{ SWITCH1_PORT , SWITCH1_PIN },
{ SWITCH2_PORT , SWITCH2_PIN },

};

extern ERROR_S  DoorSwitch_Init(u8 switch_ch_NO)
{
  u8 status; 
  if (switch_ch_NO < MAX_SWITCHES_NO  )
  {
      GPIO_Init(SWITCHES[switch_ch_NO].port , SWITCHES[switch_ch_NO].pin , GPIO_INPUT);
      status = ERROR_OK;
  }
  else
  {
      status = ERROR_NOK;
  }
  return status;
}


extern ERROR_S  DoorSwitch_Read(u8 switch_ch_NO , u8* value)
{
  u8 status; 
  if (switch_ch_NO < MAX_SWITCHES_NO   &&  value != NULL )
  {
      GPIO_ReadPin( SWITCHES[switch_ch_NO].port  , SWITCHES[switch_ch_NO].pin,  &value);
      status = ERROR_OK;
  }
  else
  {
      status = ERROR_NOK;
  }
  return status;
}

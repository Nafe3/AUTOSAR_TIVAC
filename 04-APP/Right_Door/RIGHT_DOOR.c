#include "RIGHT_DOOR.h"
//include header name
#define RIGHT_DOOR  2
ERROR_S RDOOR_Init(void)
{
  ERROR_S ERROR_Status = Error_ok;
  SWITCH_Init(RIGHT_DOOR);
  return ERROR_Status;

}
ERROR_S RDOOR_ReadStatus(u8* value)
{
  u8 GetDoorStatus;
  ERROR_S ERROR_Status = Error_ok;
  
  SWITCH_Read(RIGHT_DOOR, &GetDoorStatus);
  *value= GetDoorStatus;
  return ERROR_Status;
}

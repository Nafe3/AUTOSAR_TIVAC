#include "Left_Door.h"
//include el header
#define LEFT_DOOR    0
ERROR_S LDOOR_Init(void)
{
  ERROR_S ERROR_Status = Error_ok;
  SWITCH_Init(LEFT_DOOR);
  return ERROR_Status;

}
ERROR_S LDOOR_ReadStatus(u8* value)
{
  u8 GetDoorStatus;
  ERROR_S ERROR_Status = Error_ok;
  
  SWITCH_Read(LEFT_DOOR, &GetDoorStatus);
  *value= GetDoorStatus;
  return ERROR_Status;

  
}

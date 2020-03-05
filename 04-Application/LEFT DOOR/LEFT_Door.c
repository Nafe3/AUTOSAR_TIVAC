/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#include "STD_TYPES.h"
#include "LEFT_Door.h"
#include "HSWITCH_interface.h"


#define LEFT_DOOR    SWITCH_CH2

/*
 *Description : This API shall initiate the Left Door switch Channel
 *parameters  :
 *              -> None
 * Return     :
 *          -> ERROR_Status (ERROR_OK ,ERROR_NOK)
 */
ERROR_S LDOOR_Init(void)
{
  ERROR_S ERROR_Status = ERROR_OK;

  ERROR_Status = DoorSwitch_Init(LEFT_DOOR);

  return ERROR_Status;

}

/*
 *Description : This API shall get the Left Door status open or closed
 *parameters  :
 *              -> *value : pointer to the return value of the door status
 * Return     :
 *          -> ERROR_Status (ERROR_OK ,ERROR_NOK)
 */
ERROR_S LDOOR_ReadStatus(u8* value)
{

  ERROR_S ERROR_Status = ERROR_OK;
  
  ERROR_Status = DoorSwitch_Read(LEFT_DOOR, value);

  return ERROR_Status;

  
}

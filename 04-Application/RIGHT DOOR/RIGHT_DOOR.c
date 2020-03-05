/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#include "STD_TYPES.h"
#include "HSWITCH_interface.h"
#include "RIGHT_DOOR.h"


#define RIGHT_DOOR  SWITCH_CH1

/*
 *Description : This API shall initiate the Right Door switch Channel
 *parameters  :
 *              -> None
 * Return     :
 *          -> ERROR_Status (ERROR_OK ,ERROR_NOK)
 */
ERROR_S RDOOR_Init(void)
{
    ERROR_S ERROR_Status = ERROR_OK;

    ERROR_Status = DoorSwitch_Init(RIGHT_DOOR);

    return ERROR_Status;

}

/*
 *Description : This API shall get the Right Door status open or closed
 *parameters  :
 *              -> *value : pointer to the return value of the door status
 * Return     :
 *          -> ERROR_Status (ERROR_OK ,ERROR_NOK)
 */
ERROR_S RDOOR_ReadStatus(u8* value)
{
    ERROR_S ERROR_Status = ERROR_OK;

    ERROR_Status = DoorSwitch_Read(RIGHT_DOOR, value);

    return ERROR_Status;
}

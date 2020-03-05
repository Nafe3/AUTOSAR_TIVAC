/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#ifndef LDOOR_H_
#define LDOOR_H_

/*
 *Description : This API shall initiate the Left Door switch Channel
 *parameters  :
 *              -> None
 * Return     :
 *          -> ERROR_Status (ERROR_OK ,ERROR_NOK)
 */
ERROR_S LDOOR_Init(void);

/*
 *Description : This API shall get the Left Door status open or closed
 *parameters  :
 *              -> *value : pointer to the return value of the door status
 * Return     :
 *          -> ERROR_Status (ERROR_OK ,ERROR_NOK)
 */
ERROR_S LDOOR_ReadStatus(u8* value);

#endif

/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#ifndef RDOOR_H_
#define RDOOR_H_

/*
 *Description : This API shall initiate the Right Door switch Channel
 *parameters  :
 *              -> None
 * Return     :
 *          -> ERROR_Status (ERROR_OK ,ERROR_NOK)
 */
ERROR_S RDOOR_Init(void);

/*
 *Description : This API shall get the Right Door status open or closed
 *parameters  :
 *              -> *value : pointer to the return value of the door status
 * Return     :
 *          -> ERROR_Status (ERROR_OK ,ERROR_NOK)
 */
ERROR_S RDOOR_ReadStatus(u8* value);

#endif

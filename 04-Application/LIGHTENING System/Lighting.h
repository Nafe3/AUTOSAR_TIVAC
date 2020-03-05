/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#ifndef LIGHT_HANDLER
#define LIGHT_HANDLER

/*
 * Description : This API shall initiate the Lightening system
 * Parameters :
 *          -> void
 * Return     :
 *          -> ERROR_Status (ERROR_OK ,ERROR_NOK)
 * This API shall :
 * 1. Initiate the Lamp system with the Channel decieded
 * 2. Initiate Left DOOR System
 * 3. Initiate Right DOOOR System
 */
ERROR_S   LIGHT_Init(void);

/*
 * Description : This API shall run The Cabin Car Lamp System.
 * Parameters  :
 *            -> void
 * Return      :
 *            -> ERROR_Status
 * This API shall :
 * 1. Read The Left DOOR State open (LOW) or closed (HIGH).
 * 2. Make the Decision to turn on or off the light
 *  depending on doors state.
 */
ERROR_S   LIGHT_System(void);


/*
 * Description : This API shall run The Cabin Car Lamp System.
 * Parameters  :
 *            -> void
 * Return      :
 *            -> ERROR_Status
 * This API shall :
 * 1. Send signal ON to the lamp channel
 */
ERROR_S   LIGHT_ON(void);

/*
 * Description : This API shall run The Cabin Car Lamp System.
 * Parameters  :
 *            -> void
 * Return      :
 *            -> ERROR_Status
 * This API shall :
 * 1. Send signal OFF to the lamp channel
 */
ERROR_S   LIGHT_OFF(void);

#endif

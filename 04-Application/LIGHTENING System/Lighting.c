/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#include "STD_TYPES.h"
#include "Rcc_TivaC.h"
#include "RIGHT_Door.h"
#include "LEFT_Door.h"
#include "HLAMP_interface.h"
#include "Lighting.h"

/*  defining The channel number  */
#define NUM        LAMP1

/*  defining the HIGH and the LOW signals  */
#define HIGH       1
#define LOW        0


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
 * */
ERROR_S   LIGHT_Init(void)
{
    ERROR_S ERROR_Status = ERROR_OK;

    ERROR_Status |= Lamp_Init(NUM);
    ERROR_Status |= LDOOR_Init();
    ERROR_Status |= RDOOR_Init();

    return ERROR_Status;
}

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
ERROR_S LIGHT_System(void)
{

  u8 LDoorState = LOW ,RDoorState = LOW;
  ERROR_S ERROR_Status = ERROR_OK;

  ERROR_Status |= LDOOR_ReadStatus(&LDoorState);
  ERROR_Status |= RDOOR_ReadStatus(&RDoorState);

  if(LDoorState== LOW  ||  RDoorState==LOW  )
  {
      ERROR_Status |= LIGHT_ON();
  }
  else
  {
      ERROR_Status |= LIGHT_OFF();
  }

  return ERROR_Status;
}


/*
 * Description : This API shall run The Cabin Car Lamp System.
 * Parameters  :
 *            -> void
 * Return      :
 *            -> ERROR_Status
 * This API shall :
 * 1. Send signal ON to the lamp channel
 */
ERROR_S   LIGHT_ON(void)
{
  ERROR_S ERROR_Status = ERROR_OK;

  ERROR_Status = Lamp_ON(NUM);

  return ERROR_Status;
}

/*
 * Description : This API shall run The Cabin Car Lamp System.
 * Parameters  :
 *            -> void
 * Return      :
 *            -> ERROR_Status
 * This API shall :
 * 1. Send signal OFF to the lamp channel
 */
ERROR_S   LIGHT_OFF(void)
{
  ERROR_S ERROR_Status = ERROR_OK;

  ERROR_Status = Lamp_OFF(NUM);

  return ERROR_Status;
}

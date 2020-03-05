/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#include"STD_TYPES.h"
#include"Rcc_TivaC.h"
#include"GPIO_interface.h"
#include"HLAMP_interface.h"


/*
 * Description : This API shall initiate the lamp on the selected channel
 * inputs:
 *         LAMP_ch_No  >>        LAMP1
 * output:
 *         ERROR_S       >>      ERROR_OK  or  ERROR_NOK
 */
extern  ERROR_S Lamp_Init(u8 LAMP_ch_No)
{
	u8 status;
	if(LAMP_ch_No == LAMP1)
	{
	    RCC_EnableGpioClk(LAMP1_PORT);
	    GPIO_Init( LAMP1_PORT , LAMP1_PIN , GPIO_OUTPUT);
	    status  =  ERROR_OK;
	}
	else
	{
		status  =  ERROR_NOK;
	}
    return status;
}

/*
 * Description : This API shall set the lamp on the selected channel value to ON
 * inputs:
 *         LAMP_ch_No  >>        LAMP1
 * output:
 *         ERROR_S       >>      ERROR_OK  or  ERROR_NOK
 */
extern  ERROR_S Lamp_ON(u8 LAMP_ch_No)
{
	u8 status;
	if(LAMP_ch_No == LAMP1)
	{
		  GPIO_WritePin( LAMP1_PORT , LAMP1_PIN , GPIO_OUTPUT_HIGH);
	    status  =  ERROR_OK;
	}
	else
	{
		status  =  ERROR_NOK;
	}
    return status;
}

/*
 * Description : This API shall set the lamp on the selected channel value to OFF
 * inputs:
 *         LAMP_ch_No  >>        LAMP1
 * output:
 *         ERROR_S       >>      ERROR_OK  or  ERROR_NOK
 */
extern  ERROR_S Lamp_OFF(u8 LAMP_ch_No)
{
	u8 status;
	if(LAMP_ch_No == LAMP1)
	{
		  GPIO_WritePin( LAMP1_PORT , LAMP1_PIN , GPIO_OUTPUT_LOW);
	      status  =  ERROR_OK;
	}
	else
	{
		  status  =  ERROR_NOK;
	}
    return status;
}

#include"STD_TYPES.h"
#include"MACROS.h"
#include"HLAMP_interface.h"
#include"GPIO_interface.h"


extern  ERROR_S Lamp_Init(u8 LAMP_ch_No)
{
	u8 status;
	if(LAMP_ch_No == LAMP1)
	{
	    GPIO_Init( LAMP1_PORT , LAMP1_PIN , GPIO_OUTPUT);
	    status  =  ERROR_OK;
	}
	else
	{
		status  =  ERROR_NOK;
	}
    return status;
}

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

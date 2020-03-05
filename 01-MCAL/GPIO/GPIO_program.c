/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#include "STD_TYPES.h"
#include "GPIO_interface.h"




/*                               Base Addresses                                         */
#define PORTA_BASE_ADDRESS				0x40004000
#define PORTB_BASE_ADDRESS				0x40005000
#define PORTC_BASE_ADDRESS				0x40006000
#define PORTD_BASE_ADDRESS			    0x40007000
#define PORTE_BASE_ADDRESS				0x40024000
#define PORTF_BASE_ADDRESS				0x40025000


/*                          Registers Offset Addresses                                  */

                                    /*  PORTA   */
/*  Register that contains data(RW) */
#define GPIO_A_DATA						    			*((u32*)(PORTA_BASE_ADDRESS+0x3FC))
/*  Register that sets data(RW)     */
#define GPIO_A_DIR										*((u32*)(PORTA_BASE_ADDRESS+0x400))
/*  Register Interrupt Sense(RW)    */
#define GPIO_A_IS										*((u32*)(PORTA_BASE_ADDRESS+0x404))
/*  Interrupt Both Edges(RW)        */
#define GPIO_A_IBE										*((u32*)(PORTA_BASE_ADDRESS+0x408))
/*  Interrupt Event(RW)             */
#define GPIO_A_IEV										*((u32*)(PORTA_BASE_ADDRESS+0x40C))
/*  Interrupt Mask(RW)              */
#define GPIO_A_IM										*((u32*)(PORTA_BASE_ADDRESS+0x410))
/*  RAW Interrupt Status(RO)        */
#define GPIO_A_RIS										*((u32*)(PORTA_BASE_ADDRESS+0x414))
/*  Masked Interrupt Status         */
#define GPIO_A_MIS										*((u32*)(PORTA_BASE_ADDRESS+0x418))
/*  Interrupt Clear                 */
#define GPIO_A_ICR										*((u32*)(PORTA_BASE_ADDRESS+0x41C))
/*  Alternate Function Select       */
#define GPIO_A_AFSEL									*((u32*)(PORTA_BASE_ADDRESS+0x420))
/*  2mA Drive Select                */
#define GPIO_A_DR2R							    		*((u32*)(PORTA_BASE_ADDRESS+0x500))
/*  4mA Drive Select                */
#define GPIO_A_DR4R								    	*((u32*)(PORTA_BASE_ADDRESS+0x504))
/*  8mA Drive Select                */
#define GPIO_A_DR8R									    *((u32*)(PORTA_BASE_ADDRESS+0x508))
/*  Open Drain Select               */
#define GPIO_A_ODR									    *((u32*)(PORTA_BASE_ADDRESS+0x50C))
/*  Pull Up Select                  */
#define GPIO_A_PUR										*((u32*)(PORTA_BASE_ADDRESS+0x510))
/*  Pull down select                */
#define GPIO_A_PDR										*((u32*)(PORTA_BASE_ADDRESS+0x514))
/*  Slew Rate                       */
#define GPIO_A_SLR										*((u32*)(PORTA_BASE_ADDRESS+0x518))
/*  Digital Enable                  */
#define GPIO_A_DEN										*((u32*)(PORTA_BASE_ADDRESS+0x51C))
/*  GPIO Lock                       */
#define GPIO_A_LOCK									    *((u32*)(PORTA_BASE_ADDRESS+0x520))
/*  GPIO Commit                     */
#define GPIO_A_CR										*((u32*)(PORTA_BASE_ADDRESS+0x524))
/*  GPIO Analog Mode Select         */
#define GPIO_A_AMSEL									*((u32*)(PORTA_BASE_ADDRESS+0x528))
/*  GPIO Port Control               */
#define GPIO_A_PCTL									    *((u32*)(PORTA_BASE_ADDRESS+0x52C))
/*  ADC Control                     */
#define GPIO_A_ADCCTL								    *((u32*)(PORTA_BASE_ADDRESS+0x530))
/*  GPIO DMA Control                */
#define GPIO_A_DMACTL								    *((u32*)(PORTA_BASE_ADDRESS+0x534))
																																 
																																 
                                     /*PORTB*/
/*  Register that contains data(RW) */
#define GPIO_B_DATA									    *((u32*)(PORTB_BASE_ADDRESS+0x3FC))
/*  Register that sets data(RW)     */
#define GPIO_B_DIR										*((u32*)(PORTB_BASE_ADDRESS+0x400))
/*  Register Interrupt Sense(RW)    */
#define GPIO_B_IS										*((u32*)(PORTB_BASE_ADDRESS+0x404))
/*  Interrupt Both Edges(RW)        */
#define GPIO_B_IBE										*((u32*)(PORTB_BASE_ADDRESS+0x408))
/*  Interrupt Event(RW)             */
#define GPIO_B_IEV										*((u32*)(PORTB_BASE_ADDRESS+0x40C))
/*  Interrupt Mask(RW)              */
#define GPIO_B_IM										*((u32*)(PORTB_BASE_ADDRESS+0x410))
/*  RAW Interrupt Status(RO)        */
#define GPIO_B_RIS										*((u32*)(PORTB_BASE_ADDRESS+0x414))
/*  Masked Interrupt Status         */
#define GPIO_B_MIS										*((u32*)(PORTB_BASE_ADDRESS+0x418))
/*  Interrupt Clear                 */
#define GPIO_B_ICR										*((u32*)(PORTB_BASE_ADDRESS+0x41C))
/*  Alternate Function Select       */
#define GPIO_B_AFSEL									*((u32*)(PORTB_BASE_ADDRESS+0x420))
/*  2mA Drive Select                */
#define GPIO_B_DR2R									    *((u32*)(PORTB_BASE_ADDRESS+0x500))
/*  4mA Drive Select                */
#define GPIO_B_DR4R									    *((u32*)(PORTB_BASE_ADDRESS+0x504))
/*  8mA Drive Select                */
#define GPIO_B_DR8R									    *((u32*)(PORTB_BASE_ADDRESS+0x508))
/*  Open Drain Select               */
#define GPIO_B_ODR									    *((u32*)(PORTB_BASE_ADDRESS+0x50C))
/*  Pull Up Select                  */
#define GPIO_B_PUR										*((u32*)(PORTB_BASE_ADDRESS+0x510))
/*  Pull down select                */
#define GPIO_B_PDR										*((u32*)(PORTB_BASE_ADDRESS+0x514))
/*  Slew Rate                       */
#define GPIO_B_SLR										*((u32*)(PORTB_BASE_ADDRESS+0x518))
/*  Digital Enable                  */
#define GPIO_B_DEN										*((u32*)(PORTB_BASE_ADDRESS+0x51C))
/*  GPIO Lock                       */
#define GPIO_B_LOCK									    *((u32*)(PORTB_BASE_ADDRESS+0x520))
/*  GPIO Commit                     */
#define GPIO_B_CR										*((u32*)(PORTB_BASE_ADDRESS+0x524))
/*  GPIO Analog Mode Select         */
#define GPIO_B_AMSEL									*((u32*)(PORTB_BASE_ADDRESS+0x528))
/*  GPIO Port Control               */
#define GPIO_B_PCTL									    *((u32*)(PORTB_BASE_ADDRESS+0x52C))
/*  ADC Control                     */
#define GPIO_B_ADCCTL								    *((u32*)(PORTB_BASE_ADDRESS+0x530))
/*  GPIO DMA Control                */
#define GPIO_B_DMACTL								    *((u32*)(PORTB_BASE_ADDRESS+0x534))
																																 
                                      /*PORTC*/
/*  Register that contains data(RW) */
#define GPIO_C_DATA									    *((u32*)(PORTC_BASE_ADDRESS+0x3FC))
/*  Register that sets data(RW)     */
#define GPIO_C_DIR										*((u32*)(PORTC_BASE_ADDRESS+0x400))
/*  Register Interrupt Sense(RW)    */
#define GPIO_C_IS										*((u32*)(PORTC_BASE_ADDRESS+0x404))
/*  Interrupt Both Edges(RW)        */
#define GPIO_C_IBE										*((u32*)(PORTC_BASE_ADDRESS+0x408))
/*  Interrupt Event(RW)             */
#define GPIO_C_IEV										*((u32*)(PORTC_BASE_ADDRESS+0x40C))
/*  Interrupt Mask(RW)              */
#define GPIO_C_IM										*((u32*)(PORTC_BASE_ADDRESS+0x410))
/*  RAW Interrupt Status(RO)        */
#define GPIO_C_RIS										*((u32*)(PORTC_BASE_ADDRESS+0x414))
/*  Masked Interrupt Status         */
#define GPIO_C_MIS										*((u32*)(PORTC_BASE_ADDRESS+0x418))
/*  Interrupt Clear                 */
#define GPIO_C_ICR										*((u32*)(PORTC_BASE_ADDRESS+0x41C))
/*  Alternate Function Select       */
#define GPIO_C_AFSEL									*((u32*)(PORTC_BASE_ADDRESS+0x420))
/*  2mA Drive Select                */
#define GPIO_C_DR2R									    *((u32*)(PORTC_BASE_ADDRESS+0x500))
/*  4mA Drive Select                */
#define GPIO_C_DR4R									    *((u32*)(PORTC_BASE_ADDRESS+0x504))
/*  8mA Drive Select                */
#define GPIO_C_DR8R									    *((u32*)(PORTC_BASE_ADDRESS+0x508))
/*  Open Drain Select               */
#define GPIO_C_ODR									    *((u32*)(PORTC_BASE_ADDRESS+0x50C))
/*  Pull Up Select                  */
#define GPIO_C_PUR										*((u32*)(PORTC_BASE_ADDRESS+0x510))
/*  Pull down select                */
#define GPIO_C_PDR										*((u32*)(PORTC_BASE_ADDRESS+0x514))
/*  Slew Rate                       */
#define GPIO_C_SLR										*((u32*)(PORTC_BASE_ADDRESS+0x518))
/*  Digital Enable                  */
#define GPIO_C_DEN										*((u32*)(PORTC_BASE_ADDRESS+0x51C))
/*  GPIO Lock                       */
#define GPIO_C_LOCK									    *((u32*)(PORTC_BASE_ADDRESS+0x520))
/*  GPIO Commit                     */
#define GPIO_C_CR										*((u32*)(PORTC_BASE_ADDRESS+0x524))
/*  GPIO Analog Mode Select         */
#define GPIO_C_AMSEL									*((u32*)(PORTC_BASE_ADDRESS+0x528))
/*  GPIO Port Control               */
#define GPIO_C_PCTL									    *((u32*)(PORTC_BASE_ADDRESS+0x52C))
/*  ADC Control                     */
#define GPIO_C_ADCCTL								    *((u32*)(PORTC_BASE_ADDRESS+0x530))
/*  GPIO DMA Control                */
#define GPIO_C_DMACTL								    *((u32*)(PORTC_BASE_ADDRESS+0x534))
																																 
                                      /*PORTD*/
/*  Register that contains data(RW) */
#define GPIO_D_DATA									    *((u32*)(PORTD_BASE_ADDRESS+0x3FC))
/*  Register that sets data(RW)     */
#define GPIO_D_DIR										*((u32*)(PORTD_BASE_ADDRESS+0x400))
/*  Register Interrupt Sense(RW)    */
#define GPIO_D_IS										*((u32*)(PORTD_BASE_ADDRESS+0x404))
/*  Interrupt Both Edges(RW)        */
#define GPIO_D_IBE										*((u32*)(PORTD_BASE_ADDRESS+0x408))
/*  Interrupt Event(RW)             */
#define GPIO_D_IEV										*((u32*)(PORTD_BASE_ADDRESS+0x40C))
/*  Interrupt Mask(RW)              */
#define GPIO_D_IM										*((u32*)(PORTD_BASE_ADDRESS+0x410))
/*  RAW Interrupt Status(RO)        */
#define GPIO_D_RIS										*((u32*)(PORTD_BASE_ADDRESS+0x414))
/*  Masked Interrupt Status         */
#define GPIO_D_MIS										*((u32*)(PORTD_BASE_ADDRESS+0x418))
/*  Interrupt Clear                 */
#define GPIO_D_ICR										*((u32*)(PORTD_BASE_ADDRESS+0x41C))
/*  Alternate Function Select       */
#define GPIO_D_AFSEL									*((u32*)(PORTD_BASE_ADDRESS+0x420))
/*  2mA Drive Select                */
#define GPIO_D_DR2R									    *((u32*)(PORTD_BASE_ADDRESS+0x500))
/*  4mA Drive Select                */
#define GPIO_D_DR4R						    			*((u32*)(PORTD_BASE_ADDRESS+0x504))
/*  8mA Drive Select                */
#define GPIO_D_DR8R							    		*((u32*)(PORTD_BASE_ADDRESS+0x508))
/*  Open Drain Select               */
#define GPIO_D_ODR							    		*((u32*)(PORTD_BASE_ADDRESS+0x50C))
/*  Pull Up Select                  */
#define GPIO_D_PUR										*((u32*)(PORTD_BASE_ADDRESS+0x510))
/*  Pull down select                */
#define GPIO_D_PDR										*((u32*)(PORTD_BASE_ADDRESS+0x514))
/*  Slew Rate                       */
#define GPIO_D_SLR										*((u32*)(PORTD_BASE_ADDRESS+0x518))
/*  Digital Enable                  */
#define GPIO_D_DEN										*((u32*)(PORTD_BASE_ADDRESS+0x51C))
/*  GPIO Lock                       */
#define GPIO_D_LOCK								    	*((u32*)(PORTD_BASE_ADDRESS+0x520))
/*  GPIO Commit                     */
#define GPIO_D_CR										*((u32*)(PORTD_BASE_ADDRESS+0x524))
/*  GPIO Analog Mode Select         */
#define GPIO_D_AMSEL									*((u32*)(PORTD_BASE_ADDRESS+0x528))
/*  GPIO Port Control               */
#define GPIO_D_PCTL								    	*((u32*)(PORTD_BASE_ADDRESS+0x52C))
/*  ADC Control                     */
#define GPIO_D_ADCCTL						    		*((u32*)(PORTD_BASE_ADDRESS+0x530))
/*  GPIO DMA Control                */
#define GPIO_D_DMACTL						    		*((u32*)(PORTD_BASE_ADDRESS+0x534))
																																 
                                     /*PORTE*/
/*  Register that contains data(RW) */
#define GPIO_E_DATA								    	*((u32*)(PORTE_BASE_ADDRESS+0x3FC))
/*  Register that sets data(RW)     */
#define GPIO_E_DIR									   	*((u32*)(PORTE_BASE_ADDRESS+0x400))
/*  Register Interrupt Sense(RW)    */
#define GPIO_E_IS										*((u32*)(PORTE_BASE_ADDRESS+0x404))
/*  Interrupt Both Edges(RW)        */
#define GPIO_E_IBE										*((u32*)(PORTE_BASE_ADDRESS+0x408))
/*  Interrupt Event(RW)             */
#define GPIO_E_IEV										*((u32*)(PORTE_BASE_ADDRESS+0x40C))
/*  Interrupt Mask(RW)              */
#define GPIO_E_IM										*((u32*)(PORTE_BASE_ADDRESS+0x410))
/*  RAW Interrupt Status(RO)        */
#define GPIO_E_RIS										*((u32*)(PORTE_BASE_ADDRESS+0x414))
/*  Masked Interrupt Status         */
#define GPIO_E_MIS										*((u32*)(PORTE_BASE_ADDRESS+0x418))
/*  Interrupt Clear                 */
#define GPIO_E_ICR										*((u32*)(PORTE_BASE_ADDRESS+0x41C))
/*  Alternate Function Select       */
#define GPIO_E_AFSEL									*((u32*)(PORTE_BASE_ADDRESS+0x420))
/*  2mA Drive Select                */
#define GPIO_E_DR2R				    					*((u32*)(PORTE_BASE_ADDRESS+0x500))
/*  4mA Drive Select                */
#define GPIO_E_DR4R					    				*((u32*)(PORTE_BASE_ADDRESS+0x504))
/*  8mA Drive Select                */
#define GPIO_E_DR8R						    			*((u32*)(PORTE_BASE_ADDRESS+0x508))
/*  Open Drain Select               */
#define GPIO_E_ODR										*((u32*)(PORTE_BASE_ADDRESS+0x50C))   
/*  Pull Up Select                  */
#define GPIO_E_PUR										*((u32*)(PORTE_BASE_ADDRESS+0x510))
/*  Pull down select                */
#define GPIO_E_PDR										*((u32*)(PORTE_BASE_ADDRESS+0x514))
/*  Slew Rate                       */
#define GPIO_E_SLR										*((u32*)(PORTE_BASE_ADDRESS+0x518))
/*  Digital Enable                  */
#define GPIO_E_DEN										*((u32*)(PORTE_BASE_ADDRESS+0x51C))
/*  GPIO Lock                       */
#define GPIO_E_LOCK							    		*((u32*)(PORTE_BASE_ADDRESS+0x520))
/*  GPIO Commit                     */
#define GPIO_E_CR										*((u32*)(PORTE_BASE_ADDRESS+0x524))
/*  GPIO Analog Mode Select         */
#define GPIO_E_AMSEL									*((u32*)(PORTE_BASE_ADDRESS+0x528))
/*  GPIO Port Control               */
#define GPIO_E_PCTL						    			*((u32*)(PORTE_BASE_ADDRESS+0x52C))
/*  ADC Control                     */
#define GPIO_E_ADCCTL						    		*((u32*)(PORTE_BASE_ADDRESS+0x530))
/*  GPIO DMA Control                */
#define GPIO_E_DMACTL							    	*((u32*)(PORTE_BASE_ADDRESS+0x534))

	                                /*PORTF*/
/*  Register that contains data(RW) */
#define GPIO_F_DATA									    *((u32*)(PORTF_BASE_ADDRESS+0x3FC))
/*  Register that sets data(RW)     */
#define GPIO_F_DIR										*((u32*)(PORTF_BASE_ADDRESS+0x400))
/*  Register Interrupt Sense(RW)    */
#define GPIO_F_IS										*((u32*)(PORTF_BASE_ADDRESS+0x404))
/*  Interrupt Both Edges(RW)        */
#define GPIO_F_IBE										*((u32*)(PORTF_BASE_ADDRESS+0x408))
/*  Interrupt Event(RW)             */
#define GPIO_F_IEV										*((u32*)(PORTF_BASE_ADDRESS+0x40C))
/*  Interrupt Mask(RW)              */
#define GPIO_F_IM										*((u32*)(PORTF_BASE_ADDRESS+0x410))
/*  RAW Interrupt Status(RO)        */
#define GPIO_F_RIS										*((u32*)(PORTF_BASE_ADDRESS+0x414))
/*  Masked Interrupt Status         */
#define GPIO_F_MIS										*((u32*)(PORTF_BASE_ADDRESS+0x418))
/*  Interrupt Clear                 */
#define GPIO_F_ICR										*((u32*)(PORTF_BASE_ADDRESS+0x41C))
/*  Alternate Function Select       */
#define GPIO_F_AFSEL									*((u32*)(PORTF_BASE_ADDRESS+0x420))
/*  2mA Drive Select                */
#define GPIO_F_DR2R						    			*((u32*)(PORTF_BASE_ADDRESS+0x500))
/*  4mA Drive Select                */
#define GPIO_F_DR4R							    		*((u32*)(PORTF_BASE_ADDRESS+0x504))
/*  8mA Drive Select                */
#define GPIO_F_DR8R								    	*((u32*)(PORTF_BASE_ADDRESS+0x508))
/*  Open Drain Select               */
#define GPIO_F_ODR										*((u32*)(PORTF_BASE_ADDRESS+0x50C))   
/*  Pull Up Select                  */
#define GPIO_F_PUR										*((u32*)(PORTF_BASE_ADDRESS+0x510))
/*  Pull down select                */
#define GPIO_F_PDR										*((u32*)(PORTF_BASE_ADDRESS+0x514))
/*  Slew Rate                       */
#define GPIO_F_SLR										*((u32*)(PORTF_BASE_ADDRESS+0x518))
/*  Digital Enable                  */
#define GPIO_F_DEN										*((u32*)(PORTF_BASE_ADDRESS+0x51C))
/*  GPIO Lock                       */
#define GPIO_F_LOCK								    	*((u32*)(PORTF_BASE_ADDRESS+0x520))
/*  GPIO Commit                     */
#define GPIO_F_CR										*((u32*)(PORTF_BASE_ADDRESS+0x524))
/*  GPIO Analog Mode Select         */
#define GPIO_F_AMSEL									*((u32*)(PORTF_BASE_ADDRESS+0x528))
/*  GPIO Port Control               */
#define GPIO_F_PCTL									    *((u32*)(PORTF_BASE_ADDRESS+0x52C))
/*  ADC Control                     */
#define GPIO_F_ADCCTL						    		*((u32*)(PORTF_BASE_ADDRESS+0x530))
/*  GPIO DMA Control                */
#define GPIO_F_DMACTL							    	*((u32*)(PORTF_BASE_ADDRESS+0x534))




#define GPIO_ENABLE_PULL					            (u32)1








/*
 * Description: This API will be used to initialize port
 * with required direction whether it is input or output
 * Parameters :
 *              ->Port      (GPIO_PORTA ,GPIO_PORTB ,GPIO_PORTC
 *                              GPIO_PORTD ,GPIO_PORTE ,GPIO_PORTF)
 *              ->Pin       (GPIO_PIN0 ,GPIO_PIN1 ,GPIO_PIN2
 *                              GPIO_PIN3 ,GPIO_PIN4 ,GPIO_PIN5
 *                              GPIO_PIN6 ,GPIO_PIN7)
 *              ->Direction (GPIO_INPUT ,GPIO_OUTPUT)
 * Return :
 *              ->State
 *                      ERROR_OK : if the function is executed correctly
 *                      ERROR_NOK : if the function is not executed correctly
 */
ERROR_S GPIO_Init (u8 Port, u8 Pin, u8 Direction)
{
	/*According to chosen port, write in the direction register corresponding to selected pin*/
		/*#1 Corresponds to port A*/
		if (Port ==1)
		{
			/*If chosen mode is zero (which means input), write the corresponding value of input in register*/
			if (Direction==0)
			{
				GPIO_A_DIR &= ~(GPIO_INPUT<<Pin);
				GPIO_A_DEN |=   GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is one (which means output), write the corresponding value of output in register*/
			else if (Direction==1)
			{
				GPIO_A_DIR  |= GPIO_OUTPUT<<Pin;
				GPIO_A_DEN  |=   GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
		}
		/*#2 Corresponds to port B*/
		else if (Port ==2)
		{
			/*If chosen mode is zero (which means input), write the corresponding value of input in register*/
			if (Direction==0)
			{
				GPIO_B_DIR  &= ~(GPIO_INPUT<<Pin);
				GPIO_B_DEN  |=   GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is one (which means output), write the corresponding value of output in register*/
			else if (Direction==1)
			{
				GPIO_B_DIR  |= GPIO_OUTPUT<<Pin;
				GPIO_B_DEN  |=   GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
		}
		/*#3 Corresponds to port C*/
		else if (Port ==3)
		{
			/*If chosen mode is zero (which means input), write the corresponding value of input in register*/
			if (Direction==0)
			{
				GPIO_C_DIR &= ~(GPIO_INPUT<<Pin);
				GPIO_C_DEN |=   GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is one (which means output), write the corresponding value of output in register*/
			else if (Direction==1)
			{
				GPIO_C_DIR  |= GPIO_OUTPUT<<Pin;
				GPIO_C_DEN  |=   GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
		}
		/*#4 Corresponds to port D*/
		else if (Port ==4)
		{
			/*If chosen mode is zero (which means input), write the corresponding value of input in register*/
			if (Direction==0)
			{
				GPIO_D_DIR  &= ~(GPIO_INPUT<<Pin);
				GPIO_D_DEN  |=   GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is one (which means output), write the corresponding value of output in register*/
			else if (Direction==1)
			{
				GPIO_D_DIR  |= GPIO_OUTPUT<<Pin;
				GPIO_D_DEN  |=   GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
		}
		/*#5 Corresponds to port E*/
		else if (Port ==5)
		{
			/*If chosen mode is zero (which means input), write the corresponding value of input in register*/
			if (Direction==0)
			{
				GPIO_E_DIR &= ~(GPIO_INPUT<<Pin);
				GPIO_E_DEN |=   GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is one (which means output), write the corresponding value of output in register*/
			else if (Direction==1)
			{
				GPIO_E_DIR  |= GPIO_OUTPUT<<Pin;
				GPIO_E_DEN  |=   GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
		}
		/*#6 Corresponds to port F*/
		else if (Port ==6)
		{
			/*If chosen mode is zero (which means input), write the corresponding value of input in register*/
			if (Direction==GPIO_INPUT)
			{
				GPIO_F_DIR  &=  ~(GPIO_OUTPUT<<Pin);
				GPIO_F_DEN  |=  GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is one (which means output), write the corresponding value of output in register*/
			else if (Direction==1)
			{
				GPIO_F_DIR |=   GPIO_OUTPUT<<Pin;
				GPIO_F_DEN |=   GPIO_OUTPUT<<Pin;
				return ERROR_OK;
			}
		}
		/*If all the conditions failed, return error as not ok*/
		return ERROR_NOK;
}

/*
 * Description: This API will be used to write value on Pin
 * Parameters :
 *              ->Port      (GPIO_PORTA ,GPIO_PORTB ,GPIO_PORTC
 *                              GPIO_PORTD ,GPIO_PORTE ,GPIO_PORTF)
 *              ->Pin       (GPIO_PIN0 ,GPIO_PIN1 ,GPIO_PIN2
 *                              GPIO_PIN3 ,GPIO_PIN4 ,GPIO_PIN5
 *                              GPIO_PIN6 ,GPIO_PIN7)
 *              ->Value
 *                       If it is output: (GPIO_OUTPUT_LOW ,GPIO_OUTPUT_HIGH)
 *                       If it is input : (GPIO_INPUT_PULLUP ,GPIO_INPUT_PULLDOWN)
 *  Return :
 *              ->State
 *                      ERROR_OK : if the function is executed correctly
 *                      ERROR_NOK : if the function is not executed correctly
 */
ERROR_S GPIO_WritePin (u8 Port, u8 Pin, u8 Value)
{
	/*According to chosen port, write in the data register corresponding to selected pin*/
		/*#1 Corresponds to port A*/
		if (Port ==1)
		{
			/*If chosen mode is zero (which means low), write the corresponding value of Output Low in register*/
			if (Value==0)
			{
				GPIO_A_DATA &= ~(GPIO_OUTPUT_HIGH<<Pin);
				return ERROR_OK;
			}
			/*If chosen mode is one (which means high), write the corresponding value of output High in register*/
			else if (Value==1)
			{
				GPIO_A_DATA |= GPIO_OUTPUT_HIGH<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is two (which means input pull up), write the corresponding value to pull up register*/
			else if (Value==2)
			{
				GPIO_A_PUR |= GPIO_ENABLE_PULL<<Pin;
			
			}
			/*If chosen mode is three (which means input pull down), write the corresponding value to pull down register*/
			else if (Value==3)
			{
				GPIO_A_PDR |= GPIO_ENABLE_PULL<<Pin;
			
			}
		}
		/*#2 Corresponds to port B*/
		else if (Port ==2)
		{
			/*If chosen mode is zero (which means low), write the corresponding value of Output Low in register*/
			if (Value==0)
			{
				GPIO_B_DATA &= ~(GPIO_OUTPUT_HIGH<<Pin);
				return ERROR_OK;
			}
			/*If chosen mode is one (which means high), write the corresponding value of output High in register*/
			else if (Value==1)
			{
				GPIO_B_DATA  |= GPIO_OUTPUT_HIGH<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is two (which means input pull up), write the corresponding value to pull up register*/
			else if (Value==2)
			{
				GPIO_B_PUR |= GPIO_ENABLE_PULL<<Pin;
			
			}
			/*If chosen mode is three (which means input pull down), write the corresponding value to pull down register*/
			else if (Value==3)
			{
				GPIO_B_PDR |= GPIO_ENABLE_PULL<<Pin;
			
			}
		}
		/*#3 Corresponds to port C*/
		else if (Port ==3)
		{
			/*If chosen mode is zero (which means low), write the corresponding value of Output Low in register*/
			if (Value==0)
			{
				GPIO_C_DATA &= ~(GPIO_OUTPUT_HIGH<<Pin);
				return ERROR_OK;
			}
			/*If chosen mode is one (which means high), write the corresponding value of output High in register*/
			else if (Value==1)
			{
				GPIO_C_DATA  |= GPIO_OUTPUT_HIGH<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is two (which means input pull up), write the corresponding value to pull up register*/
			else if (Value==2)
			{
				GPIO_C_PUR |= GPIO_ENABLE_PULL<<Pin;
			
			}
			/*If chosen mode is three (which means input pull down), write the corresponding value to pull down register*/
			else if (Value==3)
			{
				GPIO_C_PDR |= GPIO_ENABLE_PULL<<Pin;
			
			}
		}
		/*#4 Corresponds to port D*/
		else if (Port ==4)
		{
			/*If chosen mode is zero (which means low), write the corresponding value of Output Low in register*/
			if (Value==0)
			{
				GPIO_D_DATA &= ~(GPIO_OUTPUT_HIGH<<Pin);
				return ERROR_OK;
			}
			/*If chosen mode is one (which means high), write the corresponding value of output High in register*/
			else if (Value==1)
			{
				GPIO_D_DATA  |= GPIO_OUTPUT_HIGH<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is two (which means input pull up), write the corresponding value to pull up register*/
			else if (Value==2)
			{
				GPIO_D_PUR |= GPIO_ENABLE_PULL<<Pin;
			
			}
			/*If chosen mode is three (which means input pull down), write the corresponding value to pull down register*/
			else if (Value==3)
			{
				GPIO_D_PDR |= GPIO_ENABLE_PULL<<Pin;
			
			}
		}
		/*#5 Corresponds to port E*/
		else if (Port ==5)
		{
			/*If chosen mode is zero (which means low), write the corresponding value of Output Low in register*/
			if (Value==0)
			{
				GPIO_E_DATA &= ~(GPIO_OUTPUT_HIGH<<Pin);
				return ERROR_OK;
			}
			/*If chosen mode is one (which means high), write the corresponding value of output High in register*/
			else if (Value==1)
			{
				GPIO_E_DATA  |= GPIO_OUTPUT_HIGH<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is two (which means input pull up), write the corresponding value to pull up register*/
			else if (Value==2)
			{
				GPIO_E_PUR |= GPIO_ENABLE_PULL<<Pin;
			
			}
			/*If chosen mode is three (which means input pull down), write the corresponding value to pull down register*/
			else if (Value==3)
			{
				GPIO_E_PDR |= GPIO_ENABLE_PULL<<Pin;
			
			}
		}
		/*#6 Corresponds to port F*/
		else if (Port ==6)
		{
			/*If chosen mode is zero (which means low), write the corresponding value of Output Low in register*/
			if (Value==0)
			{
				GPIO_F_DATA &= ~(GPIO_OUTPUT_HIGH<<Pin);
				return ERROR_OK;
			}
			/*If chosen mode is one (which means high), write the corresponding value of output High in register*/
			else if (Value==1)
			{
				GPIO_F_DATA |= GPIO_OUTPUT_HIGH<<Pin;
				return ERROR_OK;
			}
			/*If chosen mode is two (which means input pull up), write the corresponding value to pull up register*/
			else if (Value==2)
			{
				GPIO_F_PUR |= GPIO_ENABLE_PULL<<Pin;
			
			}
			/*If chosen mode is three (which means input pull down), write the corresponding value to pull down register*/
			else if (Value==3)
			{
				GPIO_F_PDR |= GPIO_ENABLE_PULL<<Pin;
			
			}
		}
		/*If all the conditions failed, return error as not ok*/
		return ERROR_NOK;
}

/*
 * Description: This API will be used to get status of pin
 * Parameters :
 *              ->Port      (GPIO_PORTA ,GPIO_PORTB ,GPIO_PORTC
 *                              GPIO_PORTD ,GPIO_PORTE ,GPIO_PORTF)
 *              ->Pin       (GPIO_PIN0 ,GPIO_PIN1 ,GPIO_PIN2
 *                              GPIO_PIN3 ,GPIO_PIN4 ,GPIO_PIN5
 *                              GPIO_PIN6 ,GPIO_PIN7)
 *              ->*Value    : pointer to the return value from the pin
 *  Return :
 *              ->State
 *                      ERROR_OK : if the function is executed correctly
 *                      ERROR_NOK : if the function is not executed correctly
 */
ERROR_S GPIO_ReadPin (u8 Port, u8 Pin, u8* Value)
{
	/*According to chosen port, write in the data register corresponding to selected pin*/
		/*#1 Corresponds to port A*/
		if (Port ==1)
		{
			/*Return value in data register by ANDing it with one*/
			*Value =(GPIO_A_DATA>>Pin)&0x01;
		}
		/*#2 Corresponds to port B*/
		else if (Port ==2)
		{
			/*Return value in data register by ANDing it with one*/
			*Value = (GPIO_B_DATA>>Pin)&0x01;
		}
		/*#3 Corresponds to port C*/
		else if (Port ==3)
		{
			/*Return value in data register by ANDing it with one*/
			*Value = (GPIO_C_DATA>>Pin)&0x01;
		}
		/*#4 Corresponds to port D*/
		else if (Port ==4)
		{
/*Return value in data register by ANDing it with one*/
			*Value = (GPIO_D_DATA>>Pin)&0x01;
		}
		/*#5 Corresponds to port E*/
		else if (Port ==5)
		{
			/*Return value in data register by ANDing it with one*/
			*Value = (GPIO_E_DATA>>Pin)&0x01;
		}
		/*#6 Corresponds to port F*/
		else if (Port ==6)
		{
			/*Return value in data register by ANDing it with one*/
			*Value = (GPIO_F_DATA>>Pin)&0x01;
		}
		/*If all the conditions failed, return error as not ok*/
		return ERROR_NOK;
}

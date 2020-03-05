/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/*****************************************************/
/*Author  : Mahmoud Hamdy							*/
/*Version : V01			 							*/
/*Date	  :2020-02-23								*/
/*****************************************************/

/*Libraries Inclusion*/
#include "STD_TYPES.h"

/*********************************************Macros*****************************/
/*Ports to choose from*/
#define GPIO_PORTA					1
#define GPIO_PORTB					2
#define GPIO_PORTC					3
#define GPIO_PORTD					4
#define GPIO_PORTE					5
#define GPIO_PORTF					6
/*PINs*/
#define GPIO_PIN0 					0
#define GPIO_PIN1 					1
#define GPIO_PIN2 					2
#define GPIO_PIN3 					3
#define GPIO_PIN4 					4
#define GPIO_PIN5 					5
#define GPIO_PIN6 					6
#define GPIO_PIN7 					7
/*Configuration modes*/
#define GPIO_INPUT 					0
#define GPIO_OUTPUT				    1
/*OUTPUT Levels*/
#define GPIO_OUTPUT_LOW		        0
#define GPIO_OUTPUT_HIGH		    1
/*Input Pull up/down configutations*/
#define GPIO_INPUT_PULLUP		    2
#define GPIO_INPUT_PULLDOWN         3
/**********************************************************************************/
	



/*************************************APIs*****************************************/
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
ERROR_S GPIO_Init (u8 Port, u8 Pin, u8 Direction);

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
ERROR_S GPIO_WritePin (u8 Port, u8 Pin, u8 Value);

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
ERROR_S GPIO_ReadPin (u8 Port, u8 Pin, u8* Value);

#endif

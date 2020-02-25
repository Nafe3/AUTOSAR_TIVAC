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
#define GPIO_OUTPUT				1
/*OUTPUT Levels*/
#define GPIO_OUTPUT_LOW		0
#define GPIO_OUTPUT_HIGH		1
/*Input Pull up/down configutations*/
#define GPIO_INPUT_PULLUP		2
#define GPIO_INPUT_PULLDOWN 3
/**********************************************************************************/
	
/*************************************APIs*****************************************/
/*Description: This API will be used to initialize port with required direction whether it is input or output*/
Error_S GPIO_Init (u8 Port, u8 Pin, u8 Direction);

/*Description: This API will be used to write value on Pin
If it is output, values will be written as high or lower_bound
It it is input, values will either activate pull up or pull down*/
Error_S GPIO_WritePin (u8 Port, u8 Pin, u8 Value);

/*Description: This API will be used to get status of pin*/
Error_S GPIO_Read_Pin (u8 Port, u8 Pin, u8* Value);

#endif
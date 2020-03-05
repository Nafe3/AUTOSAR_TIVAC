/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#ifndef _RCC_H_
#define _RCC_H_

#define RCC_GPIO_PORTA_CLK_EN           0x00000001
#define RCC_GPIO_PORTB_CLK_EN           0x00000002
#define RCC_GPIO_PORTC_CLK_EN           0x00000004
#define RCC_GPIO_PORTD_CLK_EN           0x00000008
#define RCC_GPIO_PORTE_CLK_EN           0x00000010
#define RCC_GPIO_PORTF_CLK_EN           0x00000020


/*
 * Function:  RCC_EnableGpioClk
 * --------------------
 *  Enables The Clock For A Specific GPIO Port
 *
 *  peripheral: The Peripheral You Want To Enable Clock For
 *              RCC_GPIO_PORTA_CLK_EN : GPIO Port A Clock Enable
 *              RCC_GPIO_PORTB_CLK_EN : GPIO Port B Clock Enable
 *              RCC_GPIO_PORTC_CLK_EN : GPIO Port C Clock Enable
 *              RCC_GPIO_PORTD_CLK_EN : GPIO Port D Clock Enable
 *              RCC_GPIO_PORTE_CLK_EN : GPIO Port E Clock Enable
 *              RCC_GPIO_PORTF_CLK_EN : GPIO Port F Clock Enable
 *
 *  returns: A status
 *                 ERROR_OK : if the function is executed correctly
 *                 ERROR_NOK : if the function is not executed correctly
 */
extern ERROR_S RCC_EnableGpioClk(u32 peripheral);

#endif


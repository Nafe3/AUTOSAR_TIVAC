#include "Rcc_TivaC.h"

#define RCGCGPIO           *((volatile uint32_t*)(0x400FE000 + 0x608))

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
 *                 E_OK : if the function is executed correctly
 *                 E_NOT_OK : if the function is not executed correctly
 */
Std_ReturnType RCC_EnableGpioClk(uint32_t peripheral)
{
    RCGCGPIO |= peripheral;
    return E_OK;
}
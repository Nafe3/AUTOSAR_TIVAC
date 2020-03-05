/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#ifndef HLAMP_INTERFACE_H
#define HLAMP_INTERFACE_H



#define   LAMP1         0
#define   LAMP1_PIN     GPIO_PIN1
#define   LAMP1_PORT    GPIO_PORTF


/*
 * Description : This API shall initiate the lamp on the selected channel
 * inputs:
 *         LAMP_ch_No  >>        LAMP1
 * output:
 *         ERROR_S       >>      ERROR_OK  or  ERROR_NOK
 */
extern ERROR_S Lamp_Init(u8 LAMP_ch_No);

/*
 * Description : This API shall set the lamp on the selected channel value to ON
 * inputs:
 *         LAMP_ch_No  >>        LAMP1
 * output:
 *         ERROR_S       >>      ERROR_OK  or  ERROR_NOK
 */
extern ERROR_S Lamp_ON(u8  LAMP_ch_No);

/*
 * Description : This API shall set the lamp on the selected channel value to OFF
 * inputs:
 *         LAMP_ch_No  >>        LAMP1
 * output:
 *         ERROR_S       >>      ERROR_OK  or  ERROR_NOK
 */
extern ERROR_S Lamp_OFF(u8 LAMP_ch_No);

#endif

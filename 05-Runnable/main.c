/**************************************************************************/
/*            Author    : Kariman ,Sara ,Mira ,Hamdy ,Nafea               */
/*            DATE      : Feb 25 2020                                     */
/*            Version   : Version 2                                       */
/**************************************************************************/

#include "STD_TYPES.h"
#include "Lighting.h"


int main(void)
{
    /*   Initializing the system application   */
    LIGHT_Init();

    while(1)
    {
        /* start the Runnable application */
        LIGHT_System();
    }

}

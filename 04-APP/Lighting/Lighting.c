#include "Lighting.h"
//header el hals
#define  NUM    (u8)1
#define HIGH      (u8)1   
ERROR_S   LIGHT_Init(void)
{
  
  LAMP_Init(NUM);
  
}
ERROR_S LIGH_System(u8 *LedState)
{
  LDOOR_ReadStatus(&LedState);
  RDOOR_ReadStatus(&LedState);
  if(LedState==HIGH)
  {
    LIGHT_ON();

  }
  else
  {
    LIGHT_OFF();

  }

}
ERROR_S   LIGHT_ON(void)
{
  LAMP_ON(NUM);

}
ERROR_S   LIGHT_OFF(void)

{
  LAMP_OFF(NUM);
}
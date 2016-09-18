#ifndef _GPIO_H_
#define _GPIO_H_

typedef enum 
{
    E_QUASI_BIDIRECTIONAL,  //Quasi-Bidirectional
    E_PUSH_UP,              //Push-Pull
    E_INPUT_ONLY,           //Input-Only
    E_OPEN_DRAIN,           //Open-Drain
    E_GPIO_MODE_END
} E_GPIO_MODE;

void Set_Port0_GPIO_Mode(E_GPIO_MODE GpioMode);
void Set_Port1_GPIO_Mode(E_GPIO_MODE GpioMode);
void Set_Port2_GPIO_Mode(E_GPIO_MODE GpioMode);
void Set_Port3_GPIO_Mode(E_GPIO_MODE GpioMode);
void Set_All_GPIO_Quasi_Mode(void);

#endif
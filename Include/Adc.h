#ifndef _ADC_H_
#define _ADC_H_

typedef enum
{
    ADC_PIN0 = 0,
    ADC_PIN1,
    ADC_PIN2,
    ADC_PIN3,
    ADC_PIN4,
    ADC_PIN5,
    ADC_PIN6,
    ADC_PIN7,
    ADC_PIN8,
    ADC_PIN9,
    ADC_PIN_MAX
}E_ADC_PIN_SEL;

typedef enum
{
    ADC_DIV0 = 0,
    ADC_DIV1,
    ADC_DIV2,
    ADC_DIV3,
    ADC_DIV4,
    ADC_DIV5,
    ADC_DIV6,
    ADC_DIV7,
    ADC_DIV8,
    ADC_DIV_MAX
}E_ADC_DIV_SEL;

void ADC_Vref_Select (UINT8 u8AdcVrefSel);
void ADC_Pin_Select (UINT8 u8AdcPinSel);
void ADC_DIV_Select (UINT8 u8Adc_Div_Sel);
void ADC_Initial (UINT8 u8AdcVrefSel, UINT8 u8AdcPinSel, UINT8 u8Adc_Div_Sel);

#endif

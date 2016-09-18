/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2015 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp. 
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/21/2015
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: N76E885 ADC demo code
//***********************************************************************************************************

#include <stdio.h>
#include "Common.h"

/*
//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
//
//<e0> System Clock Source Configuration
// <o1> System Clock Source Selection
//      <0=> 2~25MHz    XTAL
//      <1=> 32.768KHz  XTAL
//      <2=> 22.1184MHz Internal
//      <3=> 10KHz      Internal
//      <4=> OSC-In     External
//</e>
//
//<e2> Clock Divider Configuration
//     <o3.0..7>  System Clock Source Devider <1-255:1>
//                     <i> Fsys = (System Clock Source) / (2 * Devider)
//</e>
//
//<h> ADC Option
// <o6> ADC VREFSEL Selection 
//      <0=> VDD <1=> VREF(AIN0)
//
// <o4.0..3> ADC Pin Selection 
//      <0=> AIN0 (P00) <1=> AIN1 (P01) <2=> AIN2 (P02) <3=> AIN3 (P03)
//      <4=> AIN4 (P04) <5=> AIN5 (P05) <6=> AIN6 (P06) <7=> AIN7 (P07)
//      <8=> AIN8 (P26) <9=> AIN9 (P20) <10=> Band-Gap
//
// <o5.0..2> ADC Divider Selection 
//      <0=> Fsys/1  <1=> Fsys/2   <2=> Fsys/4   <3=> Fsys/8
//      <4=> Fsys/16 <5=> Fsys/32  <6=> Fsys/64  <7=> Fsys/128
//
//</h>
//
//-------- <<< end of configuration section >>> ------------------------------
*/

/******************************************************************************
 * FUNCTION_PURPOSE: ADC Vref Selection
 ******************************************************************************/
void ADC_Vref_Select (UINT8 u8AdcVrefSel)
{
    if(u8AdcVrefSel == 0)
    {
        clr_VREFSEL;                      //VREFSEL = VDD
    }
    else if(u8AdcVrefSel == 1)
    {
        set_VREFSEL;                      //VREFSEL = VREF(AIN0)
    }
}
/******************************************************************************
 * FUNCTION_PURPOSE: ADC Pin Select
 ******************************************************************************/
void ADC_Pin_Select (UINT8 u8AdcPinSel)
{
    switch(u8AdcPinSel)
    {
        case ADC_PIN0:                      //P0.0
        {
          ADCCON0 = 0x00;                   //select ADC pin
          set_P0M1_0;                       //set ADC pin is input only mode
          clr_P0M2_0;
          set_P00DIDS;                      //disable digital connection
        }
        break;
      
        case ADC_PIN1:                      //P0.1
        {
          ADCCON0 = 0x01;                   //select ADC pin
          set_P0M1_1;                       //set ADC pin is input only mode
          clr_P0M2_1;
          set_P01DIDS;                      //disable digital connection
        }
        break;
      
        case ADC_PIN2:                      //P0.2
        {
          ADCCON0 = 0x02;                   //select ADC pin
          set_P0M1_2;                       //set ADC pin is input only mode
          clr_P0M2_2;
          set_P02DIDS;                      //disable digital connection
        }
        break;
      
        case ADC_PIN3:                      //P0.3
        {
          ADCCON0 = 0x03;                   //select ADC pin
          set_P0M1_3;                       //set ADC pin is input only mode
          clr_P0M2_3;
          set_P03DIDS;                      //disable digital connection
        }
        break;
      
        case ADC_PIN4:                      //P0.4
        {
          ADCCON0 = 0x04;                   //select ADC pin
          set_P0M1_4;                       //set ADC pin is input only mode
          clr_P0M2_4;
          set_P04DIDS;                      //disable digital connection
        }
        break;
      
        case ADC_PIN5:                      //P0.5
        {
          ADCCON0 = 0x05;                   //select ADC pin
          set_P0M1_5;                       //set ADC pin is input only mode
          clr_P0M2_5;
          set_P05DIDS;                      //disable digital connection
        }
        break;
      
        case ADC_PIN6:                      //P0.6
        {
          ADCCON0 = 0x06;                   //select ADC pin
          set_P0M1_6;                       //set ADC pin is input only mode
          clr_P0M2_6;
          set_P06DIDS;                      //disable digital connection
        }
        break;
      
        case ADC_PIN7:                      //P0.7
        {
          ADCCON0 = 0x07;                   //select ADC pin
          set_P0M1_7;                       //set ADC pin is input only mode
          clr_P0M2_7;
          set_P07DIDS;                      //disable digital connection
        }
        break;
      
        case ADC_PIN8:                      //P2.6
        {
          ADCCON0 = 0x08;                   //select ADC pin
          set_P2M1_6;                       //set ADC pin is input only mode
          clr_P2M2_6;
          set_P26DIDS;                      //disable digital connection
        }
        break;
      
        case ADC_PIN9:                      //P2.0
        {
          ADCCON0 = 0x09;                   //select ADC pin
          set_P2M1_0;                       //set ADC pin is input only mode
          clr_P2M2_0;
          set_P20DIDS;                      //disable digital connection
        }
        break;

        default:
          ADCCON0 |= 0x0F;                  //band-gap 1.25V
        break;
    }
}
/******************************************************************************
 * FUNCTION_PURPOSE: ADC Clock Divider Select
 ******************************************************************************/
void ADC_DIV_Select (UINT8 u8Adc_Div_Sel)
{
    switch(u8Adc_Div_Sel)
    {
        case ADC_DIV0:
      {
          clr_ADCDIV2;
          clr_ADCDIV1;
          clr_ADCDIV0;
        }
      break;
      
      case ADC_DIV1:
      {
          clr_ADCDIV2;
          clr_ADCDIV1;
          set_ADCDIV0;
      }
      break;
      
      case ADC_DIV2:      //Default
      {
          clr_ADCDIV2;
          set_ADCDIV1;
          clr_ADCDIV0;
      }
      break;
      
        case ADC_DIV3:
      {
          clr_ADCDIV2;
          set_ADCDIV1;
          set_ADCDIV0;
        }
      break;
      
        case ADC_DIV4:
      {
          clr_ADCDIV2;
          clr_ADCDIV1;
          set_ADCDIV0;
      }
      break;
      
        case ADC_DIV5:
      {
          set_ADCDIV2;
          clr_ADCDIV1;
          clr_ADCDIV0;
        }
        break;
      
      case ADC_DIV6:
      {
          set_ADCDIV2;
          clr_ADCDIV1;
          set_ADCDIV0;
      }
      break;
      
      case ADC_DIV7:
      {
          set_ADCDIV2;
          set_ADCDIV1;
          clr_ADCDIV0;
      }
      break;
      
        case ADC_DIV8:
      {
          set_ADCDIV2;
          set_ADCDIV1;
          set_ADCDIV0;
        }
      break;

      default:
      break;
    }
}

/******************************************************************************
 * FUNCTION_PURPOSE: ADC Initial
 ******************************************************************************/
void ADC_Initial (UINT8 u8AdcVrefSel, UINT8 u8AdcPinSel, UINT8 u8Adc_Div_Sel)
{
    set_ADCEN;
    ADC_Vref_Select(u8AdcVrefSel);                         //Select ADC Vref
    ADC_Pin_Select(u8AdcPinSel);                           //Select ADC Pin
    ADC_DIV_Select(u8Adc_Div_Sel);                         //Set ADC Clock Divider
}


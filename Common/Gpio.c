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

#include <absacc.h> 
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
//     <o3.0..7>  System Clock Source Devider  <1-255:1>
//                     <i> Fsys = (System Clock Source) / (2 * Devider)
//</e>
//
// <o4> Port0 Mode Selection (P0[7:0])
//      <0=> Quasi-Bidirectional
//      <1=> Push-Pull
//      <2=> Input-Only (high-impedance)
//      <3=> Open-Drain
//
// <o5> Port1 Mode Selection (P1[1:0])
//      <0=> Quasi-Bidirectional
//      <1=> Push-Pull
//      <2=> Input-Only (high-impedance)
//      <3=> Open-Drain
//
// <o6> Port2 Mode Selection (P2[6:0])
//      <0=> Quasi-Bidirectional
//      <1=> Push-Pull
//      <2=> Input-Only (high-impedance)
//      <3=> Open-Drain
//
// <o7> Port3 Mode Selection (P3[7:0])
//      <0=> Quasi-Bidirectional
//      <1=> Push-Pull
//      <2=> Input-Only (high-impedance)
//      <3=> Open-Drain
//-------- <<< end of configuration section >>> ------------------------------
*/

void Set_Port0_GPIO_Mode(E_GPIO_MODE GpioMode)
{
    switch(GpioMode)
    {
        case E_QUASI_BIDIRECTIONAL:
        {
            P0M1 = 0x00;
            P0M2 = 0x00;
        }
        break;

        case E_PUSH_UP:
        {
            P0M1 = 0x00;
            P0M2 = 0xFF;   
        }
        break;

        case E_INPUT_ONLY:
        {
            P0M1 = 0xFF;
            P0M2 = 0x00;   
        }
        break;

        case E_OPEN_DRAIN:
        {
            P0M1 = 0xFF;
            P0M2 = 0xFF;   
        }
        break;
    }
}

void Set_Port1_GPIO_Mode(E_GPIO_MODE GpioMode)
{
    switch(GpioMode)
    {
        case E_QUASI_BIDIRECTIONAL:
        {
            P1M1 = 0x00;
            P1M2 = 0x00;
        }
        break;

        case E_PUSH_UP:
        {
            P1M1 = 0x00;
            P1M2 = 0x03;   
        }
        break;

        case E_INPUT_ONLY:
        {
            P1M1 = 0x03;
            P1M2 = 0x00;   
        }
        break;

        case E_OPEN_DRAIN:
        {
            P1M1 = 0x03;
            P1M2 = 0x03;   
        }
        break;
    }
}

void Set_Port2_GPIO_Mode(E_GPIO_MODE GpioMode)
{
    switch(GpioMode)
    {
        case E_QUASI_BIDIRECTIONAL:
        {
            P2M1 = 0x00;
            P2M2 = 0x00;
        }
        break;

        case E_PUSH_UP:
        {
            P2M1 = 0x00;
            P2M2 = 0xFF;   
        }
        break;

        case E_INPUT_ONLY:
        {
            P2M1 = 0x7F;
            P2M2 = 0x00;   
        }
        break;

        case E_OPEN_DRAIN:
        {
            P2M1 = 0x7F;
            P2M2 = 0x7F;   
        }
        break;
    }
}

void Set_Port3_GPIO_Mode(E_GPIO_MODE GpioMode)
{
    switch(GpioMode)
    {
        case E_QUASI_BIDIRECTIONAL:
        {
            P3M1 = 0x00;
            P3M2 = 0x00;
        }
        break;

        case E_PUSH_UP:
        {
            P3M1 = 0x00;
            P3M2 = 0xFF;   
        }
        break;

        case E_INPUT_ONLY:
        {
            P3M1 = 0xFF;
            P3M2 = 0x00;   
        }
        break;

        case E_OPEN_DRAIN:
        {
            P3M1 = 0xFF;
            P3M2 = 0xFF;   
        }
        break;
    }
}

void Set_All_GPIO_Quasi_Mode(void)
{
    P0M1 = 0x00;
    P0M2 = 0x00;
    P1M1 = 0x00;
    P1M2 = 0x00;
    P2M1 = 0x00;
    P2M2 = 0x00;
    P3M1 = 0x00;
    P3M2 = 0x00;
}

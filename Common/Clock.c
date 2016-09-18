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

#include "Common.h"

/***************************************************************************************************
    System Clock Source Select
****************************************************************************************************/
void System_Clock_Select(E_SYSTEM_CLOCK clock)
{
    switch (clock)
    {
        case E_HXTEN:
        {
            //step1: enable clock source
            set_EXTEN1;
            clr_EXTEN0;
                
            //step2: check ready
            while((CKSWT&SET_BIT7)==0);
                
            //step3: switching system clock source
            clr_OSC1;
            set_OSC0;
        }
        break;

        case E_LXTEN:
        {
            //step1: enable clock source
            clr_EXTEN1;
            set_EXTEN0;
                
            //step2: check ready
            while((CKSWT&SET_BIT6)==0);
                
            //step3: switching system clock source
            clr_OSC1;
            set_OSC0;
        }
        break;

        case E_OSCEN:
        {
            //step1: enable clock source
            clr_EXTEN1;
            clr_EXTEN0;
                
            //step2: check ready
            while((CKSWT&SET_BIT3)==0);
                
            //step3: switching system clock source
            clr_OSC1;
            set_OSC0;
        }
        break;
        
        case E_HIRCEN: //power on default
        {
            //step1: enable clock source
            set_HIRCEN;
                
            //step2: check ready
            while((CKSWT&SET_BIT5)==0);
                
            //step3: switching system clock source
            clr_OSC1;
            clr_OSC0;
        }
        break;

        case E_LIRCEN:
        {
            //step1: enable clock source
            set_LIRCEN;
                
            //step2: check ready
            while((CKSWT&SET_BIT4)==0);
                
            //step3: switching system clock source
            set_OSC1;
            clr_OSC0;
        }
        break;
    }
   
    //step4: check system clock switching OK or NG?
    while((CKEN&SET_BIT0)==1);  //Check Clock switch fault flag.
}

/*==========================================================================*/
void SW_Reset(void)
{
    TA = 0xAA;
    TA = 0x55;
    set_SWRST;
}
/*==========================================================================*/
void Fsys_Clock_Output_On_P26(void)
{
    set_CLOEN;                                  //System Clock Output Enable
}
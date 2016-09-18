/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2015 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp. 
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : May/1/2015
//***********************************************************************************************************

#include <stdio.h>
#include "Common.h"

#define FW_Version_Major                    0x01
#define FW_Version_Minor                    0x00
#define FW_Version_Modifi                   0x00

#define Date_Y                              2016
#define Date_M                              9
#define Date_D                              16

//-----------------------------------------------------------------------------------------------------------
void Show_FW_Version_Number_To_PC(void)
{
    printf ("====================================================================\r\n");
    printf ("*    Copyright(c) 2016 Molei Technology Corp. All rights reserved.  \r\n");
    printf ("*    Contact E-Mail: mtkowen@hotmail.com                            \r\n");
    printf ("*    FW Version  : %2d.%2d.%2d\r\n",(uint16_t)FW_Version_Major,(uint16_t)FW_Version_Minor,(uint16_t)FW_Version_Modifi);
    printf ("*    Finished Date : %2d.%2d.%2d\r\n",(uint16_t)Date_Y,(uint16_t)Date_M,(uint16_t)Date_D);
    printf ("====================================================================");
}
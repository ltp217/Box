#ifndef _CLOCK_H_
#define _CLOCK_H_

typedef enum 
{
    E_HXTEN,  //External 2~24MHz
    E_LXTEN,  //External 32.768KHz
    E_HIRCEN, //Internal 22.1184MHz
    E_LIRCEN, //Internal 10KHz
    E_OSCEN,  //External OSC
    E_FOSC_MAX
} E_SYSTEM_CLOCK;

void  SW_Reset(void);
void  System_Clock_Select(E_SYSTEM_CLOCK clock);
void  Fsys_Clock_Output_On_P26(void);

extern bit BIT_TMP;

#endif
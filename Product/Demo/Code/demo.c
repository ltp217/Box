/******************************************************************************/
/*                                                                            */
/*                   RTX_EX1.C:  The first RTX-51 Program                     */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */
#include "N76E885.h"
#include "Version.h"
#include "Typedef.h"
#include "Define.h"
#include "Common.h"
#include "SFR_Macro.h"
#include "Delay.h"
#include "Semaphore.h"

#include "demo.h"                    /* project specific header file */

bit BIT_TMP;

void demo_init(void)
{
    /* Note
       MCU power on system clock is HIRC (22.1184MHz), so Fsys = 22.1184MHz
    */
    Set_All_GPIO_Quasi_Mode();
    InitialUART0_Timer1_Type2(9600);                            /* 9600 Baud Rate*/

    Show_FW_Version_Number_To_PC();

    printf ("\n*===================================================================");
    printf ("\n*  Name: N76E885 demo.c in UART0 Demo Code.");
    printf ("\n*===================================================================\n");	
}

/******************************************************************************/
/*       Task 0 'init': Initialize                                            */
/******************************************************************************/
void startup_task (void) _task_ STARTUP_TASK 
{    
    demo_init();
	
	  init_semaphore(0, 1, 1);	
	
  	os_create_task (PHASE1);            /* start task PHASE1                    */
    os_create_task (PHASE2);            /* start task PHASE2                    */
	  os_delete_task (STARTUP_TASK);      /* stop init task (no longer needed)    */
}

/******************************************************************************/
/*    Task 1 'phase1':                                                        */
/******************************************************************************/
void phase1 (void) _task_  PHASE1 
{
    while (1)  
		{                               /* endless loop */
		    pend_semaphore(0);
		    printf ("TASK # %d\n", (int)os_running_task_id ());  
		    release_semaphore(0);
    }
}

/******************************************************************************/
/*    Task 2 'phase2':                                                        */
/******************************************************************************/
void phase2 () _task_ PHASE2 
{
    while (1)
	  {                               /* endless loop */   
		    pend_semaphore(0);
		    printf ("TASK # %d\n", (int)os_running_task_id ());
		    release_semaphore(0);
    }
}

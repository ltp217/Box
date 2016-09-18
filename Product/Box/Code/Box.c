/******************************************************************************/
/*                                                                            */
/*                   BOX.C:  The Mini Box Main Program                        */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines */
#include "Common.h"
#include "Semaphore.h"

#include "Box.h"                    /* project specific header file */

bit BIT_TMP;

/******************************************************************************/
/*       System Initialize: GPIO¡¢UART0¡¢FW Version                           */
/******************************************************************************/
void sys_init(void)
{
    /* Note
       MCU power on system clock is HIRC (22.1184MHz), so Fsys = 22.1184MHz
    */
    Set_All_GPIO_Quasi_Mode();                              /* GPIO init */
   
    InitialUART0_Timer1_Type2(BAUD_RATE_9600); /* Baud Rate */

    Show_FW_Version_Number_To_PC();                         /* Fireware Version */   
}

/******************************************************************************/
/*       Task 0 'init': Initialize                                            */
/******************************************************************************/
void startup_task (void) _task_ STARTUP_TASK 
{    
    sys_init();
    
    init_semaphore(0, 1, 1);            /* semphore init */
    
    os_create_task(PHASE1);            /* start task PHASE1                    */
    os_create_task(PHASE2);            /* start task PHASE2                    */
    os_delete_task(STARTUP_TASK);      /* stop init task (no longer needed)    */
}

/******************************************************************************/
/*    Task 1 'phase1':                                                        */
/******************************************************************************/
void phase1 (void) _task_  PHASE1 
{
    while (1)  
    {                               /* endless loop */
        pend_semaphore(0);
        printf("TASK # %d\n", (int)os_running_task_id ());  
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

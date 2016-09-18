#ifndef _SERIAL_H_
#define _SERIAL_H_

#define BAUD_RATE_9600   9600
#define BAUD_RATE_38400  38400
#define BAUD_RATE_115200 115200

void  InitialUART0_Timer1_Type1(UINT32 u32Baudrate); //T1M = 0, SMOD = 0
void  InitialUART0_Timer1_Type2(UINT32 u32Baudrate); //T1M = 0, SMOD = 1
void  InitialUART0_Timer1_Type3(UINT32 u32Baudrate); //T1M = 1, SMOD = 0
void  InitialUART0_Timer1_Type4(UINT32 u32Baudrate); //T1M = 1, SMOD = 1
void  InitialUART0_Timer3_Type5(UINT32 u32Baudrate); //Timer3 as Baudrate, SMOD=0, Prescale=0
void  InitialUART0_Timer3_Type6(UINT32 u32Baudrate); //Timer3 as Baudrate, SMOD=1, Prescale=0
void  InitialUART1_Timer3(UINT32 u32Baudrate);
void  Send_Data_To_UART0(UINT8 c);
void  Send_String_To_UART0(UINT8 *str);
UINT8 Receive_Data_From_UART0(void);
void  Send_Data_To_UART1(UINT8 c);
void  Send_String_To_UART1(UINT8 *str);
UINT8 Receive_Data_From_UART1(void);

#endif
#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_

#define MAX_SEMAPHORES  3       /* ʹ���ź����������Ŀ */
#define MAX_TASK        16      /* ��������� */

#define SEM_OK          0       
#define SEM_FAIL        0xFF    /*ֻ������RTX51-tiny*/


/*�����ź���*/
typedef struct tagSEM_SET {
    uint8_t max_count;          /* ���ź�����������ֵ */
    uint8_t count;              /* ���ź����ĵ�ǰ����ֵ */
    uint16_t pending_tasks;     /* �ȴ����ź�������� */
}SEM_SET;

char pend_sem(uint8_t sem_id);
void pend_semaphore(uint8_t sem_id);
char release_sem(uint8_t sem_id);
void release_semaphore(uint8_t sem_id);
void init_semaphore(uint8_t sem_id, uint8_t max_count, uint8_t count);

extern SEM_SET sem_tab[MAX_SEMAPHORES];

#endif
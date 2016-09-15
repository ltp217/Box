#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_

#define MAX_SEMAPHORES  3       /* 使用信号量的最大数目 */
#define MAX_TASK        16      /* 最大任务数 */

#define SEM_OK          0       
#define SEM_FAIL        0xFF    /*只适用于RTX51-tiny*/


/*定义信号量*/
typedef struct tagSEM_SET {
    uint8_t max_count;          /* 该信号量的最大计数值 */
    uint8_t count;              /* 该信号量的当前计数值 */
    uint16_t pending_tasks;     /* 等待该信号量任务表 */
}SEM_SET;

char pend_sem(uint8_t sem_id);
void pend_semaphore(uint8_t sem_id);
char release_sem(uint8_t sem_id);
void release_semaphore(uint8_t sem_id);
void init_semaphore(uint8_t sem_id, uint8_t max_count, uint8_t count);

extern SEM_SET sem_tab[MAX_SEMAPHORES];

#endif
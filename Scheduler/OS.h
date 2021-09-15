 


#ifndef OS_H_
#define OS_H_

#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

#define OS_MAX_TASK_NUM ((u8)10u)  /**< Maximal task number that can be registered. */
#define OS_MAX_TIME     ((u8)10u)  /**< Maximal time that a task can run (OS_MAX_TIME*time_ticks). */
#define OS_MIN_TIME     ((u8)1u)   /**< Minimal time that a task can run (OS_MIN_TIME*time_ticks). */

typedef void (*fncPtr)(void);           /**< Function pointer for registering tasks. */

/**
 * States of the tasks.
 */
typedef enum
{
    BLOCKED = 0,                        /**< In the BLOCKED state the task waits for the timer to put it into READY state. */
    READY,                              /**< In the READY state the task is ready to be called and executed in the main function. */
    SUSPENDED                           /**< In the SUSPENDED state the task is ignored by the timer and executer. */
} OS_state;

/**
 * Variables of the tasks.
 */
typedef struct
{
    fncPtr      function;               /**< This is the task that gets called periodically. */
    u8     t_periodicity;             /**< The period we want to call it. */
    u8     time_cnt;               /**< Counter, if it reaches the time_burst, then the timer puts it into READY state. */
    OS_state    state;                  /**< The current state of the task. */
} OS_struct;

/**
 * Feedback and error handling for the task creation.
 */
typedef enum
{
    OK = 0,                             /**< OK:    Everything went as expected. */
    NOK_NULL_PTR,                       /**< ERROR: Null pointer as a task. */
    NOK_TIME_LIMIT,                     /**< ERROR: The time period is more or less, than the limits. */
    NOK_CNT_LIMIT,                      /**< ERROR: Something horrible happened, time to panic! */
    NOK_UNKNOWN
} OS_feedback;

/**
 * Functions.
 */
OS_feedback OS_TaskCreate(fncPtr task, u8 default_time_burst, OS_state default_state);
void OS_TaskTimer(void);
void OS_TaskExecution(void);
OS_state OS_GetTaskSate(u8 task_number);
u8 OS_GetTaskBurstTime(u8 task_number);
u8 OS_GetTaskCntTime(u8 task_number);
void OS_SetTaskSate(u8 task_number, OS_state new_state);
void OS_SetTaskBurstTime(u8 task_number, u8 new_time_burst);
void OS_SetTaskCntTime(u8 task_number, u8 new_time_cnt);




#endif /* OS_H_ */
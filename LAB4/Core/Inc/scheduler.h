/*
 * scheduler.h
 *
 *  Created on: Dec 10, 2024
 *      Author: VO HOANG HUY
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
/*
#include <stdint.h>
typedef struct{
	void (*pTask)(void);
	uint32_t 	Delay;
	uint32_t 	Period;
	uint8_t		RunMe;

	uint32_t TaskID;
}sTasks;

#define SCH_MAX_TASKS	40

void SCH_Init(void);
unsigned char SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);

void SCH_Delete_Task(const uint8_t TASK_INDEX);
*/
#include <stdint.h>
#define SCH_MAX_TASKS	40
#define NO_TASK_ID		0

typedef struct{
	// Pointer to the task (must be a ’ void ( void ) ’ function )
	void(*pTask)(void);
	// Delay (ticks) until the function will (next) be run
	uint32_t Delay;
	// Interval (ticks) between subsequent runs .
	uint32_t Period;
	// Incremented (by scheduler) when task i s due to execute
	uint8_t RunMe;
	uint32_t TaskID;
} sTask ;

sTask SCH_tasks_G[SCH_MAX_TASKS];
extern unsigned char current_index_task;

void SCH_Delete_Task(const unsigned char TASK_INDEX);
void SCH_Init(void);
void SCH_Add_Task (void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
#endif /* INC_SCHEDULER_H_ */

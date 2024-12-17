/*
 * scheduler.c
 *
 *  Created on: Dec 10, 2024
 *      Author: VO HOANG HUY
 */
/*#include "scheduler.h"
sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void){
	unsigned char i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}
}
unsigned char SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	unsigned char Index;
	while((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)){
		Index++;
	}
	if(Index == SCH_MAX_TASKS){
		return SCH_MAX_TASKS;
	}

	SCH_tasks_G[current_index_task].pTask = pFunction;
	SCH_tasks_G[current_index_task].Delay = DELAY;
	SCH_tasks_G[current_index_task].Period = PERIOD;
	SCH_tasks_G[current_index_task].RunMe = 0;

	return Index;

}
void SCH_Update(void){
	for(unsigned char i = 0; i < SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].pTask){
			if(SCH_tasks_G[i].Delay > 0){
				SCH_tasks_G[i].Delay--;
			}
			else{
				if(SCH_tasks_G[i].Period)SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
				SCH_tasks_G[i].RunMe += 1;
			}
		}
	}
}
void SCH_Dispatch_Tasks(void){
	for(unsigned char i = 0; i < SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
			if(SCH_tasks_G[i].Period == 0){
				SCH_Delete_Task(i);
			}
		}
	}
}

void SCH_Delete_Task(const uint8_t TASK_INDEX){
		SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
		SCH_tasks_G[TASK_INDEX].Delay = 0;
		SCH_tasks_G[TASK_INDEX].Period = 0;
		SCH_tasks_G[TASK_INDEX].RunMe = 0;
}*/
#include "scheduler.h"

unsigned char current_index_task = 0;

void SCH_Delete_Task(const unsigned char TASK_INDEX){
	unsigned char Return_code ;
	SCH_tasks_G [TASK_INDEX].pTask = 0x0000 ;
	SCH_tasks_G [TASK_INDEX].Delay = 0;
	SCH_tasks_G [TASK_INDEX].Period = 0;
	SCH_tasks_G [TASK_INDEX].RunMe = 0;
	current_index_task--;
//	return Return_code ; // return status
}
void SCH_Init(void){
	unsigned char i ;
	for(i = 0; i < current_index_task; i++){
		SCH_Delete_Task(i);
	}
}
void SCH_Add_Task( void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	if(current_index_task < SCH_MAX_TASKS){

		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY;
		SCH_tasks_G[current_index_task].Period = PERIOD;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;
	}
}

void SCH_Update(void){
	for(int i = 0; i < current_index_task; i++){
		if (SCH_tasks_G[i].Delay > 0){
			SCH_tasks_G[i].Delay --;
		}else{
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for(int i = 0; i < current_index_task; i++){
		if(i == 4){// one-shot task
			if(SCH_tasks_G[i].RunMe > 0){
				SCH_tasks_G[i].RunMe--;
				(*SCH_tasks_G[i].pTask)();
				SCH_Delete_Task(i);
			}
			//delete task out of SCH_tasks_G
		}
		else{
			if(SCH_tasks_G[i].RunMe > 0){
				SCH_tasks_G[i].RunMe--;
				(*SCH_tasks_G[i].pTask)();
			}
		}
	}
}

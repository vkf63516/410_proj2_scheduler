/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */
#include "../includes/scheduler_RR.h"


bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	bool check = p.remaining_cpu_time <= 0;
	int pttr = p.required_cpu_time - p.remaining_cpu_time;
	int ptrcs = pttr % time_slice;

	if (pttr > 0 && ptrcs == 0) {
		return true;
	}
	return check;
}

void Scheduler_RR::sort() {
	return;
}



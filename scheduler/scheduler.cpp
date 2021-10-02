/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */
#include "../includes/scheduler.h"

void Scheduler::add(PCB p) {
	ready_q -> push(p);
}

PCB Scheduler::getNext() {
	PCB receive = ready_q -> front();
	ready_q -> pop();
	return receive;
}

bool Scheduler::isEmpty() {
	if (ready_q -> empty()) {
		return true;
	}
	return false;
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	if (p.remaining_cpu_time <= 0 || (preemptive && tick_count - p.start_time >= time_slice)) {
		return true;
	}
	return false;
}

void Scheduler::sort() {
	return;
}



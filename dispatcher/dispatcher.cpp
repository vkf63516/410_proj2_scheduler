/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */
#include "../includes/dispatcher.h"

PCB Dispatcher::get_from_CPU() {
	PCB receive = cpu -> get_process_off_core();
	is_valid_job_on_cpu = receive.process_number == UNINITIALIZED;
	return receive;
}

void Dispatcher::put_on_CPU(PCB &process) {
	cpu -> put_process_on_core(process);
}

bool Dispatcher::isValidJobOnCPU() {
	PCB receive = cpu -> get_COPY_of_Current_Process();
	return !receive.isEmpty();
}




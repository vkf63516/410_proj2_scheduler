/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */
#include <algorithm>
#include <vector>
#include "../includes/scheduler_SRTF.h"

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	PCB check = ready_q->front();

	if (check.remaining_cpu_time > 0)
	{
		if (check.process_number != p.process_number)
		{
			if (check.remaining_cpu_time < p.remaining_cpu_time)
			{
				return true;
			}
		}
	}

	return p.remaining_cpu_time <= 0;
}

bool sort_remains(PCB &m1, PCB &m2) {
	return m1.remaining_cpu_time < m2.remaining_cpu_time;
}

void Scheduler_SRTF::sort() {
	std::vector<PCB> temp;

	while (!ready_q -> empty()) {
		temp.push_back(ready_q -> front());
		ready_q -> pop();
	}
	std::sort(temp.begin(), temp.end(), sort_remains);
	for (int i = 0; i < temp.size(); ++i) {
		ready_q -> push(temp.at(i));
	}

}

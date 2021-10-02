/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */
#include "../includes/stats.h"
using namespace std;

Stats::Stats(vector<PCB> &finished_vector) {
	vec = new vector<PCB>();
	*vec = finished_vector;
	av_wait_time = 0;
	av_turnaround_time = 0;
	av_response_time = 0;
}

void Stats::showAllProcessInfo() {
	for (PCB receive : *vec) {
		cout << "Process " << receive.process_number << " Required CPU time:"
				<< receive.required_cpu_time << "  arrived:" << receive.arrival_time
				<< " started:" << receive.start_time << " finished:" << receive.finish_time << endl;
	}
}

float Stats::get_av_response_time() {
	calcStats();
	return av_response_time;
}

float Stats::get_av_turnaround_time() {
	calcStats();
	return av_turnaround_time;
}

float Stats::get_av_wait_time() {
	calcStats();
	return av_wait_time;
}

void Stats::calcStats() {
	float wait_av = 0;
	float turnaround_av = 0;
	float response_av = 0;

	for (PCB rec : *vec) {
		wait_av += rec.finish_time - rec.arrival_time - rec.required_cpu_time;
		turnaround_av += rec.finish_time - rec.arrival_time;
		response_av += rec.start_time - rec.arrival_time;
	}
	av_wait_time = wait_av / vec -> size();
	av_turnaround_time = turnaround_av / vec -> size();
	av_response_time = response_av / vec -> size();
}

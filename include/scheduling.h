
#ifndef SCHEDULING_H
#define SCHEDULING_H

#include "domain.h"

void scheduleSurgeries(Hospital *hospital);
void displaySchedule(const Hospital *hospital);
void calculateUtilization(const Hospital *hospital);

void scheduleUsingIntervalPartitioning(Hospital *hospital);


#endif

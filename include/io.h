
#ifndef IO_H
#define IO_H

#include "domain.h"

void saveSurgeries(const Hospital *hospital);
void saveSurgeons(const Hospital *hospital);
void saveTheatres(const Hospital *hospital);
void saveEquipment(const Hospital *hospital);

void loadSurgeries(Hospital *hospital);
void loadSurgeons(Hospital *hospital);
void loadTheatres(Hospital *hospital);
void loadEquipment(Hospital *hospital);

#endif

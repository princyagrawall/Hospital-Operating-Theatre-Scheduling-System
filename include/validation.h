
#ifndef VALIDATION_H
#define VALIDATION_H

#include "domain.h"

int validateSurgery(const Surgery *surgery);
int validateSurgeon(const Surgeon *surgeon);
int validateTheatre(const OperatingTheatre *theatre);
int validateEquipment(const Equipment *equipment);

int isSurgeonAvailable(
    const Hospital *hospital,
    int surgeon_id,
    int start,
    int end
);

int isTheatreAvailable(
    const Hospital *hospital,
    int theatre_id,
    int start,
    int end
);

int isEquipmentAvailable(
    const Hospital *hospital,
    const Surgery *surgery,
    int start,
    int end
);

#endif

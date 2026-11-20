
#include <string.h>
#include "validation.h"

int validateSurgery(const Surgery *surgery) {
    return surgery->id > 0 &&
           strlen(surgery->name) > 0 &&
           surgery->duration > 0 &&
           surgery->priority >= 1 &&
           surgery->priority <= 5 &&
           surgery->start_time >= 0 &&
           surgery->start_time + surgery->duration <= 1440;
}

int validateSurgeon(const Surgeon *surgeon) {
    return surgeon->id > 0 &&
           strlen(surgeon->name) > 0 &&
           strlen(surgeon->specialization) > 0;
}

int validateTheatre(const OperatingTheatre *theatre) {
    return theatre->id > 0 &&
           strlen(theatre->name) > 0 &&
           theatre->capacity > 0;
}

int validateEquipment(const Equipment *equipment) {
    return equipment->id > 0 &&
           strlen(equipment->name) > 0 &&
           equipment->quantity >= 0 &&
           equipment->available >= 0 &&
           equipment->available <= equipment->quantity;
}

int isSurgeonAvailable(
    const Hospital *hospital,
    int surgeon_id,
    int start,
    int end
) {
    for (int i = 0; i < hospital->surgery_count; i++) {
        Surgery s = hospital->surgeries[i];

        if (s.scheduled && s.surgeon_id == surgeon_id &&
            start < s.end_time && end > s.start_time)
            return 0;
    }

    return 1;
}

int isTheatreAvailable(
    const Hospital *hospital,
    int theatre_id,
    int start,
    int end
) {
    for (int i = 0; i < hospital->surgery_count; i++) {
        Surgery s = hospital->surgeries[i];

        if (s.scheduled && s.theatre_id == theatre_id &&
            start < s.end_time && end > s.start_time)
            return 0;
    }

    return 1;
}

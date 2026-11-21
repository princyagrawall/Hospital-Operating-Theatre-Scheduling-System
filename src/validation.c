
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "validation.h"

/* Case-insensitive comparison */
static int stringsMatch(const char *a, const char *b) {
    if (a == NULL || b == NULL) return 0;

    while (*a && *b) {
        if (tolower((unsigned char)*a) !=
            tolower((unsigned char)*b)) {
            return 0;
        }

        a++;
        b++;
    }

    return *a == '\0' && *b == '\0';
}

/* ================= SURGERY VALIDATION ================= */

int validateSurgery(const Surgery *surgery) {
    if (surgery == NULL) return 0;

    if (surgery->id <= 0 ||
        strlen(surgery->name) == 0 ||
        surgery->duration <= 0 ||
        surgery->priority < 1 ||
        surgery->priority > 5 ||
        surgery->start_time < 0 ||
        surgery->start_time + surgery->duration > 1440 ||
        surgery->required_equipment_count < 0 ||
        surgery->required_equipment_count > MAX_REQUIRED_EQUIPMENT) {
        return 0;
    }

    for (int i = 0; i < surgery->required_equipment_count; i++) {
        if (strlen(surgery->required_equipment[i].equipment_type) == 0 ||
            surgery->required_equipment[i].quantity <= 0) {
            return 0;
        }
    }

    return 1;
}

/* ================= SURGEON VALIDATION ================= */

int validateSurgeon(const Surgeon *surgeon) {
    return surgeon != NULL &&
           surgeon->id > 0 &&
           strlen(surgeon->name) > 0 &&
           strlen(surgeon->specialization) > 0;
}

/* ================= THEATRE VALIDATION ================= */

int validateTheatre(const OperatingTheatre *theatre) {
    return theatre != NULL &&
           theatre->id > 0 &&
           strlen(theatre->name) > 0 &&
           theatre->capacity > 0;
}

/* ================= EQUIPMENT VALIDATION ================= */

int validateEquipment(const Equipment *equipment) {
    return equipment != NULL &&
           equipment->id > 0 &&
           strlen(equipment->name) > 0 &&
           equipment->quantity >= 0 &&
           equipment->available >= 0 &&
           equipment->available <= equipment->quantity;
}

/* ================= SURGEON AVAILABILITY ================= */

int isSurgeonAvailable(
    const Hospital *hospital,
    int surgeon_id,
    int start,
    int end
) {
    if (hospital == NULL || start >= end) return 0;

    for (int i = 0; i < hospital->surgery_count; i++) {
        const Surgery *s = &hospital->surgeries[i];

        if (s->scheduled &&
            s->surgeon_id == surgeon_id &&
            start < s->end_time &&
            end > s->start_time) {
            return 0;
        }
    }

    return 1;
}

/* ================= THEATRE AVAILABILITY ================= */

int isTheatreAvailable(
    const Hospital *hospital,
    int theatre_id,
    int start,
    int end
) {
    if (hospital == NULL || start >= end) return 0;

    for (int i = 0; i < hospital->surgery_count; i++) {
        const Surgery *s = &hospital->surgeries[i];

        if (s->scheduled &&
            s->theatre_id == theatre_id &&
            start < s->end_time &&
            end > s->start_time) {
            return 0;
        }
    }

    return 1;
}

/* ================= EQUIPMENT AVAILABILITY ================= */

int isEquipmentAvailable(
    const Hospital *hospital,
    const Surgery *surgery,
    int start,
    int end
) {
    if (hospital == NULL || surgery == NULL || start >= end)
        return 0;

    for (int r = 0; r < surgery->required_equipment_count; r++) {

        const RequiredEquipment *required =
            &surgery->required_equipment[r];

        int available_quantity = 0;

        /* Calculate total matching equipment stock */
        for (int e = 0; e < hospital->equipment_count; e++) {
            const Equipment *equipment = &hospital->equipment[e];

            if (stringsMatch(equipment->name,
                             required->equipment_type)) {
                available_quantity += equipment->available;
            }
        }

        /* Subtract equipment used by overlapping surgeries */
        for (int i = 0; i < hospital->surgery_count; i++) {
            const Surgery *existing = &hospital->surgeries[i];

            if (!existing->scheduled ||
                !(start < existing->end_time &&
                  end > existing->start_time)) {
                continue;
            }

            for (int k = 0;
                 k < existing->required_equipment_count; k++) {

                if (stringsMatch(
                    existing->required_equipment[k].equipment_type,
                    required->equipment_type)) {

                    available_quantity -=
                        existing->required_equipment[k].quantity;
                }
            }
        }

        if (available_quantity < required->quantity)
            return 0;
    }

    return 1;
}

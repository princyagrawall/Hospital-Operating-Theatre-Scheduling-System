
#include <stdio.h>
#include "io.h"

void saveSurgeries(const Hospital *hospital) {
    FILE *file = fopen("data/surgeries.csv", "w");

    if (!file) {
        printf("Unable to save surgeries.\n");
        return;
    }

    fprintf(file, "ID,Name,Duration,Priority,Start,End,Surgeon,Theatre,Scheduled\n");

    for (int i = 0; i < hospital->surgery_count; i++) {
        Surgery s = hospital->surgeries[i];

        fprintf(file, "%d,%s,%d,%d,%d,%d,%d,%d,%d\n",
                s.id, s.name, s.duration, s.priority,
                s.start_time, s.end_time,
                s.surgeon_id, s.theatre_id, s.scheduled);
    }

    fclose(file);
}

void saveSurgeons(const Hospital *hospital) {
    FILE *file = fopen("data/surgeons.csv", "w");

    if (!file) return;

    fprintf(file, "ID,Name,Specialization\n");

    for (int i = 0; i < hospital->surgeon_count; i++) {
        Surgeon s = hospital->surgeons[i];
        fprintf(file, "%d,%s,%s\n",
                s.id, s.name, s.specialization);
    }

    fclose(file);
}

void saveTheatres(const Hospital *hospital) {
    FILE *file = fopen("data/theatres.csv", "w");

    if (!file) return;

    fprintf(file, "ID,Name,Capacity\n");

    for (int i = 0; i < hospital->theatre_count; i++) {
        OperatingTheatre t = hospital->theatres[i];
        fprintf(file, "%d,%s,%d\n", t.id, t.name, t.capacity);
    }

    fclose(file);
}

void saveEquipment(const Hospital *hospital) {
    FILE *file = fopen("data/equipment.csv", "w");

    if (!file) return;

    fprintf(file, "ID,Name,Type,Quantity,Available\n");

    for (int i = 0; i < hospital->equipment_count; i++) {
        Equipment e = hospital->equipment[i];

        fprintf(file, "%d,%s,%s,%d,%d\n",
                e.id, e.name, e.type,
                e.quantity, e.available);
    }

    fclose(file);
}

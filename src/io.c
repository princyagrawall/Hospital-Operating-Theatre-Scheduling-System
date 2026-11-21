
#include <stdio.h>
#include <string.h>
#include "io.h"

void saveSurgeries(const Hospital *hospital) {
    FILE *file = fopen("data/surgeries.csv", "w");
    if (file == NULL) return;

    fprintf(file, "id,name,duration,priority,start_time,end_time,specialization,equipment_required,surgeon_id,theatre_id,scheduled\n");

    for (int i = 0; i < hospital->surgery_count; i++) {
        const Surgery *s = &hospital->surgeries[i];

        fprintf(file, "%d,%s,%d,%d,%d,%d,%s,%d,%d,%d,%d\n",
                s->id, s->name, s->duration, s->priority,
                s->start_time, s->end_time,
                s->required_specialization, s->equipment_required,
                s->surgeon_id, s->theatre_id, s->scheduled);
    }

    fclose(file);
}

void saveSurgeons(const Hospital *hospital) {
    FILE *file = fopen("data/surgeons.csv", "w");
    if (file == NULL) return;

    fprintf(file, "id,name,specialization,available\n");

    for (int i = 0; i < hospital->surgeon_count; i++) {
        const Surgeon *s = &hospital->surgeons[i];
        fprintf(file, "%d,%s,%s,%d\n",
                s->id, s->name, s->specialization, s->available);
    }

    fclose(file);
}

void saveTheatres(const Hospital *hospital) {
    FILE *file = fopen("data/theatres.csv", "w");
    if (file == NULL) return;

    fprintf(file, "id,name,capacity,available\n");

    for (int i = 0; i < hospital->theatre_count; i++) {
        const OperatingTheatre *t = &hospital->theatres[i];
        fprintf(file, "%d,%s,%d,%d\n",
                t->id, t->name, t->capacity, t->available);
    }

    fclose(file);
}

void saveEquipment(const Hospital *hospital) {
    FILE *file = fopen("data/equipment.csv", "w");
    if (file == NULL) return;

    fprintf(file, "id,name,type,quantity,available\n");

    for (int i = 0; i < hospital->equipment_count; i++) {
        const Equipment *e = &hospital->equipment[i];
        fprintf(file, "%d,%s,%s,%d,%d\n",
                e->id, e->name, e->type, e->quantity, e->available);
    }

    fclose(file);
}

void loadSurgeries(Hospital *hospital) {
    FILE *file = fopen("data/surgeries.csv", "r");
    if (file == NULL) return;

    char line[512];
    do {
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return;
    }

    } while (line[0] == '\n' || line[0] == '\r');

    while (fgets(line, sizeof(line), file)) {
        Surgery s = {0};

        int fields = sscanf(line,
            "%d,%49[^,],%d,%d,%d,%d,%49[^,],%d,%d,%d,%d",
            &s.id, s.name, &s.duration, &s.priority,
            &s.start_time, &s.end_time,
            s.required_specialization, &s.equipment_required,
            &s.surgeon_id, &s.theatre_id, &s.scheduled);

        if (fields == 11 && hospital->surgery_count < MAX_SURGERIES) {
            s.required_equipment_count = 0;
            addSurgery(hospital, s);
        }
    }

    fclose(file);
}

void loadSurgeons(Hospital *hospital) {
    FILE *file = fopen("data/surgeons.csv", "r");
    if (file == NULL) return;

    char line[256];
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        Surgeon s = {0};

        if (sscanf(line, "%d,%49[^,],%49[^,],%d",
                   &s.id, s.name, s.specialization, &s.available) == 4) {
            addSurgeon(hospital, s);
        }
    }

    fclose(file);
}

void loadTheatres(Hospital *hospital) {
    FILE *file = fopen("data/theatres.csv", "r");
    if (file == NULL) return;

    char line[256];
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        OperatingTheatre t = {0};

        if (sscanf(line, "%d,%49[^,],%d,%d",
                   &t.id, t.name, &t.capacity, &t.available) == 4) {
            addTheatre(hospital, t);
        }
    }

    fclose(file);
}

void loadEquipment(Hospital *hospital) {
    FILE *file = fopen("data/equipment.csv", "r");
    if (file == NULL) return;

    char line[256];
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        Equipment e = {0};

        if (sscanf(line, "%d,%49[^,],%49[^,],%d,%d",
                   &e.id, e.name, e.type,
                   &e.quantity, &e.available) == 5) {
            addEquipment(hospital, e);
        }
    }

    fclose(file);
}

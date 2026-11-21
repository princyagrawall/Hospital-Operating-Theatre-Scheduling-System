
#include <stdio.h>
#include <string.h>

#include "io.h"

/* ================= EQUIPMENT REQUIREMENT STORAGE ================= */

/*
 * Save individual surgery equipment requirements in:
 * data/surgery_equipment.csv
 *
 * Format:
 * surgery_id,equipment_name,quantity
 */

static void saveSurgeryEquipment(const Hospital *hospital) {
    FILE *file = fopen("data/surgery_equipment.csv", "w");

    if (file == NULL) {
        perror("Unable to save surgery equipment");
        return;
    }

    fprintf(file, "surgery_id,equipment_name,quantity\n");

    for (int i = 0; i < hospital->surgery_count; i++) {
        const Surgery *s = &hospital->surgeries[i];

        for (int j = 0; j < s->required_equipment_count; j++) {
            fprintf(file, "%d,%s,%d\n",
                    s->id,
                    s->required_equipment[j].equipment_type,
                    s->required_equipment[j].quantity);
        }
    }

    fclose(file);
}

/* Load equipment requirements after surgeries have been loaded. */
static void loadSurgeryEquipment(Hospital *hospital) {
    FILE *file = fopen("data/surgery_equipment.csv", "r");

    /* This file may not exist on the first run. */
    if (file == NULL) return;

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n' || line[0] == '\r')
            continue;

        if (strncmp(line, "surgery_id,", 11) == 0)
            continue;

        int surgery_id;
        int quantity;
        char equipment_name[50];

        if (sscanf(line, "%d,%49[^,],%d",
                   &surgery_id, equipment_name, &quantity) != 3)
            continue;

        if (quantity <= 0)
            continue;

        /* Find the surgery associated with this requirement. */
        for (int i = 0; i < hospital->surgery_count; i++) {
            Surgery *s = &hospital->surgeries[i];

            if (s->id != surgery_id)
                continue;

            if (s->required_equipment_count >= MAX_REQUIRED_EQUIPMENT)
                break;

            RequiredEquipment *required =
                &s->required_equipment[s->required_equipment_count];

            strcpy(required->equipment_type, equipment_name);
            required->quantity = quantity;

            s->required_equipment_count++;

            break;
        }
    }

    fclose(file);
}

/* ================= SAVE FUNCTIONS ================= */

void saveSurgeries(const Hospital *hospital) {
    if (hospital == NULL) return;

    FILE *file = fopen("data/surgeries.csv", "w");

    if (file == NULL) {
        perror("Unable to save surgeries");
        return;
    }

    fprintf(file,
        "id,name,duration,priority,start_time,end_time,specialization,"
        "equipment_required,surgeon_id,theatre_id,scheduled\n");

    for (int i = 0; i < hospital->surgery_count; i++) {
        const Surgery *s = &hospital->surgeries[i];

        fprintf(file, "%d,%s,%d,%d,%d,%d,%s,%d,%d,%d,%d\n",
                s->id, s->name, s->duration, s->priority,
                s->start_time, s->end_time,
                s->required_specialization, s->equipment_required,
                s->surgeon_id, s->theatre_id, s->scheduled);
    }

    fclose(file);

    /* Save the detailed equipment requirements separately. */
    saveSurgeryEquipment(hospital);
}

void saveSurgeons(const Hospital *hospital) {
    if (hospital == NULL) return;

    FILE *file = fopen("data/surgeons.csv", "w");

    if (file == NULL) {
        perror("Unable to save surgeons");
        return;
    }

    fprintf(file, "id,name,specialization,available\n");

    for (int i = 0; i < hospital->surgeon_count; i++) {
        const Surgeon *s = &hospital->surgeons[i];

        fprintf(file, "%d,%s,%s,%d\n",
                s->id, s->name, s->specialization, s->available);
    }

    fclose(file);
}

void saveTheatres(const Hospital *hospital) {
    if (hospital == NULL) return;

    FILE *file = fopen("data/theatres.csv", "w");

    if (file == NULL) {
        perror("Unable to save theatres");
        return;
    }

    fprintf(file, "id,name,capacity,available\n");

    for (int i = 0; i < hospital->theatre_count; i++) {
        const OperatingTheatre *t = &hospital->theatres[i];

        fprintf(file, "%d,%s,%d,%d\n",
                t->id, t->name, t->capacity, t->available);
    }

    fclose(file);
}

void saveEquipment(const Hospital *hospital) {
    if (hospital == NULL) return;

    FILE *file = fopen("data/equipment.csv", "w");

    if (file == NULL) {
        perror("Unable to save equipment");
        return;
    }

    fprintf(file, "id,name,type,quantity,available\n");

    for (int i = 0; i < hospital->equipment_count; i++) {
        const Equipment *e = &hospital->equipment[i];

        fprintf(file, "%d,%s,%s,%d,%d\n",
                e->id, e->name, e->type,
                e->quantity, e->available);
    }

    fclose(file);
}

/* ================= LOAD FUNCTIONS ================= */

void loadSurgeries(Hospital *hospital) {
    if (hospital == NULL) return;

    FILE *file = fopen("data/surgeries.csv", "r");

    if (file == NULL) {
        perror("Unable to load surgeries");
        return;
    }

    char line[512];

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n' || line[0] == '\r')
            continue;

        if (strncmp(line, "id,", 3) == 0 ||
            strncmp(line, "ID,", 3) == 0)
            continue;

        Surgery s = {0};

        int fields = sscanf(line,
            "%d,%49[^,],%d,%d,%d,%d,%49[^,],%d,%d,%d,%d",
            &s.id, s.name, &s.duration, &s.priority,
            &s.start_time, &s.end_time,
            s.required_specialization, &s.equipment_required,
            &s.surgeon_id, &s.theatre_id, &s.scheduled);

        if (fields == 11 &&
            hospital->surgery_count < MAX_SURGERIES) {
            addSurgery(hospital, s);
        }
    }

    fclose(file);

    /* Load requirements after all surgery records are available. */
    loadSurgeryEquipment(hospital);
}

void loadSurgeons(Hospital *hospital) {
    if (hospital == NULL) return;

    FILE *file = fopen("data/surgeons.csv", "r");

    if (file == NULL) {
        perror("Unable to load surgeons");
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n' || line[0] == '\r')
            continue;

        if (strncmp(line, "id,", 3) == 0)
            continue;

        Surgeon s = {0};

        if (sscanf(line, "%d,%49[^,],%49[^,],%d",
                   &s.id, s.name, s.specialization,
                   &s.available) == 4) {
            addSurgeon(hospital, s);
        }
    }

    fclose(file);
}

void loadTheatres(Hospital *hospital) {
    if (hospital == NULL) return;

    FILE *file = fopen("data/theatres.csv", "r");

    if (file == NULL) {
        perror("Unable to load theatres");
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n' || line[0] == '\r')
            continue;

        if (strncmp(line, "id,", 3) == 0)
            continue;

        OperatingTheatre t = {0};

        if (sscanf(line, "%d,%49[^,],%d,%d",
                   &t.id, t.name, &t.capacity,
                   &t.available) == 4) {
            addTheatre(hospital, t);
        }
    }

    fclose(file);
}

void loadEquipment(Hospital *hospital) {
    if (hospital == NULL) return;

    FILE *file = fopen("data/equipment.csv", "r");

    if (file == NULL) {
        perror("Unable to load equipment");
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n' || line[0] == '\r')
            continue;

        if (strncmp(line, "id,", 3) == 0)
            continue;

        Equipment e = {0};

        if (sscanf(line, "%d,%49[^,],%49[^,],%d,%d",
                   &e.id, e.name, e.type,
                   &e.quantity, &e.available) == 5) {
            addEquipment(hospital, e);
        }
    }

    fclose(file);
}

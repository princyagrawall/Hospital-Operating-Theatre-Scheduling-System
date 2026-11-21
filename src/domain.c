
#include <stdio.h>
#include <string.h>

#include "domain.h"

/* ================= INITIALIZATION ================= */

void initializeHospital(Hospital *hospital) {
    if (hospital == NULL) return;

    memset(hospital, 0, sizeof(Hospital));
}

/* ================= ADD SURGERY ================= */

int addSurgery(Hospital *hospital, Surgery surgery) {
    if (hospital == NULL ||
        hospital->surgery_count >= MAX_SURGERIES ||
        surgery.id <= 0) {
        return 0;
    }

    for (int i = 0; i < hospital->surgery_count; i++) {
        if (hospital->surgeries[i].id == surgery.id)
            return 0;
    }

    hospital->surgeries[hospital->surgery_count++] = surgery;
    return 1;
}

/* ================= ADD SURGEON ================= */

int addSurgeon(Hospital *hospital, Surgeon surgeon) {
    if (hospital == NULL ||
        hospital->surgeon_count >= MAX_SURGEONS ||
        surgeon.id <= 0) {
        return 0;
    }

    for (int i = 0; i < hospital->surgeon_count; i++) {
        if (hospital->surgeons[i].id == surgeon.id)
            return 0;
    }

    hospital->surgeons[hospital->surgeon_count++] = surgeon;
    return 1;
}

/* ================= ADD THEATRE ================= */

int addTheatre(Hospital *hospital, OperatingTheatre theatre) {
    if (hospital == NULL ||
        hospital->theatre_count >= MAX_THEATRES ||
        theatre.id <= 0) {
        return 0;
    }

    for (int i = 0; i < hospital->theatre_count; i++) {
        if (hospital->theatres[i].id == theatre.id)
            return 0;
    }

    hospital->theatres[hospital->theatre_count++] = theatre;
    return 1;
}

/* ================= ADD EQUIPMENT ================= */

int addEquipment(Hospital *hospital, Equipment equipment) {
    if (hospital == NULL ||
        hospital->equipment_count >= MAX_EQUIPMENT ||
        equipment.id <= 0) {
        return 0;
    }

    for (int i = 0; i < hospital->equipment_count; i++) {
        if (hospital->equipment[i].id == equipment.id)
            return 0;
    }

    hospital->equipment[hospital->equipment_count++] = equipment;
    return 1;
}

/* ================= DISPLAY SURGERIES ================= */

void displaySurgeries(const Hospital *hospital) {
    printf("\n========== SURGERY RECORDS ==========\n");

    if (hospital == NULL || hospital->surgery_count == 0) {
        printf("No surgeries found.\n");
        return;
    }

    for (int i = 0; i < hospital->surgery_count; i++) {
        const Surgery *s = &hospital->surgeries[i];

        printf("\nID: %d", s->id);
        printf("\nName: %s", s->name);
        printf("\nDuration: %d minutes", s->duration);
        printf("\nPriority: %d", s->priority);
        printf("\nRequired Specialization: %s",
               s->required_specialization);

        printf("\nEquipment Units Required: %d",
               s->equipment_required);

        printf("\nScheduled: %s\n",
               s->scheduled ? "Yes" : "No");
    }
}

/* ================= DISPLAY SURGEONS ================= */

void displaySurgeons(const Hospital *hospital) {
    printf("\n========== SURGEON RECORDS ==========\n");

    if (hospital == NULL || hospital->surgeon_count == 0) {
        printf("No surgeons found.\n");
        return;
    }

    for (int i = 0; i < hospital->surgeon_count; i++) {
        const Surgeon *s = &hospital->surgeons[i];

        printf("\nID: %d", s->id);
        printf("\nName: %s", s->name);
        printf("\nSpecialization: %s", s->specialization);
        printf("\nAvailable: %s\n",
               s->available ? "Yes" : "No");
    }
}

/* ================= DISPLAY THEATRES ================= */

void displayTheatres(const Hospital *hospital) {
    printf("\n========== THEATRE RECORDS ==========\n");

    if (hospital == NULL || hospital->theatre_count == 0) {
        printf("No theatres found.\n");
        return;
    }

    for (int i = 0; i < hospital->theatre_count; i++) {
        const OperatingTheatre *t = &hospital->theatres[i];

        printf("\nID: %d", t->id);
        printf("\nName: %s", t->name);
        printf("\nCapacity: %d", t->capacity);
        printf("\nAvailable: %s\n",
               t->available ? "Yes" : "No");
    }
}

/* ================= DISPLAY EQUIPMENT ================= */

void displayEquipment(const Hospital *hospital) {
    printf("\n========== EQUIPMENT RECORDS ==========\n");

    if (hospital == NULL || hospital->equipment_count == 0) {
        printf("No equipment found.\n");
        return;
    }

    for (int i = 0; i < hospital->equipment_count; i++) {
        const Equipment *e = &hospital->equipment[i];

        printf("\nID: %d", e->id);
        printf("\nName: %s", e->name);
        printf("\nType: %s", e->type);
        printf("\nTotal Quantity: %d", e->quantity);
        printf("\nAvailable Quantity: %d\n", e->available);
    }
}

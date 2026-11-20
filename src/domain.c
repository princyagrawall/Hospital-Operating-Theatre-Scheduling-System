
#include <stdio.h>
#include "domain.h"

void initializeHospital(Hospital *hospital) {
    hospital->surgery_count = 0;
    hospital->surgeon_count = 0;
    hospital->theatre_count = 0;
    hospital->equipment_count = 0;
}

int addSurgery(Hospital *hospital, Surgery surgery) {
    if (hospital->surgery_count >= MAX_SURGERIES)
        return 0;

    hospital->surgeries[hospital->surgery_count++] = surgery;
    return 1;
}

int addSurgeon(Hospital *hospital, Surgeon surgeon) {
    if (hospital->surgeon_count >= MAX_SURGEONS)
        return 0;

    hospital->surgeons[hospital->surgeon_count++] = surgeon;
    return 1;
}

int addTheatre(Hospital *hospital, OperatingTheatre theatre) {
    if (hospital->theatre_count >= MAX_THEATRES)
        return 0;

    hospital->theatres[hospital->theatre_count++] = theatre;
    return 1;
}

int addEquipment(Hospital *hospital, Equipment equipment) {
    if (hospital->equipment_count >= MAX_EQUIPMENT)
        return 0;

    hospital->equipment[hospital->equipment_count++] = equipment;
    return 1;
}

void displaySurgeries(const Hospital *hospital) {
    printf("\n--- SURGERY RECORDS ---\n");

    for (int i = 0; i < hospital->surgery_count; i++) {
        Surgery s = hospital->surgeries[i];

        printf("ID: %d | Name: %s | Duration: %d mins | Priority: %d\n",
               s.id, s.name, s.duration, s.priority);
    }
}

void displaySurgeons(const Hospital *hospital) {
    printf("\n--- SURGEON RECORDS ---\n");

    for (int i = 0; i < hospital->surgeon_count; i++) {
        Surgeon s = hospital->surgeons[i];

        printf("ID: %d | Name: %s | Specialization: %s\n",
               s.id, s.name, s.specialization);
    }
}

void displayTheatres(const Hospital *hospital) {
    printf("\n--- OPERATING THEATRES ---\n");

    for (int i = 0; i < hospital->theatre_count; i++) {
        OperatingTheatre t = hospital->theatres[i];

        printf("ID: %d | Name: %s | Equipment Capacity: %d\n",
               t.id, t.name, t.capacity);
    }
}

void displayEquipment(const Hospital *hospital) {
    printf("\n--- EQUIPMENT RECORDS ---\n");

    for (int i = 0; i < hospital->equipment_count; i++) {
        Equipment e = hospital->equipment[i];

        printf("ID: %d | Name: %s | Quantity: %d | Available: %d\n",
               e.id, e.name, e.quantity, e.available);
    }
}

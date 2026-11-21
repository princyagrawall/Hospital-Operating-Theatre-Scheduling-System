#include <stdio.h>
#include "domain.h"

void displaySurgeries(const Hospital *hospital) {

    printf("\n--- SURGERY RECORDS ---\n");

    for (int i = 0; i < hospital->surgery_count; i++) {

        Surgery s = hospital->surgeries[i];

        printf("\nID: %d", s.id);
        printf("\nName: %s", s.name);
        printf("\nDuration: %d minutes", s.duration);
        printf("\nPriority: %d", s.priority);
        printf("\nRequired Specialization: %s\n",
               s.required_specialization);
    }
}

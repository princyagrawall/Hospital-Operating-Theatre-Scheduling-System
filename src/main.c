#include <stdio.h>
#include <string.h>

#include "domain.h"
#include "validation.h"
#include "scheduling.h"
#include "io.h"

void addSurgeryMenu(Hospital *hospital) {

    Surgery s = {0};

    printf("\nEnter Surgery ID: ");
    scanf("%d", &s.id);

    printf("Enter Surgery Name: ");
    scanf(" %49[^\n]", s.name);

    printf("Enter Duration (minutes): ");
    scanf("%d", &s.duration);

    printf("Enter Priority (1-5): ");
    scanf("%d", &s.priority);

    printf("Enter Start Time (minutes from midnight): ");
    scanf("%d", &s.start_time);

    printf("Enter Required Specialization: ");
    scanf(" %49[^\n]", s.required_specialization);

    printf("Enter Required Equipment Capacity: ");
    scanf("%d", &s.equipment_required);

    if (!validateSurgery(&s) || s.equipment_required < 0) {
        printf("\nInvalid surgery details!\n");
        return;
    }

    if (addSurgery(hospital, s)) {
        printf("\nSurgery added successfully!\n");
        saveSurgeries(hospital);
    } else {
        printf("\nSurgery storage is full!\n");
    }
}

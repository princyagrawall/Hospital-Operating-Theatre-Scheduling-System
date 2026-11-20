
#include <stdio.h>
#include "domain.h"
#include "scheduling.h"
#include "validation.h"
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

void addSurgeonMenu(Hospital *hospital) {

    Surgeon s = {0};

    printf("\nEnter Surgeon ID: ");
    scanf("%d", &s.id);

    printf("Enter Surgeon Name: ");
    scanf(" %49[^\n]", s.name);

    printf("Enter Specialization: ");
    scanf(" %49[^\n]", s.specialization);

    s.available = 1;

    if (!validateSurgeon(&s)) {
        printf("\nInvalid surgeon details!\n");
        return;
    }

    if (addSurgeon(hospital, s)) {
        printf("\nSurgeon added successfully!\n");
        saveSurgeons(hospital);
    } else {
        printf("\nSurgeon storage is full!\n");
    }
}

void addTheatreMenu(Hospital *hospital) {

    OperatingTheatre t = {0};

    printf("\nEnter Theatre ID: ");
    scanf("%d", &t.id);

    printf("Enter Theatre Name: ");
    scanf(" %49[^\n]", t.name);

    printf("Enter Equipment Capacity: ");
    scanf("%d", &t.capacity);

    t.available = 1;

    if (!validateTheatre(&t)) {
        printf("\nInvalid theatre details!\n");
        return;
    }

    if (addTheatre(hospital, t)) {
        printf("\nTheatre added successfully!\n");
        saveTheatres(hospital);
    } else {
        printf("\nTheatre storage is full!\n");
    }
}

void addEquipmentMenu(Hospital *hospital) {

    Equipment e = {0};

    printf("\nEnter Equipment ID: ");
    scanf("%d", &e.id);

    printf("Enter Equipment Name: ");
    scanf(" %49[^\n]", e.name);

    printf("Enter Equipment Type: ");
    scanf(" %49[^\n]", e.type);

    printf("Enter Quantity: ");
    scanf("%d", &e.quantity);

    printf("Enter Available Quantity: ");
    scanf("%d", &e.available);

    if (!validateEquipment(&e)) {
        printf("\nInvalid equipment details!\n");
        return;
    }

    if (addEquipment(hospital, e)) {
        printf("\nEquipment added successfully!\n");
        saveEquipment(hospital);
    } else {
        printf("\nEquipment storage is full!\n");
    }
}

int main(void) {

    Hospital hospital;
    initializeHospital(&hospital);

    int choice;

    do {

        printf("\n\n");
        printf("============================================\n");
        printf(" HOSPITAL OPERATING THEATRE SCHEDULING SYSTEM\n");
        printf("============================================\n");

        printf("1. Add Surgery\n");
        printf("2. Add Surgeon\n");
        printf("3. Add Operating Theatre\n");
        printf("4. Add Medical Equipment\n");
        printf("5. View Surgeries\n");
        printf("6. View Surgeons\n");
        printf("7. View Operating Theatres\n");
        printf("8. View Equipment\n");
        printf("9. Generate Surgery Schedule\n");
        printf("10. View Final Schedule\n");
        printf("11. Calculate Theatre Utilization\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {

            case 1:
                addSurgeryMenu(&hospital);
                break;

            case 2:
                addSurgeonMenu(&hospital);
                break;

            case 3:
                addTheatreMenu(&hospital);
                break;

            case 4:
                addEquipmentMenu(&hospital);
                break;

            case 5:
                displaySurgeries(&hospital);
                break;

            case 6:
                displaySurgeons(&hospital);
                break;

            case 7:
                displayTheatres(&hospital);
                break;

            case 8:
                displayEquipment(&hospital);
                break;

            case 9:
                scheduleSurgeries(&hospital);
                saveSurgeries(&hospital);
                break;

            case 10:
                displaySchedule(&hospital);
                break;

            case 11:
                calculateUtilization(&hospital);
                break;

            case 0:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}


#include <stdio.h>

#include "domain.h"
#include "validation.h"
#include "scheduling.h"
#include "io.h"
#include "benchmark.h"

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

    printf("Enter Start Time (minutes from 00:00): ");
    scanf("%d", &s.start_time);

    printf("Enter Equipment Required: ");
    scanf("%d", &s.equipment_required);

    if (!validateSurgery(&s) || s.equipment_required < 0) {
        printf("Invalid surgery details.\n");
        return;
    }

    if (addSurgery(hospital, s)) {
        printf("Surgery added successfully.\n");
        saveSurgeries(hospital);
    } else {
        printf("Unable to add surgery.\n");
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

    if (validateSurgeon(&s) && addSurgeon(hospital, s)) {
        printf("Surgeon added successfully.\n");
        saveSurgeons(hospital);
    } else {
        printf("Invalid details or surgeon limit reached.\n");
    }
}

void addTheatreMenu(Hospital *hospital) {
    OperatingTheatre t = {0};

    printf("\nEnter Theatre ID: ");
    scanf("%d", &t.id);

    printf("Enter Theatre Name: ");
    scanf(" %49[^\n]", t.name);

    printf("Enter Theatre Capacity: ");
    scanf("%d", &t.capacity);

    t.available = 1;

    if (validateTheatre(&t) && addTheatre(hospital, t)) {
        printf("Theatre added successfully.\n");
        saveTheatres(hospital);
    } else {
        printf("Invalid details or theatre limit reached.\n");
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

    e.available = e.quantity;

    if (validateEquipment(&e) && addEquipment(hospital, e)) {
        printf("Equipment added successfully.\n");
        saveEquipment(hospital);
    } else {
        printf("Invalid details or equipment limit reached.\n");
    }
}

int main(void) {
    Hospital hospital;
    initializeHospital(&hospital);

    loadSurgeons(&hospital);
    loadTheatres(&hospital);
    loadEquipment(&hospital);
    loadSurgeries(&hospital);

    printf("\nHospital data loaded successfully.\n");

    int choice;

    do {
        printf("\n========== HOSPITAL OT SCHEDULING SYSTEM ==========\n");
        printf("1. Add Surgery\n");
        printf("2. Add Surgeon\n");
        printf("3. Add Operating Theatre\n");
        printf("4. Add Equipment\n");
        printf("5. Display Surgeries\n");
        printf("6. Display Surgeons\n");
        printf("7. Display Theatres\n");
        printf("8. Display Equipment\n");
        printf("9. Generate Priority-Based Schedule (Greedy)\n");
        printf("10. Display Schedule\n");
        printf("11. Calculate Theatre Utilization\n");
        printf("12. Interval Partitioning (Greedy)\n");
        printf("13. Backtracking Scheduling\n");
        printf("14. Branch and Bound Scheduling\n");
        printf("15. Benchmark Scheduling Algorithms\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
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

            case 12:
                scheduleUsingIntervalPartitioning(&hospital);
                saveSurgeries(&hospital);
                break;

            case 13:
                scheduleUsingBacktracking(&hospital);
                saveSurgeries(&hospital);
                break;

            case 14:
                scheduleUsingBranchAndBound(&hospital);
                saveSurgeries(&hospital);
                break;
            
            case 15:
                runBenchmark(&hospital);
                break;

            case 0:
                printf("Exiting Hospital OT Scheduling System.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}

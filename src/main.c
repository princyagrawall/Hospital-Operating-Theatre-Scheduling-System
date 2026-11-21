
#include <stdio.h>
#include <string.h>

#include "domain.h"
#include "validation.h"
#include "scheduling.h"
#include "io.h"
#include "benchmark.h"

/* ================= EQUIPMENT STOCK HELPER ================= */

int getEquipmentStock(const Hospital *hospital, const char *name) {
    int total = 0;

    for (int i = 0; i < hospital->equipment_count; i++) {
        if (strcmp(hospital->equipment[i].name, name) == 0) {
            total += hospital->equipment[i].available;
        }
    }

    return total;
}

/* ================= ADD SURGERY ================= */

void addSurgeryMenu(Hospital *hospital) {
    Surgery s = {0};

    printf("\nEnter Surgery ID: ");
    if (scanf("%d", &s.id) != 1) return;

    printf("Enter Surgery Name: ");
    if (scanf(" %49[^\n]", s.name) != 1) return;

    printf("Enter Required Specialization: ");
    if (scanf(" %49[^\n]", s.required_specialization) != 1) return;

    printf("Enter Duration (minutes): ");
    if (scanf("%d", &s.duration) != 1) return;

    printf("Enter Priority (1-5): ");
    if (scanf("%d", &s.priority) != 1) return;

    printf("Enter Start Time (minutes from 00:00): ");
    if (scanf("%d", &s.start_time) != 1) return;

    s.end_time = s.start_time + s.duration;

    printf("\nHow many different equipment types are required? (0-%d): ",
           MAX_REQUIRED_EQUIPMENT);

    if (scanf("%d", &s.required_equipment_count) != 1) return;

    if (s.required_equipment_count < 0 ||
        s.required_equipment_count > MAX_REQUIRED_EQUIPMENT) {
        printf("Invalid equipment count.\n");
        return;
    }

    s.equipment_required = 0;

    for (int i = 0; i < s.required_equipment_count; i++) {
        RequiredEquipment *required = &s.required_equipment[i];

        printf("\nEquipment %d name: ", i + 1);
        if (scanf(" %49[^\n]", required->equipment_type) != 1)
            return;

        printf("Quantity required: ");
        if (scanf("%d", &required->quantity) != 1)
            return;

        if (required->quantity <= 0) {
            printf("Quantity must be positive.\n");
            return;
        }

        /* Check for duplicate equipment entries. */
        for (int j = 0; j < i; j++) {
            if (strcmp(s.required_equipment[j].equipment_type,
                       required->equipment_type) == 0) {
                printf("Equipment entered twice. Please restart.\n");
                return;
            }
        }

        /* Check equipment stock. */
        int stock = getEquipmentStock(
            hospital, required->equipment_type
        );

        if (stock < required->quantity) {
            printf("Equipment not found or insufficient stock.\n");
            printf("Available quantity: %d\n", stock);
            return;
        }

        s.equipment_required += required->quantity;
    }

    if (!validateSurgery(&s)) {
        printf("Invalid surgery details.\n");
        return;
    }

    if (addSurgery(hospital, s)) {
        printf("\nSurgery added successfully.\n");
        saveSurgeries(hospital);
    } else {
        printf("Unable to add surgery. Check duplicate ID or surgery limit.\n");
    }
}

/* ================= ADD SURGEON ================= */

void addSurgeonMenu(Hospital *hospital) {
    Surgeon s = {0};

    printf("\nEnter Surgeon ID: ");
    if (scanf("%d", &s.id) != 1) return;

    printf("Enter Surgeon Name: ");
    if (scanf(" %49[^\n]", s.name) != 1) return;

    printf("Enter Specialization: ");
    if (scanf(" %49[^\n]", s.specialization) != 1) return;

    s.available = 1;

    if (validateSurgeon(&s) && addSurgeon(hospital, s)) {
        printf("Surgeon added successfully.\n");
        saveSurgeons(hospital);
    } else {
        printf("Invalid details or surgeon limit reached.\n");
    }
}

/* ================= ADD THEATRE ================= */

void addTheatreMenu(Hospital *hospital) {
    OperatingTheatre t = {0};

    printf("\nEnter Theatre ID: ");
    if (scanf("%d", &t.id) != 1) return;

    printf("Enter Theatre Name: ");
    if (scanf(" %49[^\n]", t.name) != 1) return;

    printf("Enter Theatre Capacity: ");
    if (scanf("%d", &t.capacity) != 1) return;

    t.available = 1;

    if (validateTheatre(&t) && addTheatre(hospital, t)) {
        printf("Theatre added successfully.\n");
        saveTheatres(hospital);
    } else {
        printf("Invalid details or theatre limit reached.\n");
    }
}

/* ================= ADD EQUIPMENT ================= */

void addEquipmentMenu(Hospital *hospital) {
    Equipment e = {0};

    printf("\nEnter Equipment ID: ");
    if (scanf("%d", &e.id) != 1) return;

    printf("Enter Equipment Name: ");
    if (scanf(" %49[^\n]", e.name) != 1) return;

    printf("Enter Equipment Type: ");
    if (scanf(" %49[^\n]", e.type) != 1) return;

    printf("Enter Quantity: ");
    if (scanf("%d", &e.quantity) != 1) return;

    e.available = e.quantity;

    if (validateEquipment(&e) && addEquipment(hospital, e)) {
        printf("Equipment added successfully.\n");
        saveEquipment(hospital);
    } else {
        printf("Invalid details or equipment limit reached.\n");
    }
}

/* ================= MAIN MENU ================= */

int main(void) {
    Hospital hospital;
    initializeHospital(&hospital);

    loadSurgeons(&hospital);
    loadTheatres(&hospital);
    loadEquipment(&hospital);
    loadSurgeries(&hospital);

    printf("\n");
    printf("  +====================================================================+\n");
    printf("  |                                                                    |\n");
    printf("  |               PRECISION IN EVERY PROCEDURE,                        |\n");
    printf("  |                  CARE IN EVERY DECISION                            |\n");
    printf("  |                                                                    |\n");
    printf("  +====================================================================+\n");

    printf("\n\n");

   printf("\n");
printf("+========================================================================+\n");
printf("|                                                                        |\n");
printf("|     H   H   OOOOO   SSSSS   PPPPP   IIIII   TTTTT   AAAAA   L          |\n");
printf("|     H   H  O     O  S       P    P    I       T    A     A  L          |\n");
printf("|     HHHHH  O     O  SSSSS   PPPPP     I       T    AAAAAAA  L          |\n");
printf("|     H   H  O     O      S   P         I       T    A     A  L          |\n");
printf("|     H   H   OOOOO   SSSSS   P       IIIII     T    A     A  LLLLL      |\n");
printf("|                                                                        |\n");
printf("|                         OPERATING THEATRE (OT)                         |\n");
printf("|                       ------------------------                         |\n");
printf("|                          SCHEDULING SYSTEM                             |\n");
printf("|                                                                        |\n");
printf("|                 Optimizing Time. Maximizing Care.                      |\n");
printf("|                                                                        |\n");
printf("+========================================================================+\n");
printf("\n");
printf("       SURGICAL PRECISION  |  SMART SCHEDULING  |  OPTIMAL CARE\n\n");

    int choice;

    do {
        
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


#include <stdio.h>
#include <stdlib.h>

#include "scheduling.h"
#include "validation.h"

static void sortSurgeriesByPriority(Hospital *hospital) {
    for (int i = 0; i < hospital->surgery_count - 1; i++) {
        for (int j = 0; j < hospital->surgery_count - i - 1; j++) {

            if (hospital->surgeries[j].priority <
                hospital->surgeries[j + 1].priority) {

                Surgery temp = hospital->surgeries[j];
                hospital->surgeries[j] = hospital->surgeries[j + 1];
                hospital->surgeries[j + 1] = temp;
            }
        }
    }
}

void scheduleSurgeries(Hospital *hospital) {
    if (hospital == NULL) return;

    printf("\n--- PRIORITY-BASED SURGERY SCHEDULING ---\n");

    sortSurgeriesByPriority(hospital);

    int scheduled_count = 0;

    for (int i = 0; i < hospital->surgery_count; i++) {
        Surgery *s = &hospital->surgeries[i];

        if (s->scheduled) continue;

        int start = s->start_time;
        int end = start + s->duration;
        int assigned = 0;

        for (int j = 0; j < hospital->surgeon_count && !assigned; j++) {
            Surgeon *surgeon = &hospital->surgeons[j];

            if (!surgeon->available) continue;

            if (!isSurgeonAvailable(hospital, surgeon->id, start, end))
                continue;

            for (int k = 0; k < hospital->theatre_count; k++) {
                OperatingTheatre *theatre = &hospital->theatres[k];

                if (!theatre->available) continue;

                if (theatre->capacity < s->equipment_required)
                    continue;

                if (!isTheatreAvailable(hospital, theatre->id, start, end))
                    continue;

                s->surgeon_id = surgeon->id;
                s->theatre_id = theatre->id;
                s->end_time = end;
                s->scheduled = 1;

                printf("\nSurgery Scheduled Successfully!");
                printf("\nSurgery: %s", s->name);
                printf("\nPriority: %d", s->priority);
                printf("\nSurgeon: %s", surgeon->name);
                printf("\nTheatre: %s", theatre->name);
                printf("\nTime: %d - %d\n", start, end);

                assigned = 1;
                scheduled_count++;
                break;
            }
        }

        if (!assigned) {
            printf("\nCould not schedule: %s\n", s->name);
        }
    }

    printf("\nTotal Surgeries Scheduled: %d\n", scheduled_count);
}

void displaySchedule(const Hospital *hospital) {
    if (hospital == NULL) return;

    printf("\n========== FINAL SURGERY SCHEDULE ==========\n");

    int found = 0;

    for (int i = 0; i < hospital->surgery_count; i++) {
        const Surgery *s = &hospital->surgeries[i];

        if (!s->scheduled) continue;

        printf("\nSurgery ID: %d", s->id);
        printf("\nName: %s", s->name);
        printf("\nPriority: %d", s->priority);
        printf("\nSurgeon ID: %d", s->surgeon_id);
        printf("\nTheatre ID: %d", s->theatre_id);
        printf("\nStart Time: %d", s->start_time);
        printf("\nEnd Time: %d\n", s->end_time);

        found = 1;
    }

    if (!found) {
        printf("No surgeries scheduled yet.\n");
    }
}

void calculateUtilization(const Hospital *hospital) {
    if (hospital == NULL) return;

    printf("\n========== THEATRE UTILIZATION ==========\n");

    for (int i = 0; i < hospital->theatre_count; i++) {
        const OperatingTheatre *theatre = &hospital->theatres[i];

        int total_minutes = 0;

        for (int j = 0; j < hospital->surgery_count; j++) {
            const Surgery *s = &hospital->surgeries[j];

            if (s->scheduled && s->theatre_id == theatre->id) {
                total_minutes += s->duration;
            }
        }

        float utilization = (total_minutes / 480.0f) * 100.0f;

        if (utilization > 100.0f)
            utilization = 100.0f;

        printf("\nTheatre: %s", theatre->name);
        printf("\nOccupied Minutes: %d", total_minutes);
        printf("\nUtilization: %.2f%%\n", utilization);
    }
}

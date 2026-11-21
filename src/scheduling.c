
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "domain.h"
#include "scheduling.h"
#include "validation.h"

/* Normalize specialization names for comparison */
static void normalizeSpecialization(const char *input,
                                    char *output,
                                    size_t size) {
    size_t j = 0;

    if (input == NULL || size == 0)
        return;

    for (size_t i = 0; input[i] != '\0' && j < size - 1; i++) {
        if (!isspace((unsigned char)input[i])) {
            output[j++] = (char)tolower((unsigned char)input[i]);
        }
    }

    output[j] = '\0';

    if (strcmp(output, "cardiologist") == 0)
        strcpy(output, "cardiology");
    else if (strcmp(output, "neurologist") == 0)
        strcpy(output, "neurology");
    else if (strcmp(output, "orthopedist") == 0)
        strcpy(output, "orthopedics");
}

/* Check whether surgeon specialization matches surgery requirement */
static int specializationsMatch(const char *surgeonSpec,
                                const char *surgerySpec) {
    char surgeon[50];
    char surgery[50];

    normalizeSpecialization(surgeonSpec, surgeon, sizeof(surgeon));
    normalizeSpecialization(surgerySpec, surgery, sizeof(surgery));

    if (surgeon[0] == '\0' || surgery[0] == '\0')
        return 0;

    return strcmp(surgeon, surgery) == 0;
}

/* Priority-Based Greedy Scheduling */
void scheduleSurgeries(Hospital *hospital) {
    if (hospital == NULL)
        return;

    printf("\n--- PRIORITY-BASED SURGERY SCHEDULING ---\n");

    /* Sort surgeries by descending priority */
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

    int count = 0;

    for (int i = 0; i < hospital->surgery_count; i++) {
        Surgery *s = &hospital->surgeries[i];

        if (s->scheduled)
            continue;

        int start = s->start_time;
        int end = start + s->duration;
        int assigned = 0;

        /* Find a suitable surgeon */
        for (int j = 0;
             j < hospital->surgeon_count && !assigned;
             j++) {

            Surgeon *surgeon = &hospital->surgeons[j];

            if (!surgeon->available)
                continue;

            if (!specializationsMatch(
                    surgeon->specialization,
                    s->required_specialization))
                continue;

            if (!isSurgeonAvailable(
                    hospital, surgeon->id, start, end))
                continue;

            /* Find a suitable operating theatre */
            for (int k = 0; k < hospital->theatre_count; k++) {
                OperatingTheatre *theatre = &hospital->theatres[k];

                if (!theatre->available ||
                    theatre->capacity < s->equipment_required)
                    continue;

                if (!isTheatreAvailable(
                        hospital, theatre->id, start, end))
                    continue;

                s->surgeon_id = surgeon->id;
                s->theatre_id = theatre->id;
                s->end_time = end;
                s->scheduled = 1;

                printf("\nScheduled: %s", s->name);
                printf("\nSurgeon: %s", surgeon->name);
                printf("\nTheatre: %s", theatre->name);
                printf("\nTime: %d - %d\n", start, end);

                assigned = 1;
                count++;
                break;
            }
        }

        if (!assigned) {
            printf("\nCould not schedule: %s\n", s->name);
        }
    }

    printf("\nTotal surgeries scheduled: %d\n", count);
}

/* Display Final Surgery Schedule */
void displaySchedule(const Hospital *hospital) {
    if (hospital == NULL)
        return;

    printf("\n========== FINAL SURGERY SCHEDULE ==========\n");

    int found = 0;

    for (int i = 0; i < hospital->surgery_count; i++) {
        const Surgery *s = &hospital->surgeries[i];

        if (!s->scheduled)
            continue;

        printf("\nID: %d", s->id);
        printf("\nSurgery: %s", s->name);
        printf("\nPriority: %d", s->priority);
        printf("\nSurgeon ID: %d", s->surgeon_id);
        printf("\nTheatre ID: %d", s->theatre_id);
        printf("\nTime: %d - %d\n", s->start_time, s->end_time);

        found = 1;
    }

    if (!found)
        printf("No surgeries scheduled yet.\n");
}

/* Calculate Operating Theatre Utilization */
void calculateUtilization(const Hospital *hospital) {
    if (hospital == NULL)
        return;

    printf("\n========== THEATRE UTILIZATION ==========\n");

    for (int i = 0; i < hospital->theatre_count; i++) {
        const OperatingTheatre *theatre = &hospital->theatres[i];

        int occupied = 0;

        for (int j = 0; j < hospital->surgery_count; j++) {
            const Surgery *s = &hospital->surgeries[j];

            if (s->scheduled && s->theatre_id == theatre->id)
                occupied += s->duration;
        }

        float utilization = (occupied / 480.0f) * 100.0f;

        if (utilization > 100.0f)
            utilization = 100.0f;

        printf("\nTheatre: %s", theatre->name);
        printf("\nOccupied Minutes: %d", occupied);
        printf("\nUtilization: %.2f%%\n", utilization);
    }
}

/* Interval Partitioning Algorithm */
void scheduleUsingIntervalPartitioning(Hospital *hospital) {
    if (hospital == NULL || hospital->theatre_count == 0) {
        printf("No operating theatres available.\n");
        return;
    }

    printf("\n===== INTERVAL PARTITIONING SCHEDULER =====\n");

    /* Sort surgeries by ascending start time */
    for (int i = 0; i < hospital->surgery_count - 1; i++) {
        for (int j = 0; j < hospital->surgery_count - i - 1; j++) {

            if (hospital->surgeries[j].start_time >
                hospital->surgeries[j + 1].start_time) {

                Surgery temp = hospital->surgeries[j];
                hospital->surgeries[j] = hospital->surgeries[j + 1];
                hospital->surgeries[j + 1] = temp;
            }
        }
    }

    int theatre_end[MAX_THEATRES] = {0};
    int count = 0;

    for (int i = 0; i < hospital->surgery_count; i++) {
        Surgery *s = &hospital->surgeries[i];

        if (s->scheduled)
            continue;

        int start = s->start_time;
        int end = start + s->duration;
        int assigned = 0;

        for (int j = 0; j < hospital->theatre_count; j++) {
            OperatingTheatre *t = &hospital->theatres[j];

            if (!t->available ||
                t->capacity < s->equipment_required)
                continue;

            if (theatre_end[j] <= start &&
                isTheatreAvailable(hospital, t->id, start, end)) {

                s->theatre_id = t->id;
                s->end_time = end;
                theatre_end[j] = end;
                s->scheduled = 1;

                printf("\nSurgery: %s", s->name);
                printf("\nTheatre: %s", t->name);
                printf("\nTime: %d - %d\n", start, end);

                assigned = 1;
                count++;
                break;
            }
        }

        if (!assigned) {
            printf("\nCould not allocate: %s\n", s->name);
        }
    }

    printf("\nTotal surgeries allocated: %d\n", count);
}


#include <stdio.h>
#include "scheduling.h"
#include "validation.h"

void scheduleSurgeries(Hospital *hospital) {

    printf("\n--- GENERATING SURGERY SCHEDULE ---\n");

    int scheduled_count = 0;

    for (int i = 0; i < hospital->surgery_count; i++) {

        Surgery *s = &hospital->surgeries[i];

        if (s->scheduled)
            continue;

        int start = s->start_time;
        int end = start + s->duration;
        int assigned = 0;

        for (int j = 0; j < hospital->surgeon_count && !assigned; j++) {

            Surgeon surgeon = hospital->surgeons[j];

            if (!surgeon.available)
                continue;

            if (!isSurgeonAvailable(hospital, surgeon.id, start, end))
                continue;

            for (int k = 0; k < hospital->theatre_count; k++) {

                OperatingTheatre theatre = hospital->theatres[k];

                if (!theatre.available)
                    continue;

                if (theatre.capacity < s->equipment_required)
                    continue;

                if (!isTheatreAvailable(hospital, theatre.id, start, end))
                    continue;

                s->surgeon_id = surgeon.id;
                s->theatre_id = theatre.id;
                s->end_time = end;
                s->scheduled = 1;

                printf("\nSurgery: %s\n", s->name);
                printf("Surgeon: %s\n", surgeon.name);
                printf("Theatre: %s\n", theatre.name);
                printf("Start: %d minutes\n", start);
                printf("End: %d minutes\n", end);

                assigned = 1;
                scheduled_count++;
                break;
            }
        }

        if (!assigned) {
            printf("\nCould not schedule surgery: %s\n", s->name);
        }
    }

    printf("\nTotal newly scheduled surgeries: %d\n", scheduled_count);
}

void displaySchedule(const Hospital *hospital) {

    printf("\n========== HOSPITAL SURGERY SCHEDULE ==========\n");

    int found = 0;

    for (int i = 0; i < hospital->surgery_count; i++) {

        Surgery s = hospital->surgeries[i];

        if (s.scheduled) {

            printf("\nSurgery ID: %d", s.id);
            printf("\nSurgery: %s", s.name);
            printf("\nSurgeon ID: %d", s.surgeon_id);
            printf("\nTheatre ID: %d", s.theatre_id);
            printf("\nStart Time: %d", s.start_time);
            printf("\nEnd Time: %d\n", s.end_time);

            found = 1;
        }
    }

    if (!found)
        printf("\nNo surgeries scheduled yet.\n");
}

void calculateUtilization(const Hospital *hospital) {

    printf("\n========== THEATRE UTILIZATION ==========\n");

    for (int i = 0; i < hospital->theatre_count; i++) {

        int total_minutes = 0;
        int available_minutes = 480;

        for (int j = 0; j < hospital->surgery_count; j++) {

            Surgery s = hospital->surgeries[j];

            if (s.scheduled &&
                s.theatre_id == hospital->theatres[i].id) {

                total_minutes += s.duration;
            }
        }

        float utilization =
            (float)total_minutes / available_minutes * 100.0f;

        if (utilization > 100.0f)
            utilization = 100.0f;

        printf("\nTheatre: %s",
               hospital->theatres[i].name);

        printf("\nUsed: %d minutes", total_minutes);

        printf("\nUtilization: %.2f%%\n", utilization);
    }
}

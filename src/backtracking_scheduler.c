
#include <stdio.h>
#include "domain.h"
#include "scheduling.h"

static int assignedTheatre[MAX_SURGERIES];

static int hasConflict(const Hospital *hospital,
                       int surgeryIndex,
                       int theatreId) {
    const Surgery *current = &hospital->surgeries[surgeryIndex];
    int start = current->start_time;
    int end = start + current->duration;

    for (int i = 0; i < hospital->surgery_count; i++) {
        if (i == surgeryIndex) continue;

        const Surgery *other = &hospital->surgeries[i];

        int otherTheatre = other->scheduled
            ? other->theatre_id
            : -1;

        if (!other->scheduled && assignedTheatre[i] > 0)
            otherTheatre = assignedTheatre[i];

        if (otherTheatre != theatreId) continue;

        int otherStart = other->start_time;
        int otherEnd = other->scheduled
            ? other->end_time
            : otherStart + other->duration;

        if (start < otherEnd && otherStart < end)
            return 1;
    }

    return 0;
}

static int backtrack(Hospital *hospital, int index) {
    if (index == hospital->surgery_count)
        return 1;

    Surgery *s = &hospital->surgeries[index];

    if (s->scheduled)
        return backtrack(hospital, index + 1);

    for (int i = 0; i < hospital->theatre_count; i++) {
        OperatingTheatre *t = &hospital->theatres[i];

        if (!t->available)
            continue;

        if (t->capacity < s->equipment_required)
            continue;

        if (hasConflict(hospital, index, t->id))
            continue;

        assignedTheatre[index] = t->id;

        if (backtrack(hospital, index + 1))
            return 1;

        assignedTheatre[index] = 0;
    }

    return 0;
}

void scheduleUsingBacktracking(Hospital *hospital) {
    if (hospital == NULL) return;

    if (hospital->theatre_count == 0) {
        printf("No operating theatres available.\n");
        return;
    }

    for (int i = 0; i < MAX_SURGERIES; i++)
        assignedTheatre[i] = 0;

    printf("\n===== BACKTRACKING SCHEDULER =====\n");

    if (backtrack(hospital, 0)) {
        int count = 0;

        for (int i = 0; i < hospital->surgery_count; i++) {
            Surgery *s = &hospital->surgeries[i];

            if (!s->scheduled && assignedTheatre[i] > 0) {
                s->theatre_id = assignedTheatre[i];
                s->end_time = s->start_time + s->duration;
                s->scheduled = 1;
                count++;

                printf("\nSurgery: %s", s->name);
                printf("\nTheatre ID: %d", s->theatre_id);
                printf("\nTime: %d - %d\n",
                       s->start_time, s->end_time);
            }
        }

        printf("\nSuccessfully allocated %d surgeries.\n", count);
    } else {
        printf("No valid allocation found with the available theatres.\n");
    }
}



#include <stdio.h>
#include "domain.h"
#include "scheduling.h"

static int currentAssignment[MAX_SURGERIES];
static int bestAssignment[MAX_SURGERIES];
static int remainingPriority[MAX_SURGERIES + 1];
static int bestScore;
static Hospital *currentHospital;

/* Check whether a theatre has a time conflict */
static int hasTheatreConflict(int index, int theatreId) {
    Surgery *current = &currentHospital->surgeries[index];

    int start = current->start_time;
    int end = start + current->duration;

    for (int i = 0; i < currentHospital->surgery_count; i++) {
        if (i == index)
            continue;

        Surgery *other = &currentHospital->surgeries[i];

        int assignedId = 0;
        int otherStart = other->start_time;
        int otherEnd = otherStart + other->duration;

        if (other->scheduled) {
            assignedId = other->theatre_id;
            if (other->end_time > otherStart)
                otherEnd = other->end_time;
        } else {
            assignedId = currentAssignment[i];
        }

        if (assignedId == theatreId &&
            start < otherEnd && otherStart < end) {
            return 1;
        }
    }

    return 0;
}

/* Branch and Bound search */
static void branchAndBound(int index, int score) {
    if (score + remainingPriority[index] <= bestScore)
        return;

    if (index == currentHospital->surgery_count) {
        bestScore = score;

        for (int i = 0; i < currentHospital->surgery_count; i++)
            bestAssignment[i] = currentAssignment[i];

        return;
    }

    Surgery *s = &currentHospital->surgeries[index];

    /* Already scheduled surgeries remain unchanged */
    if (s->scheduled) {
        currentAssignment[index] = s->theatre_id;
        branchAndBound(index + 1, score);
        return;
    }

    /* Try assigning this surgery to each suitable theatre */
    for (int i = 0; i < currentHospital->theatre_count; i++) {
        OperatingTheatre *t = &currentHospital->theatres[i];

        if (!t->available)
            continue;

        if (t->capacity < s->equipment_required)
            continue;

        if (hasTheatreConflict(index, t->id))
            continue;

        currentAssignment[index] = t->id;

        branchAndBound(index + 1, score + s->priority);

        /* Undo the choice */
        currentAssignment[index] = 0;
    }

    /* Also consider leaving this surgery unscheduled */
    currentAssignment[index] = 0;
    branchAndBound(index + 1, score);
}

void scheduleUsingBranchAndBound(Hospital *hospital) {
    if (hospital == NULL || hospital->theatre_count == 0) {
        printf("No hospital or theatre data available.\n");
        return;
    }

    if (hospital->surgery_count > MAX_SURGERIES ||
        hospital->theatre_count > MAX_THEATRES) {
        printf("Scheduling limits exceeded.\n");
        return;
    }

    currentHospital = hospital;
    bestScore = -1;

    for (int i = 0; i < MAX_SURGERIES; i++) {
        currentAssignment[i] = 0;
        bestAssignment[i] = 0;
    }

    /* Calculate an upper bound on remaining priority */
    remainingPriority[hospital->surgery_count] = 0;

    for (int i = hospital->surgery_count - 1; i >= 0; i--) {
        int priority = hospital->surgeries[i].scheduled
            ? 0 : hospital->surgeries[i].priority;

        remainingPriority[i] = remainingPriority[i + 1] + priority;
    }

    printf("\n===== BRANCH AND BOUND SCHEDULER =====\n");

    branchAndBound(0, 0);

    int count = 0;

    for (int i = 0; i < hospital->surgery_count; i++) {
        Surgery *s = &hospital->surgeries[i];

        if (!s->scheduled && bestAssignment[i] > 0) {
            s->theatre_id = bestAssignment[i];
            s->end_time = s->start_time + s->duration;
            s->scheduled = 1;
            count++;

            printf("\nSurgery: %s", s->name);
            printf("\nTheatre ID: %d", s->theatre_id);
            printf("\nPriority: %d", s->priority);
            printf("\nTime: %d - %d\n",
                   s->start_time, s->end_time);
        }
    }

    printf("\nNew surgeries scheduled: %d\n", count);
    printf("Total priority score: %d\n", bestScore);
}

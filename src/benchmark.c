
#include <stdio.h>
#include <time.h>

#include "domain.h"
#include "scheduling.h"

#define BILLION 1000000000.0

static double getTimeInNanoseconds(struct timespec start,
                                   struct timespec end)
{
    return ((end.tv_sec - start.tv_sec) * BILLION)
         + (end.tv_nsec - start.tv_nsec);
}

void runBenchmark(Hospital *hospital)
{
    struct timespec start, end;
    double elapsed;

    printf("\n===== Hospital Scheduling Benchmark =====\n");

    clock_gettime(CLOCK_MONOTONIC, &start);
    scheduleSurgeries(hospital);
    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed = getTimeInNanoseconds(start, end);

    printf("Greedy Priority Scheduling: %.0f ns\n", elapsed);

    clock_gettime(CLOCK_MONOTONIC, &start);
    scheduleUsingIntervalPartitioning(hospital);
    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed = getTimeInNanoseconds(start, end);

    printf("Interval Partitioning: %.0f ns\n", elapsed);

    clock_gettime(CLOCK_MONOTONIC, &start);
    scheduleUsingBacktracking(hospital);
    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed = getTimeInNanoseconds(start, end);

    printf("Backtracking: %.0f ns\n", elapsed);

    clock_gettime(CLOCK_MONOTONIC, &start);
    scheduleUsingBranchAndBound(hospital);
    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed = getTimeInNanoseconds(start, end);

    printf("Branch and Bound: %.0f ns\n", elapsed);

    printf("=========================================\n");
}


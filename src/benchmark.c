
#include <stdio.h>
#include <time.h>

#include "domain.h"
#include "scheduling.h"
#include "benchmark.h"

#define BENCHMARK_FILE "benchmarks/benchmark_results.csv"

typedef void (*SchedulingFunction)(Hospital *);

typedef struct {
    const char *name;
    SchedulingFunction function;
} BenchmarkAlgorithm;

void runBenchmark(const Hospital *hospital)
{
    BenchmarkAlgorithm algorithms[] = {
        {"Greedy Priority Scheduling", scheduleSurgeries},
        {"Interval Partitioning", scheduleUsingIntervalPartitioning},
        {"Backtracking", scheduleUsingBacktracking},
        {"Branch and Bound", scheduleUsingBranchAndBound}
    };

    int algorithm_count =
        sizeof(algorithms) / sizeof(algorithms[0]);

    FILE *file = fopen(BENCHMARK_FILE, "a+");

    if (file == NULL) {
        printf("Error: Could not open benchmark CSV file.\n");
        return;
    }

    fseek(file, 0, SEEK_END);

    if (ftell(file) == 0) {
        fprintf(file,
                "Algorithm,Input_Size,Execution_Time_ns,Result,Notes\n");
    }

    printf("\n===== Scheduling Algorithm Benchmark =====\n");
    printf("Number of surgeries: %d\n\n", hospital->surgery_count);

    for (int i = 0; i < algorithm_count; i++) {

        /* Give every algorithm identical starting data. */
        Hospital testHospital = *hospital;

        clock_t start = clock();

        algorithms[i].function(&testHospital);

        clock_t end = clock();

        if (start == (clock_t)-1 || end == (clock_t)-1) {
            printf("%s: Timing unavailable\n", algorithms[i].name);
            continue;
        }

        double elapsed_ns =
            ((double)(end - start) / CLOCKS_PER_SEC) * 1000000000.0;

        printf("%s: %.0f ns\n",
               algorithms[i].name, elapsed_ns);

        fprintf(file,
                "%s,%d,%.0f,Measured,Fresh copy of hospital data\n",
                algorithms[i].name,
                hospital->surgery_count,
                elapsed_ns);
    }

    fclose(file);

    printf("\nBenchmark results saved to %s\n", BENCHMARK_FILE);
    printf("==========================================\n");
}


#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#include "domain.h"
#include "scheduling.h"
#include "benchmark.h"

#define BENCHMARK_FILE "benchmarks/benchmark_results.csv"
#define RUNS 100

typedef void (*SchedulingFunction)(Hospital *);

typedef struct {
    const char *name;
    SchedulingFunction function;
} BenchmarkAlgorithm;

static double getTimeNanoseconds(void) {
    struct timespec ts;

    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0)
        return -1.0;

    return (double)ts.tv_sec * 1000000000.0
         + (double)ts.tv_nsec;
}

/* Run an algorithm without displaying its internal output. */
static void runSilently(SchedulingFunction function,
                        Hospital *hospital) {

    fflush(stdout);

    int saved_stdout = dup(STDOUT_FILENO);
    int devnull = open("/dev/null", O_WRONLY);

    if (saved_stdout == -1 || devnull == -1) {
        if (saved_stdout != -1)
            close(saved_stdout);

        if (devnull != -1)
            close(devnull);

        function(hospital);
        return;
    }

    dup2(devnull, STDOUT_FILENO);
    close(devnull);

    function(hospital);

    fflush(stdout);

    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
}

void runBenchmark(const Hospital *hospital) {

    if (hospital == NULL) {
        printf("Invalid hospital data.\n");
        return;
    }

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
        perror("Could not open benchmark CSV file");
        return;
    }

    fseek(file, 0, SEEK_END);

    if (ftell(file) == 0) {
        fprintf(file,
            "Algorithm,Input_Size,Average_Time_ns,Runs\n");
    }

    printf("\n===== SCHEDULING ALGORITHM BENCHMARK =====\n");
    printf("Number of surgeries: %d\n", hospital->surgery_count);
    printf("Number of runs per algorithm: %d\n\n", RUNS);

    printf("%-30s %18s\n", "Algorithm", "Average Time (ns)");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < algorithm_count; i++) {

        double totalTime = 0.0;
        int validRuns = 0;

        for (int j = 0; j < RUNS; j++) {

            Hospital testHospital = *hospital;

            double start = getTimeNanoseconds();

            if (start < 0)
                continue;

            runSilently(algorithms[i].function, &testHospital);

            double end = getTimeNanoseconds();

            if (end < start)
                continue;

            totalTime += end - start;
            validRuns++;
        }

        if (validRuns == 0) {
            printf("%-30s Timing unavailable\n",
                   algorithms[i].name);
            continue;
        }

        double averageTime = totalTime / validRuns;

        printf("%-30s %18.2f\n",
               algorithms[i].name, averageTime);

        fprintf(file, "%s,%d,%.2f,%d\n",
                algorithms[i].name,
                hospital->surgery_count,
                averageTime,
                validRuns);
    }

    fclose(file);

    printf("\nBenchmark results saved to %s\n",
           BENCHMARK_FILE);
    printf("==========================================\n");
}

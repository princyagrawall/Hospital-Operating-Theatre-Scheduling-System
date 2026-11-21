
#include <stdio.h>

#define MAX_SURGERIES 100
#define MAX_THEATRES 30

typedef struct {
    int id;
    int start;
    int end;
} Surgery;

int assignments[MAX_SURGERIES];
int theatre_end[MAX_THEATRES];

int backtrack(Surgery surgeries[], int n, int theatre_count, int index) {

    if (index == n)
        return 1;

    for (int i = 0; i < theatre_count; i++) {

        if (theatre_end[i] <= surgeries[index].start) {

            int previous_end = theatre_end[i];

            assignments[index] = i + 1;
            theatre_end[i] = surgeries[index].end;

            if (backtrack(surgeries, n, theatre_count, index + 1))
                return 1;

            /* Undo the assignment */
            theatre_end[i] = previous_end;
            assignments[index] = 0;
        }
    }

    return 0;
}

void scheduleUsingBacktracking(Surgery surgeries[], int n, int theatre_count) {

    if (n <= 0 || n > MAX_SURGERIES ||
        theatre_count <= 0 || theatre_count > MAX_THEATRES) {
        printf("Invalid scheduling input.\n");
        return;
    }

    for (int i = 0; i < MAX_THEATRES; i++)
        theatre_end[i] = 0;

    for (int i = 0; i < MAX_SURGERIES; i++)
        assignments[i] = 0;

    printf("\n===== BACKTRACKING SCHEDULER =====\n");

    if (backtrack(surgeries, n, theatre_count, 0)) {

        for (int i = 0; i < n; i++) {
            printf("Surgery %d -> Theatre %d\n",
                   surgeries[i].id, assignments[i]);
        }

        printf("\nAll surgeries successfully allocated.\n");
    } else {
        printf("No valid allocation found with available theatres.\n");
    }
}

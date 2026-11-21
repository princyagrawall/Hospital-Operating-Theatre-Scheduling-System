
#include <stdio.h>

typedef struct {
    int id;
    int start;
    int end;
} Surgery;

void scheduleUsingBacktracking(Surgery surgeries[], int n, int theatre_count);

int main(void) {

    Surgery surgeries[] = {
        {1, 540, 660},
        {2, 600, 720},
        {3, 660, 780},
        {4, 700, 820}
    };

    int n = sizeof(surgeries) / sizeof(surgeries[0]);

    scheduleUsingBacktracking(surgeries, n, 2);

    return 0;
}


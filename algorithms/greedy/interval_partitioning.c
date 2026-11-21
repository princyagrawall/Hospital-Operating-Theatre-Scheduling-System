
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int start;
    int end;
} SurgeryInterval;

void sortByStartTime(SurgeryInterval surgeries[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (surgeries[j].start > surgeries[j + 1].start) {
                SurgeryInterval temp = surgeries[j];
                surgeries[j] = surgeries[j + 1];
                surgeries[j + 1] = temp;
            }
        }
    }
}

void intervalPartitioning(SurgeryInterval surgeries[], int n) {
    if (n <= 0) return;

    sortByStartTime(surgeries, n);

    int theatreEnd[100];
    int theatreCount = 0;

    printf("\n===== INTERVAL PARTITIONING =====\n");

    for (int i = 0; i < n; i++) {
        int assigned = 0;

        for (int j = 0; j < theatreCount; j++) {
            if (theatreEnd[j] <= surgeries[i].start) {
                theatreEnd[j] = surgeries[i].end;

                printf("Surgery %d -> Theatre %d\n",
                       surgeries[i].id, j + 1);

                assigned = 1;
                break;
            }
        }

        if (!assigned) {
            if (theatreCount >= 100) {
                printf("Theatre limit reached.\n");
                return;
            }

            theatreEnd[theatreCount] = surgeries[i].end;
            theatreCount++;

            printf("Surgery %d -> Theatre %d\n",
                   surgeries[i].id, theatreCount);
        }
    }

    printf("\nMinimum Theatres Required: %d\n", theatreCount);
}

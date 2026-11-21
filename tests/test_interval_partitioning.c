
#include <stdio.h>

typedef struct {
    int id;
    int start;
    int end;
} SurgeryInterval;

void intervalPartitioning(SurgeryInterval surgeries[], int n);

int main(void) {
    SurgeryInterval surgeries[] = {
        {1, 540, 660},
        {2, 600, 720},
        {3, 660, 780},
        {4, 700, 820},
        {5, 780, 900}
    };

    int n = sizeof(surgeries) / sizeof(surgeries[0]);

    intervalPartitioning(surgeries, n);

    return 0;
}

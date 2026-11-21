
#include <stdio.h>

typedef struct {
    int id;
    char name[50];
} Surgery;

// Binary Search: searches for a surgery using its ID
int binarySearch(Surgery surgeries[], int n, int targetID) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (surgeries[mid].id == targetID) {
            return mid;
        }
        else if (surgeries[mid].id < targetID) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    Surgery surgeries[] = {
        {101, "Heart Surgery"},
        {102, "Brain Surgery"},
        {103, "Eye Surgery"},
        {104, "Knee Surgery"},
        {105, "Kidney Surgery"}
    };

    int n = sizeof(surgeries) / sizeof(surgeries[0]);
    int targetID;

    printf("Enter Surgery ID to search: ");
    scanf("%d", &targetID);

    int result = binarySearch(surgeries, n, targetID);

    if (result != -1) {
        printf("Surgery Found!\n");
        printf("ID: %d\n", surgeries[result].id);
        printf("Name: %s\n", surgeries[result].name);
    }
    else {
        printf("Surgery not found.\n");
    }

    return 0;
}

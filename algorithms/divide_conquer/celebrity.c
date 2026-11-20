
#include <stdio.h>

int findCelebrity(int n, int matrix[n][n]) {
    if (n <= 0)
        return -1;

    int candidate = 0;

    // Find a possible celebrity
    for (int i = 1; i < n; i++) {
        if (matrix[candidate][i] == 1)
            candidate = i;
    }

    // Verify the candidate
    for (int i = 0; i < n; i++) {
        if (i == candidate)
            continue;

        if (matrix[candidate][i] == 1 ||
            matrix[i][candidate] == 0) {
            return -1;
        }
    }

    return candidate;
}

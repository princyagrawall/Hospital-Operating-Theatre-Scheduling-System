
#include <stdio.h>
#include <stdlib.h>

static void addMatrix(const int *A, const int *B, int *C, int n) {
    for (int i = 0; i < n * n; i++)
        C[i] = A[i] + B[i];
}

static void subtractMatrix(const int *A, const int *B, int *C, int n) {
    for (int i = 0; i < n * n; i++)
        C[i] = A[i] - B[i];
}

static void strassenRecursive(
    const int *A, const int *B, int *C, int n
) {
    if (n == 1) {
        C[0] = A[0] * B[0];
        return;
    }

    int k = n / 2;
    int size = k * k;

    int *M = calloc(21 * size, sizeof(int));

    if (M == NULL)
        return;

    int *A11 = M;
    int *A12 = A11 + size;
    int *A21 = A12 + size;
    int *A22 = A21 + size;

    int *B11 = A22 + size;
    int *B12 = B11 + size;
    int *B21 = B12 + size;
    int *B22 = B21 + size;

    int *T1 = B22 + size;
    int *T2 = T1 + size;

    int *P1 = T2 + size;
    int *P2 = P1 + size;
    int *P3 = P2 + size;
    int *P4 = P3 + size;
    int *P5 = P4 + size;
    int *P6 = P5 + size;
    int *P7 = P6 + size;

    // Divide matrices into four submatrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i*k+j] = A[i*n+j];
            A12[i*k+j] = A[i*n+j+k];
            A21[i*k+j] = A[(i+k)*n+j];
            A22[i*k+j] = A[(i+k)*n+j+k];

            B11[i*k+j] = B[i*n+j];
            B12[i*k+j] = B[i*n+j+k];
            B21[i*k+j] = B[(i+k)*n+j];
            B22[i*k+j] = B[(i+k)*n+j+k];
        }
    }

    // P1 = A11 * (B12 - B22)
    subtractMatrix(B12, B22, T1, k);
    strassenRecursive(A11, T1, P1, k);

    // P2 = (A11 + A12) * B22
    addMatrix(A11, A12, T1, k);
    strassenRecursive(T1, B22, P2, k);

    // P3 = (A21 + A22) * B11
    addMatrix(A21, A22, T1, k);
    strassenRecursive(T1, B11, P3, k);

    // P4 = A22 * (B21 - B11)
    subtractMatrix(B21, B11, T1, k);
    strassenRecursive(A22, T1, P4, k);

    // P5 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, T1, k);
    addMatrix(B11, B22, T2, k);
    strassenRecursive(T1, T2, P5, k);

    // P6 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A12, A22, T1, k);
    addMatrix(B21, B22, T2, k);
    strassenRecursive(T1, T2, P6, k);

    // P7 = (A11 - A21) * (B11 + B12)
    subtractMatrix(A11, A21, T1, k);
    addMatrix(B11, B12, T2, k);
    strassenRecursive(T1, T2, P7, k);

    // Combine results into C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int x = i * k + j;

            int C11 = P5[x] + P4[x] - P2[x] + P6[x];
            int C12 = P1[x] + P2[x];
            int C21 = P3[x] + P4[x];
            int C22 = P5[x] + P1[x] - P3[x] - P7[x];

            C[i*n+j] = C11;
            C[i*n+j+k] = C12;
            C[(i+k)*n+j] = C21;
            C[(i+k)*n+j+k] = C22;
        }
    }

    free(M);
}

int strassenMultiply(const int *A, const int *B, int *C, int n) {
    if (A == NULL || B == NULL || C == NULL || n <= 0)
        return 0;

    int m = 1;

    while (m < n) {
        if (m > 1024)
            return 0;

        m *= 2;
    }

    if ((size_t)m > (size_t)-1 / (size_t)m / sizeof(int))
        return 0;

    size_t count = (size_t)m * m;

    int *PA = calloc(count, sizeof(int));
    int *PB = calloc(count, sizeof(int));
    int *PC = calloc(count, sizeof(int));

    if (!PA || !PB || !PC) {
        free(PA);
        free(PB);
        free(PC);
        return 0;
    }

    // Pad input matrices with zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            PA[i*m+j] = A[i*n+j];
            PB[i*m+j] = B[i*n+j];
        }
    }

    strassenRecursive(PA, PB, PC, m);

    // Copy result back to original size
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i*n+j] = PC[i*m+j];
        }
    }

    free(PA);
    free(PB);
    free(PC);

    return 1;
}


#ifndef ALGORITHMS_H
#define ALGORITHMS_H

/* Sorting */
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);

/* Searching */
int binarySearchIterative(int arr[], int n, int key);
int binarySearchRecursive(int arr[], int low, int high, int key);

/* Divide and Conquer */
int findCelebrity(int n, int matrix[][100]);
long long fastPower(long long base, unsigned int exponent);
int maximumSubarray(int arr[], int low, int high);
int strassenMultiply(const int *A, const int *B, int *C, int n);

#endif


#include <stdio.h>

int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0;
    int leftSum = -2147483647;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = -2147483647;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maximumSubarray(int arr[], int low, int high) {
    if (low == high)
        return arr[low];

    int mid = low + (high - low) / 2;

    int leftSum = maximumSubarray(arr, low, mid);
    int rightSum = maximumSubarray(arr, mid + 1, high);

    int crossSum = maxCrossingSum(arr, low, mid, high);

    return maxValue(leftSum, maxValue(rightSum, crossSum));
}

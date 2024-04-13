#include <stdio.h>
#include <limits.h>

int max(int a, int b, int c) {
    return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
}

void findMaxCrossingSubarray(int arr[], int low, int mid, int high, int *maxSum, int result[], int *resultSize) {
    int leftSum = INT_MIN;
    int sum = 0;
    int left = mid;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            left = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    int right = mid + 1;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            right = i;
        }
    }

    *maxSum = leftSum + rightSum;

    // copy to result array
    *resultSize = right - left + 1;
    for (int i = left, j = 0; i <= right; i++, j++) {
        result[j] = arr[i];
    }
}

void findMaxSubarray(int arr[], int low, int high, int *maxSum, int result[], int *resultSize) {
    if (low == high) {
        *maxSum = arr[low];
        result[0] = arr[low];
        *resultSize = 1;
    } else {
        int mid = (low + high) / 2;

        int leftMaxSum, rightMaxSum, crossMaxSum;
        int leftResult[high - low + 1], rightResult[high - low + 1], crossResult[high - low + 1];
        int leftResultSize, rightResultSize, crossResultSize;

        findMaxSubarray(arr, low, mid, &leftMaxSum, leftResult, &leftResultSize);
        findMaxSubarray(arr, mid + 1, high, &rightMaxSum, rightResult, &rightResultSize);
        findMaxCrossingSubarray(arr, low, mid, high, &crossMaxSum, crossResult, &crossResultSize);

        if (leftMaxSum >= rightMaxSum && leftMaxSum >= crossMaxSum) {
            *maxSum = leftMaxSum;
            *resultSize = leftResultSize;
            for (int i = 0; i < leftResultSize; i++) {
                result[i] = leftResult[i];
            }
        } else if (rightMaxSum >= leftMaxSum && rightMaxSum >= crossMaxSum) {
            *maxSum = rightMaxSum;
            *resultSize = rightResultSize;
            for (int i = 0; i < rightResultSize; i++) {
                result[i] = rightResult[i];
            }
        } else {
            *maxSum = crossMaxSum;
            *resultSize = crossResultSize;
            for (int i = 0; i < crossResultSize; i++) {
                result[i] = crossResult[i];
            }
        }
    }
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum;
    int maxSubarray[n], resultSize;

    findMaxSubarray(arr, 0, n - 1, &maxSum, maxSubarray, &resultSize);

    printf("Maximum Subarray Sum: %d\n", maxSum);
    printf("Subarray: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", maxSubarray[i]);
    }
    printf("\n");

    return 0;
}

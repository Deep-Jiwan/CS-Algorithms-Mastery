#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
void printSubset(int subset[], int size) {
    printf("Subset with the sum: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}
void subsetSum(int arr[], int subset[], int n, int sum, int currentSum, int index, int subsetSize, bool *found) {
    if (currentSum == sum) {
        printSubset(subset, subsetSize);
        *found = true;
        return;
    }
    // Base case: end of recursion 
    if (index == n || currentSum > sum) {
        return;
    }
    // Include the current element in the subset and recur
    subset[subsetSize] = arr[index];
    subsetSum(arr, subset, n, sum, currentSum + arr[index], index + 1, subsetSize + 1, found);
    // Exclude the current element from the subset and recur
    subsetSum(arr, subset, n, sum, currentSum, index + 1, subsetSize, found);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[MAX_SIZE];
    int subset[MAX_SIZE];
    printf("Enter %d space-separated integer values for the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum;
    printf("Enter the value of d: ");
    scanf("%d", &sum);
    bool found = false;
    subsetSum(arr, subset, n, sum, 0, 0, 0, &found);
    if (!found) {
        printf("\nNo subset found with the sum %d\n", sum);
    }
    else{
        printf("\nSubset found with the sum %d\n", sum);
    }
    printf("\n22BCE3789 - Deep Mukesh Jiwan 2024");
    return 0;
}

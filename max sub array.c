#include <stdio.h>
#include <limits.h>

int max(int a, int b) { return (a > b) ? a : b; }

int maxCrossingSum(int arr[], int l, int m, int h) {
    int sum = 0, left_sum = INT_MIN, right_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum) left_sum = sum;
    }
    sum = 0;
    for (int i = m + 1; i <= h; i++) {
        sum += arr[i];
        if (sum > right_sum) right_sum = sum;
    }
    return left_sum + right_sum;
}

int maxSubArray(int arr[], int l, int h) {
    if (l == h) return arr[l];
    int m = (l + h) / 2;
    return max(max(maxSubArray(arr, l, m),
                   maxSubArray(arr, m + 1, h)),
               maxCrossingSum(arr, l, m, h));
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int max_sum = maxSubArray(arr, 0, n - 1);
    printf("Maximum Subarray Sum = %d\n", max_sum);
    return 0;
}
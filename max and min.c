#include <stdio.h>

int min, max;

void findMinMax(int arr[], int low, int high) {
    if (low == high) {  
        if (arr[low] > max) max = arr[low];
        if (arr[low] < min) min = arr[low];
    } 
    else if (high == low + 1) {  
        if (arr[low] < arr[high]) {
            if (arr[low] < min) min = arr[low];
            if (arr[high] > max) max = arr[high];
        } else {
            if (arr[high] < min) min = arr[high];
            if (arr[low] > max) max = arr[low];
        }
    } 
    else {
        int mid = (low + high) / 2;
        findMinMax(arr, low, mid);
        findMinMax(arr, mid + 1, high);
    }
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    min = max = arr[0];
    findMinMax(arr, 0, n - 1);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);
    return 0;
}
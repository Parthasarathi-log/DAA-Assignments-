#include <stdio.h>

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[right];
    int i = left;
    int j;

    for (j = left; j < right; j++) {
        if (arr[j] < pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[right];
    arr[right] = temp;

    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int main() {
    int arr[] = {5, 3, 7, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    quickSort(arr, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


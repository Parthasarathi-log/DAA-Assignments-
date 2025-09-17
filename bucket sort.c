#include <stdio.h>

void bucketSort(int arr[], int n) {
    int buckets[10][10], count[10] = {0};

    for(int i = 0; i < n; i++) {
        int bi = arr[i] / 10;
        buckets[bi][count[bi]++] = arr[i];
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 1; j < count[i]; j++) {
            int key = buckets[i][j], k = j - 1;
            while(k >= 0 && buckets[i][k] > key)
                buckets[i][k + 1] = buckets[i][k--];
            buckets[i][k + 1] = key;
        }
    }

    int idx = 0;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < count[i]; j++)
            arr[idx++] = buckets[i][j];
}

int main() {
    int arr[] = {42, 32, 33, 52, 37, 47, 51};
    int n = 7;

    bucketSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0, b[100];
    while(i <= m && j <= r)
        b[k++] = a[i] < a[j] ? a[i++] : a[j++];
    while(i <= m) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(i = l, j = 0; i <= r; i++, j++) a[i] = b[j];
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[] = {3, 1, 2, 5, 4}, n = 5;
    mergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

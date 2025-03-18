#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergesort(int a[], int low, int high);
void simplesort(int a[], int low, int mid, int high);

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        simplesort(a, low, mid, high);
    }
}

void simplesort(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int *c = (int *)malloc((high - low + 1) * sizeof(int));


    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    while (i <= mid) {
        c[k++] = a[i++];
    }

    while (j <= high) {
        c[k++] = a[j++];
    }

    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }

    free(c);
}

int main() {
    int a[20], n;
    clock_t start, end;
    double time_taken;

    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the array of elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    start = clock();
    mergesort(a, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Time taken to sort: %f sec\n", time_taken);

    return 0;
}

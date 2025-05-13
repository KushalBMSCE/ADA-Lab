#include<stdio.h>
#include<time.h>
int a[100000], n;

void quick_sort(int [],int,int);
int partition(int[],int,int);
int main()
{
    int i;
    clock_t start, end;
    double time_taken;

    printf("Enter the size of an array : ");
    scanf("%d", &n);

    printf("Enter the array elements:");
    for (i = 0; i < n; i++) {
        a[i] = rand();
    }

    start = clock();
    quick_sort(a, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Time taken to sort: %f seconds\n", time_taken);

    return 0;
}

void quick_sort(int a[], int low, int high) {
    if(low < high) {
        int pivot_index = partition(a,low,high);
        quick_sort(a,low,pivot_index-1);
        quick_sort(a,pivot_index+1,high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low+1, j = high, temp;
    while(i <= j) {
        while(i <= high && a[i] < pivot) {
            i++;
        }
        while(j >= low && a[j] > pivot) {
            j--;
        }
        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

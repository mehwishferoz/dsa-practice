#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100000

void merge(int arr[10], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for(i=0;i<n1;i++)
        L[i] = arr[l+i];
    for(j=0;j<n2;j++)
        R[j] = arr[m + 1 +j];
    i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[10], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void display(int arr[10])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%1000;
    }
    clock_t start, end;
    start = clock();
    mergesort(arr, 0, n - 1);
    end = clock();
    double duration = ((double)(end - start)/CLOCKS_PER_SEC);
    printf("Time: %g", duration);
    // display(arr);

    return 0;
}

/*
Notes:
Merge sort is a sorting algorithm that works by dividing an array into smaller subarrays, 
sorting each subarray, and then merging the sorted subarrays back together to form the final sorted array.
Time Complexity:
    1. Worst case - O(nlogn)
    2. Average case - O(nlogn)
    3. Best case - O(nlogn)
Auxiliary Space - O(n)

Merge sort is:
    - out-place (merging step requires extra space to store the elements)
    - stable (order of elements with equal values is preserved during the sort)
    - non-adaptive
    - relatively efficient for sorting large datasets
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 80000

void swap(int arr[10], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[10])
{
    clock_t start, end;
    start = clock();
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr, j+1, j);
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    end = clock();
    double duration = ((double)(end - start)/CLOCKS_PER_SEC);
    printf("Time: %g", duration);
}

int main()
{
    clock_t start, end;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%1000;
    }
    bubbleSort(arr);
    return 0;
}

/*
Notes: 
Bubble Sort is the simplest sorting algorithm that works by repeatedly 
swapping the adjacent elements if they are in the wrong order.

Time Complexity:
    1. Worst case - O(N2)
    2. Average case - O(N2)
    3. Best case - O(N)
Auxiliary Space - O(1)

Bubble sort is:
    - in-place (does'nt use any other major data structure)
    - unstable (elements with the same key value may not retain their relative order)
    - adaptive (if flag is used)

*/
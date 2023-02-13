#include<stdio.h>

void display(int arr[10])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}

void swap(int arr[10], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[10], int l, int r)
{
    int i, j, pivot;
    pivot = arr[r];
    j = l;
    i = j - 1;
    while(j<r)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
        j++;
    }
    swap(arr,i+1,r);
    return i+1;
}

void quickSort(int arr[10], int l, int r)
{
    if(l<r)
    {
        int pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main()
{
    int arr[10] = {2, 5, 1, 0, 99, 6, 4, 8, 12, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    display(arr);
    return 0;
}

/*
Notes:
It picks an element as a pivot and partitions the given array around the picked pivot.
Time Complexity:
    1. Worst case - O(N^2)
    2. Average case - O(nlogn)
    3. Best case - O(nlogn)
Auxiliary Space - O(logn)

Quick sort is:
    - in-place (as it uses extra space only for storing recursive function calls but not for manipulating the input)
    - unstable (default implementation is not stable)
*/
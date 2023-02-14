#include<stdio.h>

void insertionSort(int A[10])
{
    for(int i=1;i<10;i++)
    {
        int temp = A[i]; 
        int j = i-1;  
        while(j>=0 && A[j]>temp)
        {
            A[j+1] = A[j];  
            j--;  
        }
        A[j+1] = temp;
    }
}

void display(int A[10])
{
    for(int i=0;i<10;i++)
    {
        printf("%d ", A[i]);
    }
} 

int main()
{
    int A[10] = {7,2,3,4,6,2,1,10,11,0};
    insertionSort(A);
    display(A);
    return 0;
}

/*
Notes:
The array is virtually split into a sorted and an unsorted part. 
Values from the unsorted part are picked and placed at the correct position in the sorted part.

Time Complexity:
    1. Worst case - O(N2)
    2. Average case - O(N2)
    3. Best case - O(N)
Auxiliary Space - O(1)

Insertion sort is:
    - in-place (doesn't use any other major data structure)
    - stable (elements with the same key value retain their relative order)
    - adaptive (appropriate for data sets that are partially sorted)
*/
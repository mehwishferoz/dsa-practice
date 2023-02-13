#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 90000

void display(int arr[10])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void selectionSort(int arr[10])
{
    
    clock_t start, end;
    start = clock();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    end = clock();
    double duration = ((double)(end - start)/CLOCKS_PER_SEC);
    printf("Time: %g", duration);
}

int main()
{
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%1000;
    }
    selectionSort(arr);
    // display(arr,n);

    return 0;
}
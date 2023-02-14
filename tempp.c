#include<stdio.h>
#include<stdlib.h>
#define n 20

void display(int* arr)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr+i));
    }
}

void bubblesort(int* arr)
{
    int flag=0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if(*(arr+j+1)<*(arr+j))
            {
                int swap = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = swap;
                flag=1;
            }
        }
        if(!flag)
        break;
    }
}

void swap(int* arr, int i, int j)
{
    int temp = *(arr+i);
    *(arr+i) = *(arr+j);
    *(arr+j) = temp;
}

int partition(int* arr, int l, int r)
{
    int i, j, pivot;
    j = l;
    i = j - 1;
    pivot=*(arr+r);
    while(j<r)
    {
        if(*(arr+j)<pivot)
        {
            i++;
            swap(arr,i,j);
        }
        j++;
    }
    swap(arr,i+1,r);
    return i+1;
}

void quicksort(int* arr, int l, int r)
{
    if(l<r)
    {
        int pi = partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}

void merge(int* arr, int l, int m, int r)
{

}

void mergesort(int *arr, int l, int r)
{
    
}

/*
void insertionSort1(int n, int* arr) {
    int j, temp;
    j = n-1;
    temp = *(arr+j);
    while(temp<*(arr+j-1))
    {
        *(arr+j)=*(arr+j-1);
        j--;
    }
    *(arr+j)=temp;
    display(arr, n);
}

*/

int main()
{
    int *arr;
    arr = (int*)malloc(sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(arr+i)=rand();
    }
    // bubblesort(arr);
    // quicksort(arr,0,n-1);
    megresort(arr,0,n-1);
    display(arr);    
    
    return 0;
}

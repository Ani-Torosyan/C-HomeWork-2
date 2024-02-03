#include <stdio.h>
#include <stdlib.h>

#define THRESHOLD 10 // Threshold for switching to insertion sort
 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
 
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
 
    i = 0;
    j = 0;
    k = l;
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

    free(L);
    free(R);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
     if (l < r) 
     {
        if (r - l + 1 <= THRESHOLD) 
        {
            insertionSort(arr + l, r - l + 1); // Use insertion sort for small arrays
        } 
        else 
        {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
 
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 , 1, 0, 21, 8, 31, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}
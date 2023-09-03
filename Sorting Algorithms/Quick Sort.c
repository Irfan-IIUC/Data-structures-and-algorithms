#include <stdio.h>

void display(int* arr, int n)
{
    int i;

    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot=arr[high], i=low-1, j;

    for(j=low; j<=high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);  // sort left subarray
        quickSort(arr, pi+1, high); // sort right subarray
    }
}

int main()
{
    int arr[] = {8,2,4,7,1,3,9,6,5}, n=9;

    printf("Before Sorting: ");
    display(arr, n);

    quickSort(arr, 0, n-1);

    printf("After Sorting: ");
    display(arr, n);

    return 0;
}

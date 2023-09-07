#include <stdio.h>

void display(int* arr, int n)
{
    int i;

    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void merge(int arr[], int mid, int low, int high)
{
    int i, j, k, B[100];

    i = low;
    j = mid + 1;
    k = low;

    while((i<=mid) && (j<=high))
    {
        if(arr[i] < arr[j])
            B[k++] = arr[i++];
        else
            B[k++] = arr[j++];
    }

    while(i <= mid)
        B[k++] = arr[i++];

    while(j <= high)
        B[k++] = arr[j++];

    for(i=low; i<=high; i++)
        arr[i] = B[i];
}

void mergeSort(int arr[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low+high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, mid, low, high);
    }
}

int main()
{
    int arr[] = {6,4,2,1,9,8,3,5}, n=8;

    printf("Before Sorting: ");
    display(arr, n);

    mergeSort(arr, 0, n-1);

    printf("After Sorting: ");
    display(arr, n);

    return 0;
}

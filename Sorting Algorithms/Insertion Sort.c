#include<stdio.h>

void display(int* arr, int n)
{
    int i;

    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void insertion_sort(int* arr, int n)
{
    int i, j, temp;

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j>0; j--)
        {
            if(arr[j] < arr[j-1])
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {7,2,81,77,3}, n=5;

    printf("Before sorting: ");
    display(arr, n);

    insertion_sort(arr, n);

    printf("After sorting: ");
    display(arr, n);

    return 0;
}

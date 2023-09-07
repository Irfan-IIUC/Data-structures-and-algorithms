#include<stdio.h>

void display(int* arr, int n)
{
    int i;

    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void bubble_sort(int* arr, int n)
{
    int i, j, temp;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubble_sort_adaptive(int* arr, int n)
{
    int i, j, temp, isSorted;

    for(i=0; i<n-1; i++)
    {
        isSorted = 1;

        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                isSorted = 0;
            }
        }

        if(isSorted)
            break;
    }
}

int main()
{
    int arr[6] = {7,11,9,2,17,4}, n=6;

    printf("Before Sorting: ");
    display(arr, n);

    bubble_sort(arr, n);
    // bubble_sort_adaptive(arr, n);

    printf("\nAfter Sorting: ");
    display(arr, n);

    return 0;
}

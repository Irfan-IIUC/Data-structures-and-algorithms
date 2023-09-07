#include<stdio.h>

void display(int* arr, int n)
{
    int i;

    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void selection_sort(int* arr, int n)
{
    int i, j, min_index, temp;

    for(i=0; i<n-1; i++)
    {
        min_index = i;

        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main()
{
    int arr[] = {8,0,7,1,3}, n=5;

    printf("Before Sorting: ");
    display(arr, n);

    selection_sort(arr, n);

    printf("After Sorting: ");
    display(arr, n);

    return 0;
}

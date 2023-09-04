#include <stdio.h>

void display(int* arr, int n)
{
    int i;

    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void countSort(int* arr, int n)
{
    int max = -1, i=0, j;

    for(i=0; i<n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    int count[max+1];

    for(i=0; i<max+1; i++)
        count[i] = 0;

    for(i=0; i<n; i++)
        count[arr[i]]++;

    i=0;

    for(j=0; j<max+1; j++)
    {
        while(count[j] != 0)
        {
            arr[i++] = j;
            count[j]--;
        }
    }
}

int main()
{
    int arr[] = {3,1,9,7,1,2,4}, n=7;

    printf("Before Sorting: ");
    display(arr, n);

    countSort(arr, n);

    printf("After Sorting: ");
    display(arr, n);

    return 0;
}

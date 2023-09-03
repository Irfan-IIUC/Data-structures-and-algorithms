#include <stdio.h>

// function to find the maximum number in an array
int getMax(int arr[], int n)
{
    int max = arr[0], i;

    for(i=1; i<n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

// counting Sort for a specific digit
void countSort(int arr[], int n, int exp)
{
    int output[n], count[10] = {0}, i;

    // count the occurrences of each digit at the current exp position
    for(i=0; i<n; i++)
        count[(arr[i] / exp) % 10]++;

    // calculate the cumulative count
    for(i=1; i<10; i++)
        count[i] += count[i-1];

    // Build the output array
    for(i=n-1; i>=0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // copy the sorted elements back to the original array
    for(i=0; i<n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n), exp;

    // perform counting sort for every digit, starting from least significant digit (LSD)
    for(exp=1; max/exp > 0; exp*=10)
        countSort(arr, n, exp);
}

void printArray(int arr[], int n)
{
    int i;

    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[] = {170,45,75,90,802,24,2,66}, n;
    n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("After Sorting: ");
    printArray(arr, n);

    return 0;
}

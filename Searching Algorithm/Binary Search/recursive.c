#include<bits/stdc++.h>

struct Array
{
    int size, length;
    int* arr;
};

int binary_search(struct Array* ptr, int low, int high, int key)
{
    int mid;

    if(low <= high)
    {
        mid = (low+high) / 2;

        if(key == ptr->arr[mid])
            return mid;
        else if(key > ptr->arr[mid])
            return binary_search(ptr, mid+1, high, key);
        else
            return binary_search(ptr, low, mid-1, key);
    }

    return -1;
}

int main()
{
    struct Array* ptr;
    int i, low, high, key;

    // Allocate memory for the struct
    ptr = (struct Array*)malloc(sizeof(struct Array));
    if(ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    printf("Enter Size of an Array: ");
    scanf("%d", &ptr->size);

    // Allocate memory for the array inside the struct
    ptr->arr = (int*)malloc(sizeof(int) * ptr->size);

    printf("\nEnter Number of Elements: ");
    scanf("%d", &ptr->length);

    printf("\nEnter %d Elements (in ascending order): ", ptr->length);
    for(i=0; i<ptr->length; i++)
    {
        scanf("%d", &ptr->arr[i]);
    }

    printf("\nEnter the Element which you want to find in the Array: ");
    scanf("%d", &key);

    low = 0, high = ptr->length-1;
    int x = binary_search(ptr, low, high, key);

    if(x == -1)
        printf("\nElement not found!\n");
    else
        printf("\nElement found at Index: %d\n", x);

    // Free the memory when you're done using it
    free(ptr);

    return 0;
}

#include<bits/stdc++.h>

struct Array
{
    int size, length;
    int* arr;
};

void display(struct Array* ptr)
{
    int i;

    printf("\nThe elements in the array are: ");
    for(i=0; i<ptr->length; i++)
    {
        printf("%d ", ptr->arr[i]);
    }

    printf("\n");
}

int linear_search(struct Array* ptr, int key)
{
    int i, found=0;

    // search for the target element in the array
    for(i=0; i<ptr->length; i++)
    {
        if(ptr->arr[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    struct Array* ptr;
    int i, key;

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

    printf("\nEnter %d Elements: ", ptr->length);
    for(i=0; i<ptr->length; i++)
    {
        scanf("%d", &ptr->arr[i]);
    }

    printf("\nEnter the Element which you want to find in the Array: ");
    scanf("%d", &key);

    int x = linear_search(ptr, key);

    if(x == -1)
        printf("\nElement not found!\n");
    else
        printf("\nElement found at Index: %d\n", x);

    // Display all the elements in the array
    display(ptr);

    // Free the memory when you're done using it
    free(ptr);

    return 0;
}

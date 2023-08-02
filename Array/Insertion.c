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

void insert(struct Array* ptr, int index, int val)
{
    int i;

    if((index < 0) || (index > ptr->length)) // check if the given index is valid or not
        printf("\nInvalid index!\n");
    else
    {
        // shifting the elements to its adjacent right
        for(i=ptr->length; i>index; i--)
        {
            ptr->arr[i] = ptr->arr[i-1];
        }

        ptr->arr[index] = val;
        ptr->length++;

        printf("\nElement inserted successfully!\n");
    }
}

int main()
{
    struct Array* ptr;
    int i, index, value;

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

    printf("\nEnter the position and value for insertion: ");
    scanf("%d %d", &index, &value);

    insert(ptr, index, value);

    // Display all the elements in the array
    display(ptr);

    // Free the memory when you're done using it
    free(ptr);

    return 0;
}

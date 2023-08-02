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

void Delete(struct Array* ptr, int val)
{
    int i, found=0, index;

    // search for the target element
    for(i=0; i<ptr->length; i++)
    {
        if(ptr->arr[i] == val)
        {
            index = i;
            found = 1;

            break;
        }
    }

    if(found == 1)
    {
        // shifting the elements to its adjacent left
        for(i=index; i<ptr->length-1; i++)
        {
            ptr->arr[i] = ptr->arr[i+1];
        }

        ptr->length--;
        printf("\nElement deleted successfully!\n");
    }
    else
    {
        printf("\nElement not found in the array!\n");
    }
}

int main()
{
    struct Array* ptr;
    int i, value;

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

    printf("\nEnter the value for deletion: ");
    scanf("%d", &value);

    Delete(ptr, value);

    // Display all the elements in the array
    display(ptr);

    // Free the memory when you're done using it
    free(ptr);

    return 0;
}

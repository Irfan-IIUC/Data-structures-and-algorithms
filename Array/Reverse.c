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

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(struct Array* ptr)
{
    int i, j;

    for(i=0, j=ptr->length-1; i<j; i++, j--)
    {
        swap(&ptr->arr[i], &ptr->arr[j]);
    }
}

int main()
{
    struct Array* ptr;
    int i;

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

    reverse(ptr);

    display(ptr);

    // Free the memory when you're done using it
    free(ptr);

    return 0;
}

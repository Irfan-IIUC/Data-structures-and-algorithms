#include<stdio.h>
#include<stdlib.h>

struct myArray{
    int used_size;
    int total_size;
    int* a;
};

int linear_search(struct myArray* arr, int num)
{
    int i;

    for(i=0; i<arr->used_size; i++)
    {
        if(arr->a[i] == num)
            return i;
    }

    return -1;
}

int main()
{
    int num, index, i;

    struct myArray arr;

    printf("Enter total size & used size: ");
    scanf("%d%d", &arr.total_size, &arr.used_size);

    arr.a = (int*)calloc(arr.total_size, sizeof(int));

    if(arr.a == NULL)
        printf("Memory allocation failed!");

    printf("\nEnter %d elements: ", arr.used_size);
    for(i=0; i<arr.used_size; i++)
        scanf("%d", &arr.a[i]);

    printf("\nEnter the element to be search: ");
    scanf("%d", &num);

    index = linear_search(&arr, num);

    if(index == -1)
        printf("\nElement not found in the array!\n");
    else
        printf("\nElement found at index %d\n", index);

    return 0;
}

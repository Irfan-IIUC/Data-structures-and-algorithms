#include<stdio.h>
#include<math.h>

int arr[] = {15,20,7,9,30,-1,-1}, size=5;

void display(int n)
{
    int i;

    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void build_max_heap()
{
    int i=1, j, parent, temp;

    while(i < size)
    {
        j = i;
        parent = ceil(j/2.0) - 1;

        while((arr[parent] < arr[j]) && (parent >= 0))
        {
            temp = arr[j];
            arr[j] = arr[parent];
            arr[parent] = temp;

            j = parent;
            parent = ceil(j/2.0) - 1;
        }

        i++;
    }
}

int main()
{
    int i=0, j, temp, l_child, r_child, k, n=size;

    printf("Before constructing: ");
    display(size);

    // building max-heap tree
    build_max_heap();

    printf("After constructing: ");
    display(size);

    // now delete elements one by one from root
    while(i < size-1)
    {
        temp = arr[0];
        arr[0] = arr[size-i-1];
        arr[size-i-1] = temp;

        j = 0;
        n--;

        // max heap property check
        while(1)
        {
            l_child = (2*j) + 1;
            r_child = (2*j) + 2;

            if(l_child >= n)
                break;
            else if((l_child < n) && (arr[r_child] >= n))
                k = l_child;
            else if(arr[l_child] >= arr[r_child])
                k = l_child;
            else if(arr[l_child] < arr[r_child])
                k = r_child;

            if(arr[j] >= arr[k])
                break;
            else
            {
                // swap parent and child
                temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }

            j = k;
        }

        i++;
    }

    printf("\nNow the elements of the array: ");
    display(size);

    return 0;
}

#include<stdio.h>
#include<math.h>

/*
                10
             /      \
           15        19
         /    \    /    \
        20    30  25    39
       /  \    /
      23  40  35

      The above binary tree is a min-heap. We have to insert 6 in it!
*/

int heap[50] = {10,15,19,20,30,25,39,23,40,35}, heap_size=10, key=6;

void display(int n)
{
    int i=0;

    for(i=0; i<n; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    int i = heap_size, parent, temp;

    printf("Before inserting: ");
    display(heap_size);

    // initially insert 60 as leaf node
    heap[heap_size++] = key;

    // keep iterating until index 0 (means root)
    while(i >= 0)
    {
        parent = ceil(i/2.0) - 1;

        // check if parent is greater than child
        if(heap[parent] <= heap[i])
            break;
        else
        {
            // swap parent and child
            temp = heap[i];
            heap[i] = heap[parent];
            heap[parent] = temp;

            i = parent;
        }
    }

    printf("\nAfter inserting: ");
    display(heap_size);

    return 0;
}

#include<stdio.h>
#include<math.h>

/*
                70
             /      \
           50        40
         /    \    /    \
        45    35  39    16
       /  \
      10   9

      The above binary tree is a max-heap. We have to insert 60 in it!
*/

int heap[50] = {70,50,40,45,35,39,16,10,9}, heap_size=9, key=60;

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
        if(heap[parent] >= heap[i])
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

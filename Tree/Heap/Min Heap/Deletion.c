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

      The above binary tree is a min-heap. We have to delete 10 from it!
*/

int heap[50] = {10,15,19,20,30,25,39,23,40,35,-1,-1,-1,-1,-1}, heap_size=10, key=10;

void display(int n)
{
    int i=0;

    for(i=0; i<n; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    int i, j, temp, l_child, r_child;

    printf("Before deletion: ");
    display(heap_size);

    heap[0] = heap[heap_size-1];
    heap[heap_size-1] = -1;
    heap_size--;

    i = 0; // parent

    while(i < heap_size)
    {
        l_child = (2*i) + 1;
        r_child = (2*i) + 2;

        if(l_child >= heap_size)
            break;
        else if((l_child < heap_size) && (heap[r_child] == -1))
            j = l_child;
        else if(heap[l_child] <= heap[r_child])
            j = l_child;
        else if(heap[l_child] > heap[r_child])
            j = r_child;

        // max heap property check
        if(heap[i] <= heap[j])
            break;
        else
        {
            // swap parent and child
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;

            i = j;
        }
    }

    printf("\nAfter deletion: ");
    display(heap_size);

    return 0;
}

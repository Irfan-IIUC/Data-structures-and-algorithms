#include<stdio.h>
#include<math.h>

/*
                50
             /      \
           45        30
         /    \    /    \
        33    16  25    34
       /  \
      12  10

      The above binary tree is a max-heap. We have to delete 50 from it!
*/

int heap[50] = {50,45,30,33,16,25,34,12,10,-1,-1,-1,-1,-1,-1}, heap_size=9, key=50;

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
        else if(heap[l_child] >= heap[r_child])
            j = l_child;
        else if(heap[l_child] < heap[r_child])
            j = r_child;

        // max heap property check
        if(heap[i] >= heap[j])
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

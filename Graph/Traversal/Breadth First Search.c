#include<stdio.h>
#include<stdlib.h>

#define N 7

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};


int isEmpty(struct queue *q)
{
    if(q->r == q->f)
    {
        return 1;
    }

    return 0;
}

int isFull(struct queue *q)
{
    if(q->r == q->size-1)
    {
        return 1;
    }

    return 0;
}

void enqueue(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("This Queue is full!\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;

    if(isEmpty(q))
    {
        printf("This Queue is empty!\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }

    return a;
}

int main()
{
    // initializing Queue (array implementation)
    struct queue q;

    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));

    /*
        0 ---- 1
        | \    |
        |  \   |
        |   \  |
        |    \ |
        3 ---- 2
         \     /
          \   /
           \ /
            4
           / \
          /   \
         5     6
    */

    // BFS Implementation (start with node 1)
    int node;
    int i = 1, j;
    int visited[N] = {0,0,0,0,0,0,0};

    int graph[N][N] =
    {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    printf("Breadth-First Search traversal: %d ", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration

    while(!isEmpty(&q))
    {
        node = dequeue(&q);

        for(j=0; j<N; j++)
        {
            if((graph[node][j] == 1) && (!visited[j]))
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    printf("\n");

    return 0;
}

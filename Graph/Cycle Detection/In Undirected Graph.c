#include<stdio.h>
#include<stdlib.h>

#define N 5

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
        return 1;

    return 0;
}

int isFull(struct queue *q)
{
    if(q->r == q->size-1)
        return 1;

    return 0;
}

void enqueue(struct queue *q, int val)
{
    if(isFull(q))
        printf("This Queue is full\n");
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
        printf("This Queue is empty\n");
    else
    {
        q->f++;
        a = q->arr[q->f];
    }

    return a;
}

int main()
{
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;

    q.arr = (int*)malloc(q.size * sizeof(int));

    /*
           1-----3
          / \    |
         /   \   |
        0     \  |
         \     \ |
          \     \|
           2     4
    */

    // BFS Implementation
    int node, i=0, j, flag[N] = {-1,-1,-1,-1,-1}, visited[N]= {0,0,0,0,0};

    int graph[N][N] =
    {
        {0,1,1,0,0},
        {1,0,0,1,1},
        {1,0,0,0,0},
        {0,1,0,0,1},
        {0,1,1,0,0}
    };

    enqueue(&q, i);
    visited[i] = 1;
    flag[i] = 0;

    while(!isEmpty(&q))
    {
        node = dequeue(&q);
        flag[node] = 1;

        for(j=0; j<N; j++)
        {
            if(graph[node][j] == 1 && flag[j] == 0)
            {
                printf("The graph contains cycle!\n");
            }
            else if(graph[node][j] == 1 && !visited[j])
            {
                flag[j] = 0;
                enqueue(&q, j);
                visited[j] = 1;
            }
        }
    }

    return 0;
}

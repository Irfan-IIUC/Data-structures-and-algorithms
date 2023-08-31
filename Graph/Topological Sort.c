#include<stdio.h>
#include<stdlib.h>

#define N 8

int visited[N] = {0,0,0,0,0,0,0,0}, arr[N], k=0;

/*
    directed graph

            0
           /|
          / |
         /  |
        1---3---2
           / \
          /   \
         6     4
         |
         |
         5---7
*/

int graph[N][N] =
{
    {0,0,0,1,0,0,0,0},
    {1,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,1,0,1,0,0},
    {0,0,0,0,0,1,0,0}
};

void DFS(int i)
{
    visited[i] = 1;

    for(int j=0; j<N; j++)
    {
        if(graph[i][j]==1 && !visited[j])
        {
            DFS(j);
        }
    }

    arr[k++] = i;
}

int main()
{
    int i;

    DFS(1);
    DFS(6);
    DFS(7);

    printf("Topological sort: ");

    for(i=k-1; i>=0; i--)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}

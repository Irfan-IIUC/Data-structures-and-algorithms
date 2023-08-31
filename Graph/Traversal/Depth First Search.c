#include<stdio.h>

#define N 7

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

void DFS(int i)
{
    printf("%d ", i);
    visited[i] = 1;

    for(int j=0; j<N; j++)
    {
        if(graph[i][j]==1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    // DFS Implementation (start with node 0)

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

    printf("Depth-First Search traversal: ");
    DFS(0);
    printf("\n");

    return 0;
}

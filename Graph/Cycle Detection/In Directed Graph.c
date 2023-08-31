#include<stdio.h>

#define N 5

/*
    flag -1 = unvisited
    flag  0 = visited
    flag  1 = popped from stack
*/

int visited[N] = {0,0,0,0,0}, flag[N] = {-1,-1,-1,-1,-1};
int graph[N][N] =
{
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
};

void DFS(int i)
{
    visited[i] = 1;
    flag[i] = 0;

    for(int j=0; j<N; j++)
    {
        if(graph[i][j]==1 && !visited[j])
            DFS(j);
        else if(graph[i][j]==1 && flag[j]==0)
            printf("Graph has a cycle!\n");
    }

    flag[i] = 1;
}

int main()
{
    /*
           1------3
          /|\     |
         / | \    |
        0  |  \   |
         \ |   \  |
          \|    \ |
           2      4
    */

    DFS(0); // start with node 0

    return 0;
}

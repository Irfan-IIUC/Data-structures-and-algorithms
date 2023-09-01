#include<stdio.h>

#define N 9

int visited[N] = {0,0,0,0,0,0,0,0,0}, cnt=0, node=0;

/*
    undirected graph

        1
       / \                  6-----7
      /   \                  \   /
     0     2    4-----5       \ /
      \   /                    8
       \ /
        3
*/

int graph[N][N] =
{
    {0,1,0,1,0,0,0,0,0},
    {1,0,1,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,0,0},
    {1,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0},
    {0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,1,1},
    {0,0,0,0,0,0,1,0,1},
    {0,0,0,0,0,0,1,1,0}
};

void DFS(int node)
{
    visited[node] = 1;

    for(int j=0; j<N; j++)
    {
        if(graph[node][j]==1 && !visited[j])
        {
            DFS(j);
        }
    }
}

void connected_components(int graph[N][N])
{
    while(node < N)
    {
        if(!visited[node])
        {
            DFS(node);
            cnt++;
        }

        node++;
    }
}

int main()
{
    connected_components(graph);
    printf("There are %d connected components in the graph!\n", cnt);

    return 0;
}

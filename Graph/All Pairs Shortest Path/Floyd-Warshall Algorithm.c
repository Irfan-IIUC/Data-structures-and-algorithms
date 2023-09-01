#include <stdio.h>

#define V 4
#define INF 9999999

void display(int matrix[V][V])
{
    int i, j;

    printf("All Pair shortest path ->\n");

    for(i=0; i<V; i++)
    {
        for(j=0; j<V; j++)
            printf("%4d", matrix[i][j]);

        printf("\n");
    }
}

void floydWarshall(int graph[][V])
{
    int i, j, k;

    for(k=0; k<V; k++)
    {
        for(i=0; i<V; i++)
        {
            for(j=0; j<V; j++)
            {
                if((graph[i][k] + graph[k][j]) < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    display(graph);
}

int main()
{
    /*
        directed graph

           8
        0-----1
        |\1  /|
        | \ / |
       4|  /  |2
        | / \ |
        |/1  \|
        2-----3
           9
    */

    int graph[V][V] =
    {
        {0, 8, INF, 1},
        {INF, 0, 1, INF},
        {4, INF, 0, INF},
        {INF, 2, 9, 0}
    };


    floydWarshall(graph);
}

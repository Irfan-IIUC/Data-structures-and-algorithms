#include<stdio.h>

#define INFINITY 9999999
#define MAX 5

void dijkstra(int graph[MAX][MAX], int n, int startnode)
{
    int cost[MAX][MAX], distance[MAX], visited[MAX], cnt, minDistance, nextnode, i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = graph[i][j];
        }
    }

    for(i=0; i<n; i++)
    {
        distance[i] = cost[startnode][i];
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    cnt = 1;

    while(cnt < n-1)
    {
        minDistance = INFINITY;

        for(i=0; i<n; i++)
        {
            if((distance[i] < minDistance) && (!visited[i]))
            {
                minDistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode]=1;

        for(i=0; i<n; i++)
        {
            if(!visited[i])
            {
                if((minDistance + cost[nextnode][i]) < distance[i])
                {
                    distance[i] = minDistance + cost[nextnode][i];
                }
            }
        }

        cnt++;
    }

    // print distance matrix
    printf("Distance from source to all nodes: ");
    for(i=0; i<n; i++)
        printf("%d ", distance[i]);
}

int main()
{
    int n=5, u=0; // n = vertices, u = starting node

    /*
             9
         0 ----- 1
         |      /|\
         |     / | \42
         |  95/  |  \
        75|   /   |   4
         |  /  19|  / \
         | /     | /31 \
         |/      |/    /
         2 ----- 3    /
         \   51      /
          \ _______ /66
    */

    int graph[5][5] =
    {
        {0, 9, 75, 0, 0},
        {9, 0, 95, 19, 42},
        {75, 95, 0, 51, 66},
        {0, 19, 51, 0, 31},
        {0, 42, 66, 31, 0}
    };

    dijkstra(graph, n, u);
    printf("\n");

    return 0;
}

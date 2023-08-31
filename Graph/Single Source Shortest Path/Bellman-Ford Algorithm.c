#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999999

struct Edge
{
    int u;
    int v;
    int w;
};

struct Graph
{
    int V, E;
    struct Edge *edge;  //array of edges
};

void bellmanford(struct Graph* g, int source)
{
    int i, j, u, v, w;

    // total vertex in the graph g
    int tV = g->V;

    //total edge in the graph g
    int tE = g->E;

    int distance[tV];

    // step 1: fill the distance array with infinity
    for(i=0; i<tV; i++)
        distance[i] = INFINITY;

    distance[source] = 0;

    // step 2: relax edges |V| - 1 times
    for(i=1; i<=tV-1; i++)
    {
        for(j=0; j<tE; j++)
        {
            u = g->edge[j].u;
            v = g->edge[j].v;
            w = g->edge[j].w;

            if((distance[u] != INFINITY) && (distance[v] > distance[u] + w))
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    // step 3: detect negative cycle
    for(i=0; i<tE; i++)
    {
        u = g->edge[i].u;
        v = g->edge[i].v;
        w = g->edge[i].w;

        if((distance[u] != INFINITY) && (distance[v] > distance[u] + w))
        {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    // no negative weight cycle found!
    printf("\nDistance from source to all nodes: ");
    for(i=0; i<tV; i++)
        printf("%d ", distance[i]);
}

int main()
{
    /*
             9
         0 ----- 1
         |      /|\
         |     / | \42
         |  95/  |  \
        7|   /   |   4
         |  /  19|  / \
         | /     | /31 \
         |/      |/    /
         2 ----- 3    /
         \   51      /
          \ _______ /66
    */

    int i;
    struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));

    g->V = 5;
    g->E = 8;

    //array of edges for graph
    g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));

    printf("Enter all the edges [u, v, w] ->\n");

    for(i=0; i<g->E; i++)
        scanf("%d %d %d", &g->edge[i].u, &g->edge[i].v, &g->edge[i].w);

    bellmanford(g, 0);  //0 is the source vertex
    printf("\n");

    return 0;
}

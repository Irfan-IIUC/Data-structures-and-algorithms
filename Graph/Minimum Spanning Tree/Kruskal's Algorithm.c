#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int src, dest, weight;
};

// structure to represent a subset for Union-Find
struct Subset
{
    int parent;
    int rank;
};

struct Edge* createGraph(int V, int E)
{
    struct Edge* graph = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// function to find the parent of a vertex using Union-Find
int findParent(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = findParent(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// function to perform Union of two subsets
void unionSets(struct Subset subsets[], int x, int y)
{
    int xroot = findParent(subsets, x);
    int yroot = findParent(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// function to implement Kruskal's algorithm
void kruskalMST(struct Edge* graph, int V, int E)
{
    int i, j;

    // step 1: Sort all the edges in non-decreasing order of their weight
    for(i=1; i<E; i++)
    {
        for(j=0; j<E-i; j++)
        {
            if(graph[j].weight > graph[j + 1].weight)
            {
                struct Edge temp = graph[j];
                graph[j] = graph[j + 1];
                graph[j + 1] = temp;
            }
        }
    }

    // allocate memory for creating V subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // initialize subsets with single elements
    for(i=0; i<V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int mstWeight = 0;
    printf("\nEdges in the MST ->\n");

    // step 2: Pick the smallest edge and check if it forms a cycle
    for(i=0; i<E; i++)
    {
        int srcParent = findParent(subsets, graph[i].src);
        int destParent = findParent(subsets, graph[i].dest);

        if(srcParent != destParent)
        {
            // include the edge in the MST
            printf("(%d - %d) with weight %d\n", graph[i].src, graph[i].dest, graph[i].weight);
            mstWeight += graph[i].weight;
            unionSets(subsets, srcParent, destParent);
        }
    }

    printf("\nTotal weight of the MST: %d\n", mstWeight);
    free(subsets);
}

int main()
{
    int i, V, E;

    printf("Enter the number of vertices and edges in the graph: ");
    scanf("%d %d", &V, &E);

    struct Edge* graph = createGraph(V, E);

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

    printf("\nEnter the source, destination, and weight of each edge:\n");
    for(i=0; i<E; i++)
    {
        scanf("%d %d %d", &graph[i].src, &graph[i].dest, &graph[i].weight);
    }

    kruskalMST(graph, V, E);
    free(graph);

    return 0;
}

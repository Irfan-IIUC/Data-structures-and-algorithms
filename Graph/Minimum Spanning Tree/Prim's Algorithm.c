#include<stdio.h>
#include<string.h>

#define INF 9999999
#define V 5

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

int graph[V][V] =
{
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}
};

int main()
{
    int no_edge=0, selected[V], x, y, min, i, j, cost=0;

    // set selected false initially
    memset(selected, 0, sizeof(selected));
    selected[0] = 1;

    printf("Edge : Weight\n\n");

    while(no_edge < V-1)
    {
        min = INF;
        x = 0;
        y = 0;

        for(i=0; i<V; i++)
        {
            if(selected[i])
            {
                for(j=0; j<V; j++)
                {
                    if(!selected[j] && graph[i][j]) // not in selected and there is an edge
                    {
                        if(min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);
        selected[y] = 1;
        cost += graph[x][y];

        no_edge++;
    }

    printf("\nTotal cost of this MST = %d\n", cost);

    return 0;
}

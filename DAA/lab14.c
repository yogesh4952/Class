#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge
{
    int u, v, w;
};

int parent[MAX];

// Find function (with path compression)
int find(int i)
{
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

// Union function
void unionSet(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

// Sort edges by weight
void sortEdges(struct Edge edges[], int E)
{
    struct Edge temp;
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Initialize parent array
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges
    sortEdges(edges, E);

    int count = 0, totalCost = 0;

    printf("\nEdges in MST:\n");

    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v))
        {
            printf("%d - %d : %d\n", u, v, edges[i].w);
            totalCost += edges[i].w;
            unionSet(u, v);
            count++;
        }
    }

    printf("Total cost of MST = %d\n", totalCost);

    return 0;
}
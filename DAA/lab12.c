#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5 // Number of vertices

int minDistance(int dist[], bool visited[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main()
{
    int graph[V][V];
    int src;

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex (0-%d): ", V - 1);
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
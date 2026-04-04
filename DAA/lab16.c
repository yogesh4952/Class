#include <stdio.h>

#define INF 99999
#define MAX 10

int main()
{
    int n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX], dist[MAX][MAX];

    printf("Enter adjacency matrix (use %d for no edge):\n", INF);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nShortest distance matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
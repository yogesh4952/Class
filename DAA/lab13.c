#include <stdio.h>
#include <limits.h>

#define MAX 10

int m[MAX][MAX];
int s[MAX][MAX];

// Function to print optimal parenthesization
void printOptimal(int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        printOptimal(i, s[i][j]);
        printOptimal(s[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n)
{
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    for (int L = 2; L <= n; L++)
    {
        for (int i = 1; i <= n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];

    printf("Enter dimensions array:\n");
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    matrixChainOrder(p, n);

    printf("\nMinimum number of multiplications: %d\n", m[1][n]);

    printf("Optimal parenthesization: ");
    printOptimal(1, n);

    return 0;
}
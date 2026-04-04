#include <stdio.h>

// Structure to store item details
struct Item
{
    int weight;
    int value;
    float ratio;
};

// Function to sort items based on ratio (descending)
void sortItems(struct Item items[], int n)
{
    struct Item temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input weights and values
    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort items by ratio
    sortItems(items, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            // Take full item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            // Take fraction of item
            totalValue += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);

    return 0;
}


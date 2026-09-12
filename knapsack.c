#include <stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

int main()
{
    int n, capacity;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and profit:\n");
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    for ( i = 0; i < n - 1; i++)
    {
        for ( j = i + 1; j < n; j++)
        {
            if (items[i].ratio < items[j].ratio)
            {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    int remaining = capacity;

    for ( i = 0; i < n; i++)
    {
        if (items[i].weight <= remaining)
        {
            totalProfit += items[i].profit;
            remaining -= items[i].weight;
        }
        else
        {
            totalProfit += items[i].ratio * remaining;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int weight;
} Item;

int compare(const void *a, const void *b)
{
    double r1 = ((Item *)a)->value / ((Item *)a)->weight;
    double r2 = ((Item *)b)->value / ((Item *)b)->weight;

    if (r1 > r2)
        return -1; // Sort in descending order
    if (r1 < r2)
        return 1;
    return 0;
}

double knapsack(Item items[], int w, int n)
{
    qsort(items, n, sizeof(Item), compare);

    double max = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= w)
        {
            max += items[i].value;
            w -= items[i].weight;
            printf("\nmax = %.2lf , w = %d",max,w);
        }
        else
        {
            max += items[i].value * ((double)w / (double)items[i].weight);
            printf("\nmax = %.2lf , w = %d",max,w);
            break;
        }
    }
    return max;
}

int main()
{
    int n, w;
    printf("Enter the total no of items : ");
    scanf("%d", &n);
    Item items[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the weight for %d item : ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the weight : ");
    scanf("%d", &w);

    double maxValue = knapsack(items, w, n);
    printf("Max value in the knapsack %.2lf: ", maxValue);

    return 0;
}
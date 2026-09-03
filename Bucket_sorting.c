#include <stdio.h>

void bucketSort(int a[], int n)
{
    int bucket[100][100];
    int count[100] = {0};
    int i, j, k, index, temp;

    for (i = 0; i < n; i++)
    {
        index = a[i] / 10;
        bucket[index][count[index]++] = a[i];
    }

    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < count[i] - 1; j++)
        {
            for (k = j + 1; k < count[i]; k++)
            {
                if (bucket[i][j] > bucket[i][k])
                {
                    temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
        }
    }

    k = 0;

    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < count[i]; j++)
            a[k++] = bucket[i][j];
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter non-negative elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bucketSort(a, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

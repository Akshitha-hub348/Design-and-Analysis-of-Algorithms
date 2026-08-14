#include <stdio.h>
#include <limits.h>

int main()
{
    int n, k, i, j;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of K: ");
    scanf("%d", &k);

    int smallest;

    for (i = 0; i < k; i++)
    {
        smallest = INT_MAX;
        int index = -1;

        for (j = 0; j < n; j++)
        {
            if (arr[j] < smallest)
            {
                smallest = arr[j];
                index = j;
            }
        }

        arr[index] = INT_MAX;
    }

    printf("The %dth smallest element is %d", k, smallest);

    return 0;
}

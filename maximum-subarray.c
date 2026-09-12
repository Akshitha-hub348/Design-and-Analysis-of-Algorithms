#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int crossSum(int a[], int low, int mid, int high)
{
    int sum = 0;
    int left = a[mid];
    int right = a[mid + 1];
int i;
    for ( i = mid; i >= low; i--)
    {
        sum = sum + a[i];

        if (sum > left)
            left = sum;
    }

    sum = 0;

    for (i = mid + 1; i <= high; i++)
    {
        sum = sum + a[i];

        if (sum > right)
            right = sum;
    }

    return left + right;
}

int maxSubarray(int a[], int low, int high)
{
    if (low == high)
        return a[low];

    int mid = (low + high) / 2;

    int left = maxSubarray(a, low, mid);
    int right = maxSubarray(a, mid + 1, high);
    int cross = crossSum(a, low, mid, high);

    return max(max(left, right), cross);
}

int main()
{
    int n;
    int i;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements:\n", n);

    for ( i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Maximum subarray sum = %d",
           maxSubarray(a, 0, n - 1));

    return 0;
}
 

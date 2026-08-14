#include <stdio.h>

int main()
{
    int a, r, n, i;
    int sum = 0;

    printf("Enter the first term: ");
    scanf("%d", &a);

    printf("Enter the common ratio: ");
    scanf("%d", &r);

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum = sum + a;
        a = a * r;
    }

    printf("Sum of the geometric series = %d\n", sum);

    return 0;
}

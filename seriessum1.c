#include <stdio.h>
#include <math.h>

int main()
{
    int a, r, n;
    double sum;

    printf("Enter the first term: ");
    scanf("%d", &a);

    printf("Enter the common ratio: ");
    scanf("%d", &r);

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (r == 1)
    {
        sum = a * n;
    }
    else
    {
        sum = (a * (pow(r, n) - 1)) / (r - 1);
    }

    printf("Sum of the geometric series = %.2f\n", sum);

    return 0;
}

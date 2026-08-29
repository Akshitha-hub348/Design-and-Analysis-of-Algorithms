#include <stdio.h>

int main()
{
    int a[100], n, T;
    int i, complement;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &T);

    int hash[201] = {0};

    for(i = 0; i < n; i++)
    {
        complement = T - a[i];

        if(complement >= -100 && complement <= 100 &&
           hash[complement + 100] == 1)
        {
            printf("Yes, two elements exist whose sum is %d.\n", T);
            printf("Elements are %d and %d.\n", complement, a[i]);
            found = 1;
            break;
        }

        if(a[i] >= -100 && a[i] <= 100)
            hash[a[i] + 100] = 1;
    }

    if(found == 0)
        printf("No, such two elements do not exist.\n");

    return 0;
}

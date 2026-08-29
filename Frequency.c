#include <stdio.h>

int main()
{
    int a[100], hash[201] = {0};
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        hash[a[i] + 100]++;
    }

    printf("Frequency of each distinct element:\n");

    for(i = 0; i < n; i++)
    {
        if(hash[a[i] + 100] != 0)
        {
            printf("%d : %d\n", a[i], hash[a[i] + 100]);
            hash[a[i] + 100] = 0;
        }
    }

    return 0;
}

#include <stdio.h>

void towerOfHanoi(int n)
{
    int moves = (1 << n) - 1;
    int i;
    char source = 'A', auxiliary = 'B', destination = 'C';

    if (n % 2 == 0)
    {
        char temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }

    for ( i = 1; i <= moves; i++)
    {
        if (i % 3 == 1)
            printf("Move disk from %c to %c\n", source, destination);
        else if (i % 3 == 2)
            printf("Move disk from %c to %c\n", source, auxiliary);
        else
            printf("Move disk from %c to %c\n", auxiliary, destination);
    }
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n);

    return 0;
} 

#include <stdio.h>
#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

void insert(int table[], int key)
{
    int index, i = 0;

    index = hash(key);

    while (table[(index + i * i) % SIZE] != -1)
    {
        i++;

        if (i == SIZE)
        {
            printf("Hash table is full\n");
            return;
        }
    }

    table[(index + i * i) % SIZE] = key;
}

void display(int table[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        if (table[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, table[i]);
    }
}

int main()
{
    int table[SIZE];
    int i, key;

    for (i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter 5 keys:\n");

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &key);
        insert(table, key);
    }

    printf("\nHash Table:\n");
    display(table);

    return 0;
} 

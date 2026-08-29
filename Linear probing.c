#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];


void initialize()
{
    int i;
	for ( i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

void insert(int value)
{
    int index = value % SIZE;

   
    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = value;
}


void search(int value)
{
    int index = value % SIZE;
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == value)
        {
            printf("%d found at index %d\n", value, index);
            return;
        }

        index = (index + 1) % SIZE;

       
        if (index == start)
        {
            break;
        }
    }

    printf("%d not found\n", value);
}


void display()
{
    printf("\nHash Table:\n");

    int i;
    for ( i = 0; i < SIZE; i++)
    {
        printf("Index %d : %d\n", i, hashTable[i]);
    }
}

int main()
{
    initialize();

    insert(10);
    insert(20);
    insert(25);
    insert(35);
    insert(15);

    display();

    search(25);
    search(50);

    return 0;
} 

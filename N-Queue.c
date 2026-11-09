
#include <stdio.h>
#include <stdlib.h>

int board[20][20];
int n;

int isSafe(int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col] == 1)
            return 0;

    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return 0;

    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return 0;

    return 1;
}

void printBoard()
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", board[i][j]);

        printf("\n");
    }

    printf("\n");
}

int solveNQueen(int row)
{
    int col;

    if (row == n)
    {
        printBoard();
        return 1;
    }

    int found = 0;

    for (col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            found = solveNQueen(row + 1) || found;

            board[row][col] = 0;
        }
    }

    return found;
}

int main()
{
    int i, j;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Invalid input");
        return 0;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            board[i][j] = 0;

    if (!solveNQueen(0))
        printf("No solution exists");

    return 0;
}

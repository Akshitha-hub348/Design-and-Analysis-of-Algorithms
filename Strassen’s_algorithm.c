#include <stdio.h>

int main()
{
    int A[2][2], B[2][2], C[2][2];
    int M1, M2, M3, M4, M5, M6, M7;

    printf("Enter elements of Matrix A:\n");
int i;
int j;
    for ( i = 0; i < 2; i++)
        for ( j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");

    for ( i = 0; i < 2; i++)
        for ( j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    int a = A[0][0];
    int b = A[0][1];
    int c = A[1][0];
    int d = A[1][1];

    int e = B[0][0];
    int f = B[0][1];
    int g = B[1][0];
    int h = B[1][1];

    M1 = (a + d) * (e + h);
    M2 = (c + d) * e;
    M3 = a * (f - h);
    M4 = d * (g - e);
    M5 = (a + b) * h;
    M6 = (c - a) * (e + f);
    M7 = (b - d) * (g + h);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;

    printf("Result Matrix:\n");

    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 2; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}

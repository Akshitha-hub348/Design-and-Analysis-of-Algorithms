#include <stdio.h>
#include <limits.h>
void printOptimalParenthesis(int i, int j, int n, int s[][n], char *name) {
    if (i == j) {
        printf("%c%d", *name, i);
        return;
    }
    printf("(");
    printOptimalParenthesis(i, s[i][j], n, s, name);
    printOptimalParenthesis(s[i][j] + 1, j, n, s, name);
    printf(")");
}

void matrixChainOrder(int p[], int n) {
    int dp[n][n];
    int s[n][n];
    int i;
    int L,k;

    for ( i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    for ( L = 2; L < n; L++) {
        for ( i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            for ( k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications: %d\n", dp[1][n - 1]);
    
    printf("Optimal Parenthesization: ");
    char matrixName = 'A';
    printOptimalParenthesis(1, n - 1, n, s, &matrixName);
    printf("\n");
}

int main() {
    int p[] = {40, 20, 30, 10, 30};
    int size = sizeof(p) / sizeof(p[0]);

    matrixChainOrder(p, size);

    return 0;
}

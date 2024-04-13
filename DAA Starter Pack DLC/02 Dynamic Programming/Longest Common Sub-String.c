#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void longestString(int **dp, int a, int b, char *x, char *y) {
    int i = a;
    int j = b;
    int index = dp[a][b];
    char str[100];
    str[index] = '\0';

    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            str[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    printf("The string is:");
    for (int i = 0; i < strlen(str); i++)
    {
        printf(" %c",str[i]);
    }
    
}

int **len_lcs(char *x, char *y, int a, int b) {
    int **dp = (int **)malloc((a + 1) * sizeof(int *));
    int i, j;

    // build the dynamic programming table
    for (i = 0; i <= a; i++) {
        dp[i] = (int *)malloc((b + 1) * sizeof(int));
        for (j = 0; j <= b; j++) {
            if (i == 0 || j == 0) {
                // set 0th row and column to 0
                dp[i][j] = 0;
            } else if (x[i - 1] == y[j - 1]) {
                // if both char are equal, add 1 to count, count is available at diagnol, dp[i-1][j-1]
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // if both char not equal, value is max of element on top and element to left of current
                int p = dp[i - 1][j];
                int q = dp[i][j - 1];
                dp[i][j] = (p > q) ? p : q;
            }
        }
    }
    return dp;
}

int main() {
    int n, m;
    printf("Enter length of strings:");
    scanf("%d %d", &n, &m);

    char a[1000], b[1000];
    //"abcbadd"
    //"bdcbaa"
    printf("Enter the 2 strings to check: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf(" %c", &b[i]);
    }
    printf("Sequence A: ");
    for (int i = 0; i < n; i++) {
        printf("%c", a[i]);
    }
    printf("\n");

    printf("Sequence B: ");
    for (int i = 0; i < m; i++) {
        printf("%c", b[i]);
    }
    printf("\n");
// inout handled, now main code
    int lena = strlen(a);
    int lenb = strlen(b);
    int **dp = len_lcs(a, b, lena, lenb);
    printf("The LCS length is : %d\n", dp[lena][lenb]);
    longestString(dp, lena, lenb, a, b);

    // Free mem
    for (int i = 0; i <= lena; i++) {
        free(dp[i]);
    }
    free(dp);
    printf("\n22BCE3789 - Deep Mukesh Jiwan 2024");
    return 0;
}

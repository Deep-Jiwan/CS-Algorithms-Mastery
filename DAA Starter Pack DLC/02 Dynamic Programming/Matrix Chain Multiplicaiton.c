#include<stdio.h>
#include<limits.h>

#define MAX_SIZE 10
void printOptimalPrarens(int i,int j,int n, int *bracket,char name){
    if(i==j){
        printf("%c%d", name,i);
        return;
    }
    printf("(");
    printOptimalPrarens(i,*((bracket + i*n)+j),n,bracket,name);
    printOptimalPrarens(*((bracket + i*n)+j)+1,j,n,bracket,name);
    printf(")");
}

int minMatrixMultiplicationCount(int p[], int n){
    int m[n][n];
    int bracket[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    printf("Optimal Parenthesization is: ");
    printOptimalPrarens(1,n-1,n,(int*)bracket,'A');
    return (m[1][n-1]);
}

int main() {
    int n=4;
    int arr[MAX_SIZE];
    printf("The total number of matrices are: %d",n);
    printf("\nEnter size of %d matrices: ",n);
    for(int i=0; i<n ; i++){
        scanf(" %d",&arr[i]);
    }
    for(int i=0; i<n ; i++){
        printf("%d",arr[i]);
    }

    printf("\nMinimum number of multiplications is %d\n", minMatrixMultiplicationCount(arr, n));
    printf("\n22BCE3789 - Deep Mukesh Jiwan 2024");
    return 0;
}

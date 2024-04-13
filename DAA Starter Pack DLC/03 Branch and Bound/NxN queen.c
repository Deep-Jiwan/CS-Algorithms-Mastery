#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printBoard(int **board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int **board, int N, int row, int col) {
    int i, j;

    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

void solveNQueens(int **board, int N, int col, int *count) {
    if (col >= N) {
        (*count)++;
        printf("Solution %d:\n", *count);
        printBoard(board, N);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, N, i, col)) {
            board[i][col] = 1;
            solveNQueens(board, N, col + 1, count);
            board[i][col] = 0;
        }
    }
}

int main() {
    int N;
    printf("Enter the size of the board: ");
    scanf("%d", &N);

    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        board[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    int count = 0;
    solveNQueens(board, N, 0, &count);
    printf("Total solutions: %d\n", count);

    for (int i = 0; i < N; i++) {
        free(board[i]);
    }
    free(board);
    printf("\n22BCE3789 - Deep Mukesh Jiwan 2024");
    return 0;
}

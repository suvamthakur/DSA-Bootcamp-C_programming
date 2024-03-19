#include <stdio.h>
#include <stdbool.h>

int n;
int board[50][50] = {0};

bool is_safe(int board[][50], int row, int col) {
    int i, j;

    for (i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }
    for (i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

void printSol() {
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool Nqueen(int board[][50], int row) {
    if (row == n) {
        printSol();
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col)) {
            board[row][col] = 1;
            if (Nqueen(board, row + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    printf("\nEnter the number of queens (n): ");
    scanf("%d", &n);
    if (!Nqueen(board, 0)) {
        printf("\nNo solution exists for %d queens.\n", n);
    }
    return 0;
}

#include <stdio.h>
#include <math.h>

int board[20], n;

int safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void backtrack(int row) {
    if (row == n) {
        for (int i = 0; i < n; i++)
            printf("%d ", board[i]);
        printf("\n");
        return;
    }

    for (int col = 0; col < n; col++) {
        if (safe(row, col)) {
            board[row] = col;
            backtrack(row + 1);
        }
    }
}

int main() {
    printf("Enter N: ");
    scanf("%d", &n);
    backtrack(0);
    return 0;
}

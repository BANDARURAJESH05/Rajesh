#include <stdio.h>

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int player = 1, moves = 0;  // Track the number of moves
char mark;

void displayBoard() {
    printf("\n %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkWin() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

void playGame() {
    int move;
    while (1) {
        displayBoard();
        printf("\nPlayer %d, enter position: ", player);
        scanf("%d", &move);

        if (move < 1 || move > 9) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already taken! Try again.\n");
            continue;
        }

        mark = (player == 1) ? 'X' : 'O';
        board[row][col] = mark;
        moves++;

        if (checkWin()) {
            displayBoard();
            printf("\nPlayer %d wins!\n", player);
            return;
        }

        if (moves == 9) {
            displayBoard();
            printf("\nIt's a Draw!\n");
            return;
        }

        player = (player == 1) ? 2 : 1;
    }
}

int main() {
    playGame();
    return 0;
}

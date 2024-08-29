#include <stdio.h>

char board[3][3];
char current_player;

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i;
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
}

int check_winner() {
    int i;

    // Cek baris
    for (i = 0; i < 3; i++) {
        if (board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player) {
            return 1;
        }
    }

    // Cek kolom
    for (i = 0; i < 3; i++) {
        if (board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player) {
            return 1;
        }
    }

    // Cek diagonal
    if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player) {
        return 1;
    }
    if (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player) {
        return 1;
    }

    return 0;
}

int is_draw() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void switch_player() {
    if (current_player == 'X') {
        current_player = 'O';
    } else {
        current_player = 'X';
    }
}

void play_game() {
    int row, col;

    while (1) {
        print_board();
        printf("Giliran %c, masukkan baris dan kolom (0, 1, atau 2):\n", current_player);
        printf("Baris: ");
        scanf("%d", &row);
        printf("Kolom: ");
        scanf("%d", &col);

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = current_player;
            if (check_winner()) {
                print_board();
                printf("Pemain %c menang!\n", current_player);
                break;
            }
            if (is_draw()) {
                print_board();
                printf("Permainan seri!\n");
                break;
            }
            switch_player();
        } else {
            printf("Posisi tidak valid, coba lagi.\n");
        }
    }
}

int main() {
    current_player = 'X';
    initialize_board();
    play_game();
    return 0;
}
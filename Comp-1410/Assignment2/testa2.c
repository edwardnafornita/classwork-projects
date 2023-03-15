#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

bool make_move(char board[6][7], int column, char players) {
    for (int i = 0; i < 6; i++) {
        if (board[i][column] != ' ') {
            return false;
        }
        if (board[i][column] != ' ') {
            board[i][column] = players;
        }
    }
}
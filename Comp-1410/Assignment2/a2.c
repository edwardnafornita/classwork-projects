/* ===========================================================================
COMP-1410 Assignment 2 - Edward Nafornita (110076381)
=========================================================================== */

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// print_player(counter) will display a message indicating who's turn it is
char print_player(char *player, int counter) {
    if (counter % 2 == 0) {
        return player[0];
    }
    else {
        return player[1];
    }
}

// print_choice(player, counter) will take in the player and a counting variable
//     and will check if the counting variable is either even or odd.
//     An even count, means that it is player X's turn whereas, an odd count
//     implies it's player O's turn.
// This will update the board to reflect the current state of the player.
// requires: player
//           counter variable
//           the board and the current position in the board (m x n)
void print_choice(char board[6][7], int m, int n, char *player, int *counter) {
    if (*counter % 2 == 0) {
        board[m][n] = player[0]; 
        *counter += 1;
    }
    else {
        board[m][n] = player[1];
        *counter += 1;
    }
}

// print_board(board) will print out the board status everytime this function
//  is called.
void print_board(char board[6][7]) {
    printf("  1   2   3   4   5   6   7  \n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
}

// make_move(board, column, player) updates the board following a move
//   by the given player in the given column; returns false if the move
//   was illegal because the column was full
// requires: 0 <= column < 7
//           player is either 'X' or 'O'
bool make_move(char board[6][7], int column, char *player, int *counter) {
    for (int i = 6; i >= 0; i--) {
        if (board[i][column - 1] == ' ') {
            print_choice(board, i, (column - 1), &player[0], counter);
            print_board(board);
            return true;
        }
    }
    
    printf("Column full! Please select a different column\n");
    return false;
}

// if_full(board) checks if the board has no more possible moves
//      ie. there are no more blank spaces in the board
bool if_full(char board[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] != ' ') {
            }
            else {
                return false;
            }
        }
    }

    printf("Tie Game. Board is full.\n");
    return true;
}

// check_win(board) returns true if the given player has 4 connected
//   pieces on the board
bool check_win(char board[6][7], char *player) {
    if (!if_full(board)) {
        int xWin = 0;
        int oWin = 0;

        // horizontal check
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                xWin = 0;
                oWin = 0;

                for (int k = 0; k < 4; k++) {
                    if (board[i][j + k] == player[0]) {
                        xWin++;
                    }
                    if (board[i][j + k] == player[1]) {
                        oWin++;
                    }
                }
                
                if (xWin == 4) {
                    printf("Player X won!\n");
                    return true;
                }
                if (oWin == 4) {
                    printf("Player O won!\n");
                    return true;
                }
            }
        }

        // vertical check
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                xWin = 0;
                oWin = 0;

                for (int k = 0; k < 4; k++) {
                    if (board[i + k][j] == player[0]) {
                        xWin++;
                    }
                    if (board[i + k][j] == player[1]) {
                        oWin++;
                    }
                }

                if (xWin == 4) {
                    printf("Player X won!\n");
                    return true;
                }
                if (oWin == 4) {
                    printf("Player O won!\n");
                    return true;
                }
            }
        }

    // right-down diagonal check
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                xWin = 0;
                oWin = 0;
                
                for (int k = 0; k < 4; k++) {
                    if (board[i + k][j + k] == player[0]) {
                        xWin++;
                    }
                    if (board[i + k][j + k] == player[1]) {
                        oWin++;
                    }
                }

                if (xWin == 4) {
                    printf("Player X won!\n");
                    return true;
                }
                if (oWin == 4) {
                    printf("Player O won!\n");
                    return true;
                }
            }
        } 

        // left-down diagonal check
        for (int i = 0; i < 5; i++) {
            for (int j = 7; j > 1; j--) {
                xWin = 0;
                oWin = 0;
                
                for (int k = 0; k < 4; k++) {
                    if (board[i + k][j - k] == player[0]) {
                        xWin++;
                    }
                    if (board[i + k][j - k] == player[1]) {
                        oWin++;
                    }
                }

                if (xWin == 4) {
                    printf("Player X won!\n");
                    return true;
                }
                if (oWin == 4) {
                    printf("Player O won!\n");
                    return true;
                }
            }
        }

        return false;
    }
    else {return false;}
}

// first_capital(str, n) returns the first capital letter in str;
//   returns 0 if str contains no capital letters
// requires: str is a string of length n
//           str contains only lower-case and upper-case letters
//           all lower-case letters appear before upper-case letters
char first_capital(const char str[], int n) {
    for (int i = 0; i < n; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            return str[i];
        }
    }

    return 0;
}

// deepest_substring(str, out) updates out to be the deepest substring of
//   str; the first is used if multiple possibilities exist
// requires:
//   str is a string with balanced parenthesis
//   out points to enough memory to store the deepest substring of str
void deepest_substring(const char str[], char out[]) {
    int n = strlen(str);
    int count = 0, greatestCount = 0, pos = 0, arrPos = 0;
    bool check = false;

    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            count++;
            if (count > greatestCount) {
                greatestCount = count;
                pos = i;
            }
        }
        if (str[i] == ')') {
            count--;
        }
    }
    
    if (greatestCount == 0) {
        strcpy(out, str);
        check = true;
    }

    for (int i = (pos + 1); i < n; i++) {
        if (check == true) {
            break;
        }
        else if (str[i] == ')') {
            break;
        }
        else {
            out[arrPos] = str[i];
            arrPos++;
        }
    }
}

int main(void) {
    char board[6][7] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    print_board(board);
    int column, counter = 0;
    char player[3] = "XO";

    while (true) {
        if ((check_win(board, &player[0]) == false) && (if_full(board) == false)) {
            printf("Player %c, choose a column: \n", print_player(&player[0], counter));
            scanf("%d", &column);

            if (column >= 1 && column <= 7) {
                make_move(board, column, &player[0], &counter);
            }
            else {
                puts("Please enter a valid column number!");
            }
        }
        else {
            break;
        }
    }
    puts("");

    char board1[6][7] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'X', ' ', ' ', ' ', ' ', ' ', ' '},
        {'X', 'O', ' ', ' ', ' ', ' ', ' '},
        {'X', 'O', ' ', ' ', ' ', ' ', ' '},
        {'X', 'O', ' ', ' ', ' ', ' ', ' '}
    };
    puts("Board Test 1: ");
    assert(check_win(board1, &player[0]) == true);
    puts("");

    char board2[6][7] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'O', 'O', 'O', 'O', ' '},
        {' ', ' ', 'X', 'X', 'X', 'O', ' '},
        {' ', ' ', 'O', 'O', 'O', 'X', 'X'},
        {' ', ' ', 'X', 'X', 'X', 'O', 'X'}
    };
    puts("Board Test 2:");
    assert(check_win(board2, &player[0]) == true);
    puts("");

    char board3[6][7] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'O', ' ', ' ', ' ', ' ', ' ', ' '},
        {'X', 'O', ' ', ' ', ' ', ' ', ' '},
        {'O', 'O', 'O', ' ', 'X', ' ', ' '},
        {'X', 'X', 'X', 'O', 'X', ' ', ' '}
    };
    puts("Board Test 3:");
    assert(check_win(board3, &player[0]) == true);
    puts("");

    char board4[6][7] = {
        {'O', 'O', 'O', 'X', 'O', 'O', 'O'},
        {'X', 'X', 'X', 'O', 'X', 'X', 'X'},
        {'O', 'O', 'O', 'X', 'O', 'O', 'O'},
        {'X', 'X', 'X', 'O', 'X', 'X', 'X'},
        {'O', 'O', 'O', 'X', 'O', 'O', 'O'},
        {'X', 'X', 'X', 'O', 'X', 'X', 'X'}
    };
    puts("Board Test 4:");
    assert(check_win(board4, &player[0]) == false);
    puts("");

    char str1[6] = "lauGH";
    assert(first_capital(str1, 6) == 'G');

    char str2[16] = "computerscience";
    assert(first_capital(str2, 16) == 0);

    char str3[20] = "nkfdstuyekgdsKJFDJ";
    assert(first_capital(str3, 20) == 'K');

    char str4[11] = "HFDJKTJERJ";
    assert(first_capital(str4, 11) == 'H');

    char str5[2] = " ";
    assert(first_capital(str5, 2) == 0);

    char substrTest[12] = "a+((b+c)+d)";
    char out[12] = " ";
    char check1[12] = "b+c";
    deepest_substring(&substrTest[0], &out[0]);
    assert(strcmp(out, check1) == 0);

    char substrTest2[20] = "(a+b)(((c+d+e)))(f)";
    char out2[20] = "";
    char check2[20] = "c+d+e";
    deepest_substring(&substrTest2[0], &out2[0]);
    assert(strcmp(out2, check2) == 0);

    char substrTest3[26] = "(a-b(c-d+e+f(g-h))-i+j)-k";
    char out3[26] = "";
    char check3[26] = "g-h";
    deepest_substring(&substrTest3[0], &out3[0]);
    assert(strcmp(out3, check3) == 0);

    char substrTest4[12] = "a-b+c-d+e-f";
    char out4[12] = "";
    char check4[12] = "a-b+c-d+e-f";
    deepest_substring(&substrTest4[0], &out4[0]);
    assert(strcmp(out4, check4) == 0);

    char substrTest5[34] = "(((((((((((a+b-c+d/e*f)))))))))))";
    char out5[34] = "";
    char check5[34] = "a+b-c+d/e*f";
    deepest_substring(&substrTest5[0], &out5[0]);
    assert(strcmp(out5, check5) == 0);

    printf("All tests passed successfully!\n");
}
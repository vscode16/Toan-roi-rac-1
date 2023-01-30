#include <iostream>
#include <fstream>
#include <cstring>
#define SIZE 9
#define SUB_SIZE 3
using namespace std;

int board[SIZE][SIZE];
bool markRow[SIZE][SIZE]; // [index][number]
bool markCol[SIZE][SIZE]; // [index][number]
bool markSub[SUB_SIZE][SUB_SIZE][SIZE]; // [index][index][number]

void enter() {
    ifstream input;
    input.open("input_sudoku.txt");

    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            input >> board[i][j];

    input.close();
}

void init() {
    memset(markRow, false, sizeof(markRow));
    memset(markCol, false, sizeof(markCol));
    memset(markSub, false, sizeof(markSub));

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 0) {
                markRow[i][board[i][j] - 1] = true;
                markCol[j][board[i][j] - 1] = true;
                markSub[i / 3][j / 3][board[i][j] - 1] = true;
            }
        }
    }
}
void show();
void Try(int i, int j) {
    if (board[i][j] == 0) {
        for (int v = 1; v <= 9; ++v) {
            if (!markRow[i][v - 1] && !markCol[j][v - 1] && !markSub[i / 3][j / 3][v - 1]) {
                board[i][j] = v;
                markRow[i][v - 1] = true;
                markCol[j][v - 1] = true;
                markSub[i / 3][j / 3][v - 1] = true;

                if (i == 8 && j == 8) {
                    show();
                    return;
                } else {
                    if (j < 8) {
                        Try(i, j + 1);
                    } else {
                        Try(i + 1, 0);
                    }
                }

                board[i][j] = 0;
                markRow[i][v - 1] = false;
                markCol[j][v - 1] = false;
                markSub[i / 3][j / 3][v - 1] = false;
            }
        }
    } else {
        if (i == 8 && j == 8) {
            show();
            return;
        } else {
            if (j < 8) {
                Try(i, j + 1);
            } else {
                Try(i + 1, 0);
            }
        }
    }
}

void show() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    enter();
    init();
    Try(0, 0);

    return 0;
}
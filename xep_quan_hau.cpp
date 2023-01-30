#include <iostream>
#include <cstring>
#define SIZE 8
using namespace std;

bool banCo[SIZE][SIZE];
bool cot[SIZE];
bool dct[2 * SIZE - 1], dcn[2 * SIZE - 1];

void khoiTao() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            banCo[i][j] = false;
        }
    }
    memset(cot, false, sizeof(cot));
    memset(dct, false, sizeof(dct));
    memset(dcn, false, sizeof(dcn));
}
void in() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (banCo[i][j]) cout << "X ";
            else cout << "O ";
        }
        cout << '\n';
    }
    cout << "\n\n";
}
void Try(int i) {
    for (int j = 0; j < SIZE; ++j) {
        if (!cot[j] && !dct[i - j + SIZE - 1] && !dcn[i + j]) {
            banCo[i][j] = true;
            cot[j] = true;
            dct[i - j + SIZE - 1] = true;
            dcn[i + j] = true;
            
            if (i == SIZE - 1) in();
            else Try(i + 1);
            
            banCo[i][j] = false;
            cot[j] = false;
            dct[i - j + SIZE - 1] = false;
            dcn[i + j] = false;
        }
    }
}
int main(void) {

    khoiTao();
    Try(0);

    return 0;
}
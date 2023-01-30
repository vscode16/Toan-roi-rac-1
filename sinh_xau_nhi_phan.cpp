#include <iostream>
#define MAX 32
using namespace std;
int x[32], n;
bool isFinal;

void init() {
    isFinal = false;
    for (int i = 0; i < n; ++i) x[i] = 0;
}
void generate() {
    int i = n - 1;
    while (i >= 0 && x[i] == 1) --i;
    if (i >= 0) {
        x[i] = 1;
        for (int j = i + 1; j < n; ++j) x[j] = 0;
    } else {
        isFinal = true;
    }
}
void print() {
    for (int i = 0; i < n; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}

namespace QuayLui {
void xuat() {
    for (int i = 0; i < n; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 0; j <= 1; ++j) {
        x[i] = j;
        if (i == (n - 1)) {
            xuat();
        } else {
            Try(i + 1);
        }
    }
}
}
int main(void) {
    cin >> n;
    /*
    init();
    while (!isFinal) {
        print();
        generate();
    }
    generate();
    */
    //using namespace QuayLui;
    QuayLui::Try(0);
    return 0;
}
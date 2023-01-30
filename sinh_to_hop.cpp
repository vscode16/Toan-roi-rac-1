#include <iostream>
using namespace std;
char a[32], x[32];
int n, k;
bool isFinal;
void enter() {
    cout << "nhap n va k ";
    cin >> n >> k;
    cout << "nhap tap A ";
    for (int i = 0; i < n; ++i) cin >> a[i];
}
void init() {
    isFinal = false;
    for (int i = 0; i < k; ++i) {
        x[i] = a[i];
    }
}
int find(char c) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == c) {
            return i;
        }
    }
    return -1;
}
void generate() {
    int i = k - 1;
    while (i >= 0 && x[i] == a[n - k + i]) --i;
    if (i >= 0) {
        int idx = find(x[i]);
        x[i] = a[idx + 1];
        for (int j = i + 1; j < k; ++j) {
            x[j] = a[idx + j - i + 1];
        }
    } else {
        isFinal = true;
    }
}
void print() {
    for (int i = 0; i < k; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}
int main(void) {

    enter();
    init();
    while (!isFinal) {
        print();
        generate();
    }
    print();

    return 0;
}
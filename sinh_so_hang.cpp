#include <iostream>
using namespace std;
// global variable
int n, ssh;
int x[100];
bool isFinal;

void nhap() {
    cout << "nhap so tu nhien n: ";
    cin >> n;
}
// cach 1 (sai)
namespace cach1 {
int ssh;
bool isFinal;
void sinh() {
    int i = ssh - 1;
    while (i >= 1 && x[i] == 1) --i;
    if (i == 0) {
        isFinal = true;
    } else {
        x[i] -= 1;
        ssh += 1;
        x[ssh - 1] = 1;
    }
}
void xem() {
    for (int i = 0; i < ssh; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void xuLy() {
    for (int i = n - 1; i >= 1; --i) {
        isFinal = false;
        int m = n % i, t = n / i;
        for (int j = 0; j < t; ++j) {
            x[j] = i;
        }
        if (m == 0) {
            ssh = t;
        } else {
            ssh = t + 1;
            x[ssh - 1] = m;
        }
        while (!isFinal) {
            xem();
            sinh();
        }
        sinh();
    }
}
}
// cach 2 (dung)
void khoiTao() {
    isFinal = false;
    ssh = 1;
    x[0] = n;
}
void sinh() {
    int i = ssh - 1;
    int du = 0;
    while (i >= 0 && x[i] == 1) {
        --i;
        du += 1;
    }
    if (i >= 0) {
        x[i] -= 1;
        du += 1;
        ssh = i + 1;
        for (int j = i + 1; j <= i + (du / x[i]); ++j) {
            x[j] = x[i];
            ssh += 1;
        }
        if (du % x[i] != 0) {
            ssh += 1;
            x[ssh - 1] = du % x[i];
        }
    } else {
        isFinal = true;
    }
}
void xuat() {
    for (int i = 0; i < ssh; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}
int main(void) {

    nhap();
    khoiTao();
    while (!isFinal) {
        xuat();
        sinh();
    }
    xuat();

    return 0;
}
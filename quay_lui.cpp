#include <iostream>
#include <cstring>

using namespace std;
char g[32];
char x[32];
bool isUsed[32];
int n, k;
namespace ToHop {
void nhap() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> g[i];
}
void khoiTao() {
    memset(isUsed, false, sizeof(isUsed));
}
int timKiem(char c) {
    for (int i = 0; i < n; ++i) {
        if (c == g[i]) return i;
    }
    return -1;
}
void xuat() {
    for (int i = 0; i < k; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void Try(int i) {
    int t;
    if (i == 0) t = -1;
    else t = timKiem(x[i - 1]);
    for (int j = t + 1; j <= n - k + i; ++j) {
        x[i] = g[j];
        if (i == (k - 1)) xuat();
        else Try(i + 1);
    }
}
}
namespace HoanVi {
void nhap() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> g[i];
}
void khoiTao() {
    memset(isUsed, false, sizeof(isUsed));
}
void xuat() {
    for (int i = 0; i < n; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 0; j < n; ++j) {
        if (!isUsed[j]) {
            x[i] = g[j];
            isUsed[j] = true;
            if (i == n - 1) {
                xuat();
            } else {
                Try(i + 1);
            }
            isUsed[j] = false;
        }
    }
}
}
int main(void) {
    /*
    cin >> n >> k;
    ToHop::Try(1);
    */
    // ToHop::nhap();
    // ToHop::Try(0);

    HoanVi::nhap();
    HoanVi::khoiTao();
    HoanVi::Try(0);

    return 0;
}
#include <iostream>

char x[32];
int idx[32];
int n;
bool isFinal;
void nhap() {
    std::cout << "so luong phan tu ";
    std::cin >> n;
    std::cout << "nhap cac phan tu: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }
}
void khoiTao() {
    isFinal = false;
    for (int i = 0; i < n; ++i) {
        idx[i] = i;
    }
}
void sinh() {
    int i = n - 2;
    while (i >= 0 && idx[i] > idx[i + 1]) --i;
    if (i < 0) {
        isFinal = true;
        return;
    }
    int j = n - 1;
    while (j > i && idx[j] < idx[i]) --j;
    // swap
    int temp = idx[i];
    idx[i] = idx[j];
    idx[j] = temp;
    //
    // dao
    int l = i + 1, r = n - 1;
    while (l < r) {
        temp = idx[l];
        idx[l] = idx[r];
        idx[r] = temp;
        ++l; --r;
    }
}
void xuat() {
    for (int i = 0; i < n; ++i) {
        std::cout << x[idx[i]] << " ";
    }
    std::cout << std::endl;
}
int main(void) {

    nhap();
    khoiTao();
    while (!isFinal) {
        xuat();
        sinh();
    }
    sinh();

    return 0;
}
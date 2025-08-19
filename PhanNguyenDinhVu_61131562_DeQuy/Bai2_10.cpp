#include <stdio.h>

// Hàm tính giai thua cua 1 so nguyên
int tinhGiaiThua(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * tinhGiaiThua(n - 1);
}

// Hàm de quy tính x_n
int tinh_x(int n) {
    if (n == 0)
        return 1;  // Ðieu kien co so: x_0 = 1

    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += tinhGiaiThua(n - i) * tinh_x(i);
    }
    return tong;
}

int main() {
    int n;
    printf("Nhap gia tri n: ");
    scanf("%d", &n);

    // Goi hàm de quy
    printf("Gia tri x_%d = %d\n", n, tinh_x(n));

    return 0;
}


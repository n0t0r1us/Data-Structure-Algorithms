#include <stdio.h>

// H�m t�nh giai thua cua 1 so nguy�n
int tinhGiaiThua(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * tinhGiaiThua(n - 1);
}

// H�m de quy t�nh x_n
int tinh_x(int n) {
    if (n == 0)
        return 1;  // �ieu kien co so: x_0 = 1

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

    // Goi h�m de quy
    printf("Gia tri x_%d = %d\n", n, tinh_x(n));

    return 0;
}


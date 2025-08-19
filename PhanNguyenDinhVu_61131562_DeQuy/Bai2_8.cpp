#include <stdio.h>

// H�m de quy t�nh x_n
int tinh_x(int n) {
    // �ieu kien co so
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // �e quy: x_n = (x_{n-1} + x_{n-2})^2 + (x_{n-1} - x_{n-2})^2
    int x_n_1 = tinh_x(n - 1);
    int x_n_2 = tinh_x(n - 2);
    return (x_n_1 + x_n_2) * (x_n_1 + x_n_2) + (x_n_1 - x_n_2) * (x_n_1 - x_n_2);
}

int main() {
    int n;
    printf("Nhap gia tri n: ");
    scanf("%d", &n);

    // Goi h�m de quy
    printf("Gia tri x_%d = %d\n", n, tinh_x(n));

    return 0;
}


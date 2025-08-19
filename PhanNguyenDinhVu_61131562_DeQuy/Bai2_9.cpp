#include <stdio.h>

// H�m de quy t�nh x_n
int tinh_x(int n);

// H�m de quy t�nh y_n
int tinh_y(int n);

// H�m de quy t�nh x_n
int tinh_x(int n) {
    // �ieu kien co so
    if (n == 0)
        return 1;

    // �e quy: x_n = 2x_{n-1} + 3y_{n-1}
    return 2 * tinh_x(n - 1) + 3 * tinh_y(n - 1);
}

// H�m de quy t�nh y_n
int tinh_y(int n) {
    // �ieu kien co so
    if (n == 0)
        return 1;

    // �e quy: y_n = 3x_{n-1} - 2y_{n-1}
    return 3 * tinh_x(n - 1) - 2 * tinh_y(n - 1);
}

int main() {
    int n;
    printf("Nhap gia tri n: ");
    scanf("%d", &n);

    // Goi h�m de quy
    printf("Gi� tri x_%d = %d\n", n, tinh_x(n));
    printf("Gi� tri y_%d = %d\n", n, tinh_y(n));

    return 0;
}


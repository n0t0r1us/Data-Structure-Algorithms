#include <stdio.h>

// Hàm de quy tính x_n
int tinh_x(int n);

// Hàm de quy tính y_n
int tinh_y(int n);

// Hàm de quy tính x_n
int tinh_x(int n) {
    // Ğieu kien co so
    if (n == 0)
        return 1;

    // Ğe quy: x_n = 2x_{n-1} + 3y_{n-1}
    return 2 * tinh_x(n - 1) + 3 * tinh_y(n - 1);
}

// Hàm de quy tính y_n
int tinh_y(int n) {
    // Ğieu kien co so
    if (n == 0)
        return 1;

    // Ğe quy: y_n = 3x_{n-1} - 2y_{n-1}
    return 3 * tinh_x(n - 1) - 2 * tinh_y(n - 1);
}

int main() {
    int n;
    printf("Nhap gia tri n: ");
    scanf("%d", &n);

    // Goi hàm de quy
    printf("Giá tri x_%d = %d\n", n, tinh_x(n));
    printf("Giá tri y_%d = %d\n", n, tinh_y(n));

    return 0;
}


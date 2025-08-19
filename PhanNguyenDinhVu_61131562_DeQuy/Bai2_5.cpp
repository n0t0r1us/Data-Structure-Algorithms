#include <stdio.h>

int dem(int n) {
    // Neu n nho hon 10, c� nghia l� so chi c� 1 chu so
    if (n < 10)
        return 1;
    else
        return 1 + dem(n / 10);  // �e quy: chia n cho 10 v� dem tiep
}

int main() {
    int n;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    // Kiem tra neu n l� so duong
    if (n >= 0) {
        printf("So luong chu so cua %d la: %d\n", n, dem(n));
    } else {
        printf("Vui l�ng nhap so nguy�n duong\n");
    }

    return 0;
}


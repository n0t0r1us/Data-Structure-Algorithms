#include <stdio.h>

int dem(int n) {
    // Neu n nho hon 10, có nghia là so chi có 1 chu so
    if (n < 10)
        return 1;
    else
        return 1 + dem(n / 10);  // Ðe quy: chia n cho 10 và dem tiep
}

int main() {
    int n;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    // Kiem tra neu n là so duong
    if (n >= 0) {
        printf("So luong chu so cua %d la: %d\n", n, dem(n));
    } else {
        printf("Vui lòng nhap so nguyên duong\n");
    }

    return 0;
}


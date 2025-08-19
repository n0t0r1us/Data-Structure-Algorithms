#include <stdio.h>

double sum_reciprocal(int n) {
    if (n == 1)
        return 1.0;  // �ieu kien dung: neu n = 1, tra ve 1
    else
        return 1.0 / n + sum_reciprocal(n - 1);  // �e quy: 1/n + sum(n-1)
}

int main() {
    int n;
    printf("Nhap gia tri n: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Ket qua S = %.5f\n", sum_reciprocal(n));
    } else {
        printf("n phai lon hon 0\n");
    }

    return 0;
}


#include <stdio.h>

int product_odd(int n) {
    if (n == 0)
        return 1;  // Ðieu kien dung: neu n = 0, tra ve 1
    else
        return (2 * n + 1) * product_odd(n - 1);
}

int main() {
    int n;
    printf("Nhap gia tri n: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Ket qua S = %d\n", product_odd(n));
    } else {
        printf("n phai lon hon 0\n");
    }

    return 0;
}


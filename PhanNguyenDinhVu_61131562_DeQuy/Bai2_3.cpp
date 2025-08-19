#include <stdio.h>

int tinhTong(int n) {
    if (n == 1)
        return 1;  // Ðieu kien dung: neu n = 1, tra ve 1
    else
        return n * (n % 2 == 1 ? 1 : -1) + tinhTong(n - 1);
}

int main() {
    int n;
    printf("Nhap gia tri n: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Ket qua S = %d\n", tinhTong(n));
    } else {
        printf("n phai lon hon 0\n");
    }

    return 0;
}


#include <stdio.h>

// Hàm tính giai thua (n!)
int giaiThua(int n) {
    if (n == 0)
        return 1;  // 0! = 1
    else
        return n * giaiThua(n - 1);  // n! = n * (n-1)!
}

// Hàm tính tong cua các giai thua tu 1! den n!
int tongGiaiThua(int n) {
    if (n == 1)
        return 1;  // Ðieu kien dung: 1! = 1
    else
        return giaiThua(n) + tongGiaiThua(n - 1);  // Tong de quy các giai thua
}

int main() {
    int n;
    printf("Nhap gia tri n: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Ket qua S = %d\n", tongGiaiThua(n));
    } else {
        printf("n phai ln hon 0\n");
    }

    return 0;
}


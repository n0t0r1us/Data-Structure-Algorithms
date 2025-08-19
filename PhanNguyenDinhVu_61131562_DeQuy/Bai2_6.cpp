#include <stdio.h>

// H�m de quy t�m uoc so chung lon nhat (USCLN) su dung phuong ph�p a - b
int gcd(int a, int b) {
    if (a == b)  // �ieu kien dung: khi a v� b bang nhau
        return a;
    if (a > b)
        return gcd(a - b, b);  // �e quy: a lon hon b th� tru a - b
    else
        return gcd(a, b - a);  // �e quy: b lon hon a th� tru b - a
}

// H�m t�m boi so chung nho nhat (BSCNN)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);  // BSCNN(a, b) = |a * b| / USCLN(a, b)
}

int main() {
    int a, b;
    printf("Nhap hai so nguyen a va b: ");
    scanf("%d", &a);
    scanf("%d", &b);

    // Kiem tra neu a v� b l� so duong
    if (a > 0 && b > 0) {
        printf("Uoc so chung lon nhat cua %d v� %d la: %d\n", a, b, gcd(a, b));
        printf("Boi so chung nho nhat cua %d v� %d la: %d\n", a, b, lcm(a, b));
    } else {
        printf("Vui l�ng nhap hai so nguy�n duong\n");
    }

    return 0;
}


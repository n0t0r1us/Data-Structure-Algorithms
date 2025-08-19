#include <stdio.h>

// Hàm de quy tìm uoc so chung lon nhat (USCLN) su dung phuong pháp a - b
int gcd(int a, int b) {
    if (a == b)  // Ðieu kien dung: khi a và b bang nhau
        return a;
    if (a > b)
        return gcd(a - b, b);  // Ðe quy: a lon hon b thì tru a - b
    else
        return gcd(a, b - a);  // Ðe quy: b lon hon a thì tru b - a
}

// Hàm tìm boi so chung nho nhat (BSCNN)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);  // BSCNN(a, b) = |a * b| / USCLN(a, b)
}

int main() {
    int a, b;
    printf("Nhap hai so nguyen a va b: ");
    scanf("%d", &a);
    scanf("%d", &b);

    // Kiem tra neu a và b là so duong
    if (a > 0 && b > 0) {
        printf("Uoc so chung lon nhat cua %d và %d la: %d\n", a, b, gcd(a, b));
        printf("Boi so chung nho nhat cua %d và %d la: %d\n", a, b, lcm(a, b));
    } else {
        printf("Vui lòng nhap hai so nguyên duong\n");
    }

    return 0;
}


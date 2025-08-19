#include <stdio.h>
#include <math.h>  // Ðe su dung hàm pow()

// Hàm tính so tien sau N nam voi lãi suat a và khoan quà b moi 10 nam
double tinhTongSoTien(double X, double a, double b, int N) {
    double tong = X;  // So tien ban dau
    for (int i = 1; i <= N; i++) {
        tong += tong * a;  // Tính lãi hàng nam

        // Cu sau 10 nam thì cong thêm khoan quà b
        if (i % 10 == 0) {
            tong += b;
        }
    }
    return tong;
}

int main() {
    double X, a, b;
    int N;

    // Nhap du lieu
    printf("Nhap so tien ban dau X: ");
    scanf("%lf", &X);
    printf("Nhap lai suat hang nam a (vi du: 0.05 cho 5%%): ");
    scanf("%lf", &a);
    printf("Nhap gia tri qua tang sau moi 10 nam b: ");
    scanf("%lf", &b);
    printf("Nhap so nam gui tien N: ");
    scanf("%d", &N);

    // Tính so tien sau N nam
    double tongTien = tinhTongSoTien(X, a, b, N);

    // Hien thi ket qua
    printf("So tien sau %d nam la: %.2f\n", N, tongTien);

    return 0;
}


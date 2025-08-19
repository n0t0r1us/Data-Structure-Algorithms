#include <stdio.h>
#include <math.h>  // �e su dung h�m pow()

// H�m t�nh so tien sau N nam voi l�i suat a v� khoan qu� b moi 10 nam
double tinhTongSoTien(double X, double a, double b, int N) {
    double tong = X;  // So tien ban dau
    for (int i = 1; i <= N; i++) {
        tong += tong * a;  // T�nh l�i h�ng nam

        // Cu sau 10 nam th� cong th�m khoan qu� b
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

    // T�nh so tien sau N nam
    double tongTien = tinhTongSoTien(X, a, b, N);

    // Hien thi ket qua
    printf("So tien sau %d nam la: %.2f\n", N, tongTien);

    return 0;
}


#include <stdio.h>

int main() {
    double a, b, c;
    double x, y, z;

    printf("Digite os tres lados: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Lados invalidos.\n");
        return 0;
    }

    if (a < b + c && b < a + c && c < a + b) {
        printf("Triangulo valido.\n");

        if (a == b && b == c) {
            printf("Equilatero\n");
        } else if (a == b || a == c || b == c) {
            printf("Isosceles\n");
        } else {
            printf("Escaleno\n");
        }

        x = a;
        y = b;
        z = c;

        if (x > z) {
            double temp = x;
            x = z;
            z = temp;
        }

        if (y > z) {
            double temp = y;
            y = z;
            z = temp;
        }

        if ((x * x + y * y) == (z * z)) {
            printf("Retangulo\n");
        } else if ((x * x + y * y) < (z * z)) {
            printf("Obtusangulo\n");
        } else {
            printf("Acutangulo\n");
        }

    } else {
        printf("Nao forma um triangulo.\n");
    }

    return 0;
}
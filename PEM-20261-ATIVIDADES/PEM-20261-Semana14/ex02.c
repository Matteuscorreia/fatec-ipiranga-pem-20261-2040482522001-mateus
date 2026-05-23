#include <stdio.h>

int main() {
    int centimetros;
    float metros;
    double quilometros, milhas;

    // int suporta valores inteiros grandes de centímetros
    // float é suficiente para metros
    // double oferece maior precisão para km e milhas

    printf("Digite a distancia em centimetros: ");
    scanf("%d", &centimetros);

    if (centimetros <= 0) {
        printf("Erro: valor deve ser positivo.\n");
    } else {
        metros = centimetros / 100.0f;
        quilometros = centimetros / 100000.0;
        milhas = quilometros / 1.60934;

        printf("\nMetros: %.2f\n", metros);
        printf("Quilometros: %.6lf\n", quilometros);
        printf("Milhas: %.6lf\n", milhas);
    }

    return 0;
}
#include <stdio.h>

int main() {
    int n, passos = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Valor invalido.\n");
        return 0;
    }

    printf("Sequencia: ");

    while (n != 1) {
        printf("%d ", n);

        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

        passos++;
    }

    printf("1\n");
    printf("Passos: %d\n", passos);

    return 0;
}
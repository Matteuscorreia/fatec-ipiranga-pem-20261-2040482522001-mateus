#include <stdio.h>

int main() {

    int numero = 1;
    char opcao;

    do {

        printf("\nTabuada do %d\n", numero);

        int j = 1;

        while (j <= 10) {
            printf("%2d x %2d = %3d\n", numero, j, numero * j);
            j++;
        }

        numero++;

        if (numero <= 10) {
            printf("\nDeseja continuar? (S/N): ");
            scanf(" %c", &opcao);
        } else {
            opcao = 'N';
        }

    } while ((opcao == 'S' || opcao == 's') && numero <= 10);

    return 0;
}
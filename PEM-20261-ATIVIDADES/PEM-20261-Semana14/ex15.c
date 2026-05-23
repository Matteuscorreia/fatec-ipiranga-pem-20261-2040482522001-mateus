#include <stdio.h>
#include <math.h>

int movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar) {

    // Caso base
    if (n == 1) {

        printf("Mova disco 1 de %c para %c\n",
               origem,
               destino);

        movimentos++;

        return;
    }

    // Passo recursivo

    hanoi(n - 1, origem, auxiliar, destino);

    printf("Mova disco %d de %c para %c\n",
           n,
           origem,
           destino);

    movimentos++;

    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {

    int n;

    printf("Digite o numero de discos: ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {

        printf("Valor invalido.\n");
        return 0;
    }

    hanoi(n, 'A', 'C', 'B');

    printf("\nTotal de movimentos: %d\n", movimentos);

    printf("Formula 2^n - 1 = %.0lf\n",
           pow(2, n) - 1);

    return 0;
}
#include <stdio.h>

int main() {
    double n1, n2, n3;
    int p1, p2, p3;
    double media;

    printf("Digite a nota 1 e o peso: ");
    scanf("%lf %d", &n1, &p1);

    printf("Digite a nota 2 e o peso: ");
    scanf("%lf %d", &n2, &p2);

    printf("Digite a nota 3 e o peso: ");
    scanf("%lf %d", &n3, &p3);

    media = (n1 * p1 + n2 * p2 + n3 * p3) / (p1 + p2 + p3);

    printf("\nMedia ponderada: %.2lf\n", media);

    printf("\nTamanho dos tipos:\n");
    printf("double: %lu bytes\n", (unsigned long)sizeof(double));
    printf("int: %lu bytes\n", (unsigned long)sizeof(int));

    return 0;
}
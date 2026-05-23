#include <stdio.h>

#define N 8

int main() {
    int v[N], inverso[N];
    int maior, menor;
    int idxMaior = 0, idxMenor = 0;
    int pares = 0, impares = 0;
    int busca;

    for (int i = 0; i < N; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    maior = menor = v[0];

    for (int i = 0; i < N; i++) {
        if (v[i] > maior) {
            maior = v[i];
            idxMaior = i;
        }

        if (v[i] < menor) {
            menor = v[i];
            idxMenor = i;
        }

        if (v[i] % 2 == 0)
            pares++;
        else
            impares++;

        inverso[i] = v[N - 1 - i];
    }

    printf("\nVetor original:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }

    printf("\n\nMaior valor: %d no indice %d\n", maior, idxMaior);
    printf("Menor valor: %d no indice %d\n", menor, idxMenor);
    printf("Pares: %d\n", pares);
    printf("Impares: %d\n", impares);

    printf("\nVetor inverso:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", inverso[i]);
    }

    printf("\n\nDigite um valor para busca: ");
    scanf("%d", &busca);

    int encontrado = 0;

    for (int i = 0; i < N; i++) {
        if (v[i] == busca) {
            printf("Valor encontrado no indice %d\n", i);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Valor nao encontrado.\n");
    }

    return 0;
}
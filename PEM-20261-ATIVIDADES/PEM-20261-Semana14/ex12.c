#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minMax(int *v, int n, int *min, int *max) {
    *min = v[0];
    *max = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] < *min)
            *min = v[i];

        if (v[i] > *max)
            *max = v[i];
    }
}

void normalizaVetor(float *v, int n) {
    float maior = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] > maior)
            maior = v[i];
    }

    for (int i = 0; i < n; i++) {
        v[i] /= maior;
    }
}

int main() {

    int a = 10, b = 20;

    printf("Antes da troca: a=%d b=%d\n", a, b);

    troca(&a, &b);

    printf("Depois da troca: a=%d b=%d\n", a, b);

    int vet[5] = {4, 9, 1, 7, 2};
    int min, max;

    minMax(vet, 5, &min, &max);

    printf("\nMinimo: %d\n", min);
    printf("Maximo: %d\n", max);

    float vf[4] = {2.0, 4.0, 8.0, 16.0};

    printf("\nVetor original:\n");

    for (int i = 0; i < 4; i++) {
        printf("%.2f ", vf[i]);
    }

    normalizaVetor(vf, 4);

    printf("\n\nVetor normalizado:\n");

    for (int i = 0; i < 4; i++) {
        printf("%.2f ", vf[i]);
    }

    printf("\n");

    return 0;
}
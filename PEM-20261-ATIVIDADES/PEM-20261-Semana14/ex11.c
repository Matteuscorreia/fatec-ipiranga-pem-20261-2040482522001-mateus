#include <stdio.h>

int main() {
    int v[6] = {1, 2, 3, 4, 5, 6};
    int *p = v;
    int soma = 0;

    for (int i = 0; i < 6; i++) {
        printf("Valor: %d | Endereco: %p\n", *(p + i), (void *)(p + i));

        soma += *(p + i);

        *(p + i) *= 2;
    }

    printf("\nSoma: %d\n", soma);

    printf("\nVetor dobrado:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", *(p + i));
    }

    printf("\n\nDiferenca entre enderecos consecutivos: %lu bytes\n",
       (unsigned long)((char *)(p + 1) - (char *)p));

    return 0;
}
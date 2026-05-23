#include <stdio.h>

void exibir(int m[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tab[4][4] = {
        {1, 2, 3, 4},
        {2, 1, 4, 3},
        {5, 6, 7, 8},
        {6, 5, 8, 7}
    };

    int simetrico = 1;
    int somaPrincipal = 0, somaSecundaria = 0;

    printf("Tabuleiro:\n");
    exibir(tab);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tab[i][j] != tab[j][i]) {
                simetrico = 0;
            }
        }
    }

    if (simetrico)
        printf("\nPares simetricos em relacao a diagonal principal.\n");
    else
        printf("\nNao eh simetrico.\n");

    for (int i = 0; i < 4; i++) {
        somaPrincipal += tab[i][i];
        somaSecundaria += tab[i][3 - i];
    }

    printf("Diagonal principal: %d\n", somaPrincipal);
    printf("Diagonal secundaria: %d\n", somaSecundaria);

    return 0;
}
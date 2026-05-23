#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int chamadasBusca = 0;
int chamadasSoma = 0;

int profundidadeBusca = 0;
int profundidadeSoma = 0;

int buscaRecAux(int *v,
                int n,
                int chave,
                int nivel) {

    chamadasBusca++;

    if (nivel > profundidadeBusca)
        profundidadeBusca = nivel;

    // Caso base
    if (n == 0)
        return -1;

    if (v[0] == chave)
        return 0;

    // Passo recursivo

    int resultado =
        buscaRecAux(v + 1,
                    n - 1,
                    chave,
                    nivel + 1);

    if (resultado == -1)
        return -1;

    return resultado + 1;
}

int buscaRec(int *v,
             int n,
             int chave) {

    return buscaRecAux(v,
                       n,
                       chave,
                       1);
}

int somaRecAux(int *v,
               int ini,
               int fim,
               int nivel) {

    chamadasSoma++;

    if (nivel > profundidadeSoma)
        profundidadeSoma = nivel;

    // Caso base
    if (ini == fim)
        return v[ini];

    // Passo recursivo

    int meio = (ini + fim) / 2;

    return somaRecAux(v,
                      ini,
                      meio,
                      nivel + 1)

           +

           somaRecAux(v,
                      meio + 1,
                      fim,
                      nivel + 1);
}

int somaRec(int *v,
            int ini,
            int fim) {

    return somaRecAux(v,
                      ini,
                      fim,
                      1);
}

int main() {

    int v[12];
    int chave;

    srand(time(NULL));

    printf("Vetor:\n");

    for (int i = 0; i < 12; i++) {

        v[i] = rand() % 100;

        printf("%d ", v[i]);
    }

    printf("\n");

    int soma = somaRec(v, 0, 11);

    printf("\nSoma total: %d\n", soma);

    printf("Digite um valor para busca: ");
    scanf("%d", &chave);

    int indice = buscaRec(v, 12, chave);

    if (indice != -1)
        printf("Valor encontrado no indice %d\n",
               indice);
    else
        printf("Valor nao encontrado\n");

    printf("\nChamadas buscaRec: %d\n",
           chamadasBusca);

    printf("Profundidade maxima buscaRec: %d\n",
           profundidadeBusca);

    printf("\nChamadas somaRec: %d\n",
           chamadasSoma);

    printf("Profundidade maxima somaRec: %d\n",
           profundidadeSoma);

    return 0;
}
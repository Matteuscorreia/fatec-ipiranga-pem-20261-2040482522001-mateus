#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASTAS 50
#define LIMITE_ALERTA 300.0

typedef struct {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int subpastas_indices[10];
    int qtd_sub;
} Pasta;

typedef struct {
    int index;
    int nivel;
    int visitado; // 0 = primeira vez, 1 = pós-processamento
} StackItem;

int ciclos = 0;

float processarHierarquia_iterativo(Pasta *drive, int raiz, int limite) {
    StackItem stack[100];
    int top = -1;

    stack[++top] = (StackItem){raiz, 0, 0};

    while (top >= 0) {
        ciclos++;

        StackItem atual = stack[top--];
        int idx = atual.index;
        int nivel = atual.nivel;

        if (idx == -1 || nivel > limite) continue;

        if (atual.visitado == 0) {
            // Empilha novamente como visitado (pós-ordem)
            stack[++top] = (StackItem){idx, nivel, 1};

            // Empilha filhos
            for (int i = drive[idx].qtd_sub - 1; i >= 0; i--) {
                stack[++top] = (StackItem){
                    drive[idx].subpastas_indices[i],
                    nivel + 1,
                    0
                };
            }
        } else {
            // Agora sim: filhos já processados → pode somar
            drive[idx].tamanho_total = drive[idx].tamanho_proprio;

            for (int i = 0; i < drive[idx].qtd_sub; i++) {
                int filho = drive[idx].subpastas_indices[i];
                drive[idx].tamanho_total += drive[filho].tamanho_total;
            }

            // Impressão igual à recursiva
            for (int i = 0; i < nivel; i++) printf("  ");

            printf("|-- %s [%.2f GB]", drive[idx].nome, drive[idx].tamanho_total);

            if (drive[idx].tamanho_total > LIMITE_ALERTA) {
                printf(" [!] ALERTA: GARGALO DETECTADO");
            }
            printf("\n");
        }
    }

    return drive[raiz].tamanho_total;
}

int main() {
    Pasta drive[MAX_PASTAS];

    strcpy(drive[0].nome, "RAIZ");
    drive[0].tamanho_proprio = 10.0;
    drive[0].qtd_sub = 2;
    drive[0].subpastas_indices[0] = 1;
    drive[0].subpastas_indices[1] = 2;

    strcpy(drive[1].nome, "Projetos_TI");
    drive[1].tamanho_proprio = 50.0;
    drive[1].qtd_sub = 1;
    drive[1].subpastas_indices[0] = 3;

    strcpy(drive[2].nome, "Backups_Antigos");
    drive[2].tamanho_proprio = 350.0;
    drive[2].qtd_sub = 0;

    strcpy(drive[3].nome, "Videos_Aulas");
    drive[3].tamanho_proprio = 280.0;
    drive[3].qtd_sub = 0;

    int limite;
    printf("Defina o limite de profundidade: ");
    scanf("%d", &limite);

    clock_t t;
    t = clock();

    printf("\n--- RELATORIO ITERATIVO ---\n");
    processarHierarquia_iterativo(drive, 0, limite);

    t = clock() - t;
    double tempo = ((double)t) / CLOCKS_PER_SEC;

    printf("---------------------------------\n");
    printf("Ciclos: %d\n", ciclos);
    printf("Tempo: %f segundos\n", tempo);

    return 0;
}
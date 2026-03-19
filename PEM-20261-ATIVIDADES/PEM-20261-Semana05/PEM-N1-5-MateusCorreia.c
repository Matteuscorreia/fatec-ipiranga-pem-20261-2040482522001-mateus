#include <stdio.h>
#include <string.h>

#define TAM 8

char tab[TAM][TAM][4];

void inicializarTabuleiro();
void mostrarTabuleiro();
void jogada1();
void jogada2();
void jogada3();
void jogada4();

// ================= MAIN =================
int main() {

    inicializarTabuleiro();

    printf("\n=== TABULEIRO INICIAL ===\n");
    mostrarTabuleiro();

    jogada1();
    jogada2();
    jogada3();
    jogada4();

    return 0;
}

// ================= TABULEIRO =================
void inicializarTabuleiro() {

    int i, j;

    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            strcpy(tab[i][j], "..");
        }
    }

    // Peões pretos
    for(j = 0; j < TAM; j++) {
        strcpy(tab[1][j], "PP");
    }

    // Peões brancos
    for(j = 0; j < TAM; j++) {
        strcpy(tab[6][j], "PB");
    }

    // Peças pretas
    strcpy(tab[0][0], "TP");
    strcpy(tab[0][1], "CP");
    strcpy(tab[0][2], "BP");
    strcpy(tab[0][3], "DP");
    strcpy(tab[0][4], "RP");
    strcpy(tab[0][5], "BP");
    strcpy(tab[0][6], "CP");
    strcpy(tab[0][7], "TP");

    // Peças brancas
    strcpy(tab[7][0], "TB");
    strcpy(tab[7][1], "CB");
    strcpy(tab[7][2], "BB");
    strcpy(tab[7][3], "DB");
    strcpy(tab[7][4], "RB");
    strcpy(tab[7][5], "BB");
    strcpy(tab[7][6], "CB");
    strcpy(tab[7][7], "TB");
}

// ================= MOSTRAR TABULEIRO =================
void mostrarTabuleiro() {

    int i, j;

    printf("\n");

    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            printf("%s ", tab[i][j]);
        }
        printf("\n");
    }
}

// ================= JOGADAS =================

void jogada1() {

    printf("\n=== JOGADA 1 ===\n");

    // Branco
    strcpy(tab[6][4], "..."); // origem
    strcpy(tab[4][4], "PB");  // destino

    // Preto
    strcpy(tab[1][4], "...");
    strcpy(tab[3][4], "PP");

    mostrarTabuleiro();
}

void jogada2() {

    printf("\n=== JOGADA 2 ===\n");

    // Branco
    strcpy(tab[7][5], "...");
    strcpy(tab[4][2], "BB");

    // Preto
    strcpy(tab[0][1], "...");
    strcpy(tab[2][2], "CP");

    mostrarTabuleiro();
}

void jogada3() {

    printf("\n=== JOGADA 3 ===\n");

    // Branco
    strcpy(tab[7][3], "...");
    strcpy(tab[3][7], "DB");

    // Preto
    strcpy(tab[0][6], "...");
    strcpy(tab[2][5], "CP");

    mostrarTabuleiro();
}

void jogada4() {

    printf("\n=== JOGADA 4 - XEQUE MATE ===\n");

    strcpy(tab[3][7], "...");
    strcpy(tab[1][5], "DB");

    mostrarTabuleiro();
}
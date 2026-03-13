#include <stdio.h>

int main()
{
    char tabuleiro[3][3];
    char jogadorAtual = 'X';
    char vazio = ' ';
    int vencedor = 0;

    int i, j;
    int jogadas = 0, linha, coluna;

    // =============== 1. Inicialização do tabuleiro
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            tabuleiro[i][j] = vazio;
        }
    }

    // =============== 2. Laço principal
    while (jogadas < 9 && !vencedor)
    {
        // Exibir tabuleiro
        printf("\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%c ", tabuleiro[i][j]);

                if (j < 2)
                {
                    printf("| ");
                }
            }

            printf("\n");

            if (i < 2)
            {
                printf("------------\n");
            }
        }

        // Solicitar jogada
        printf("Jogador %c, escolha linha (1-3): ", jogadorAtual);
        scanf("%d", &linha);

        printf("Jogador %c, escolha coluna (1-3): ", jogadorAtual);
        scanf("%d", &coluna);

        // Transformar em matriz
        linha--;
        coluna--;

        // Validação
        if (tabuleiro[linha][coluna] != vazio)
        {
            printf("Posicao ocupada! Tente novamente.\n");
            continue;
        }

        // Atualizar tabuleiro
        tabuleiro[linha][coluna] = jogadorAtual;
        jogadas++;

        // =============== 3. Verificar vitoria

        // Linhas
        for (i = 0; i < 3; i++)
        {
            if (tabuleiro[i][0] == jogadorAtual &&
                tabuleiro[i][1] == jogadorAtual &&
                tabuleiro[i][2] == jogadorAtual)
            {
                vencedor = 1;
            }
        }

        // Colunas
        for (i = 0; i < 3; i++)
        {
            if (tabuleiro[0][i] == jogadorAtual &&
                tabuleiro[1][i] == jogadorAtual &&
                tabuleiro[2][i] == jogadorAtual)
            {
                vencedor = 1;
            }
        }

        // Diagonal principal
        if (tabuleiro[0][0] == jogadorAtual &&
            tabuleiro[1][1] == jogadorAtual &&
            tabuleiro[2][2] == jogadorAtual)
        {
            vencedor = 1;
        }

        // Diagonal secundaria
        if (tabuleiro[0][2] == jogadorAtual &&
            tabuleiro[1][1] == jogadorAtual &&
            tabuleiro[2][0] == jogadorAtual)
        {
            vencedor = 1;
        }

        // Alternar jogador
        if (jogadorAtual == 'X')
        {
            jogadorAtual = 'O';
        }
        else
        {
            jogadorAtual = 'X';
        }
    }
    // Mostrar tabuleiro final
    printf("\nTabuleiro final:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %c ", tabuleiro[i][j]);

            if (j < 2)
            {
                printf("|");
            }
        }

        printf("\n");

        if (i < 2)
        {
            printf("------------\n");
        }
    }

    // =============== 4. Resultado final
    if (vencedor)
    {
        if (jogadorAtual == 'X')
        {
            printf("O jogador O venceu!\n");
        }
        else
        {
            printf("O jogador X venceu!\n");
        }
    }
    else
    {
        printf("O jogo terminou em empate.\n");
    }

    return 0;
}
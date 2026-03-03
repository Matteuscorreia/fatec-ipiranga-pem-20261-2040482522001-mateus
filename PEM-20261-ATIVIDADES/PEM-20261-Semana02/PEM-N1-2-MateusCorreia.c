#include <stdio.h>
#include <string.h>

int main()
{
    char frase[50];
    int tamanho, i, contadorPalavras=1;
    
    /* Entrada de dados */
    printf("Digite a frase: ");
    fgets(frase, sizeof(frase), stdin);
    // Remove \n (enter)
    frase[strcspn(frase, "\n")] = '\0';
    
    // Obster o tamanho da frase (qtf. bytes)
    tamanho = strlen(frase);
    
    for(i=0; i<tamanho; i++){
        if(frase[i] == ' '){
            if(frase[i + 1] != ' '){
                contadorPalavras += 1;
            }
        }
    }
    
    printf("A frase '%s' possui %d palavras",frase, contadorPalavras);
    return 0;
}
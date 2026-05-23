#include <stdio.h>
#include "stringutil.h"

int main() {

    char str1[] = "radar";
    char str2[] = "programacao";

    printf("Quantidade de vogais em '%s': %d\n",
           str1,
           contaVogais(str1));

    printf("Quantidade de vogais em '%s': %d\n",
           str2,
           contaVogais(str2));

    inverteCString(str2);

    printf("\nString invertida: %s\n", str2);

    if (ePalindromo(str1)) {
        printf("\n%s eh palindromo\n", str1);
    } else {
        printf("\n%s nao eh palindromo\n", str1);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include "stringutil.h"

int contaVogais(char *s) {

    int cont = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        char c = s[i];

        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' ||
            c == 'O' || c == 'U') {

            cont++;
        }
    }

    return cont;
}

void inverteCString(char *s) {

    int tam = strlen(s);

    for (int i = 0; i < tam / 2; i++) {

        char temp = s[i];
        s[i] = s[tam - 1 - i];
        s[tam - 1 - i] = temp;
    }
}

int ePalindromo(char *s) {

    int tam = strlen(s);

    for (int i = 0; i < tam / 2; i++) {

        if (s[i] != s[tam - 1 - i]) {
            return 0;
        }
    }

    return 1;
}
#include <stdio.h>

int mdc(int a, int b);
int potencia(int base, int exp);
int primo(int n);
void decimalBinario(int n);

int mdc(int a, int b) {

    while (b != 0) {

        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int potencia(int base, int exp) {

    int resultado = 1;

    for (int i = 0; i < exp; i++) {
        resultado *= base;
    }

    return resultado;
}

int primo(int n) {

    if (n <= 1)
        return 0;

    for (int i = 2; i < n; i++) {

        if (n % i == 0)
            return 0;
    }

    return 1;
}

void decimalBinario(int n) {

    int bin[32];
    int i = 0;

    while (n > 0) {

        bin[i] = n % 2;
        n /= 2;
        i++;
    }

    printf("Binario: ");

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }

    printf("\n");
}

int main() {

    int op;

    do {

        printf("\n===== MENU =====\n");
        printf("1 - MDC\n");
        printf("2 - Potencia\n");
        printf("3 - Numero Primo\n");
        printf("4 - Decimal para Binario\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &op);

        if (op == 1) {

            int a, b;

            printf("Digite dois numeros: ");
            scanf("%d %d", &a, &b);

            printf("MDC = %d\n", mdc(a, b));
        }

        else if (op == 2) {

            int base, exp;

            printf("Digite base e expoente: ");
            scanf("%d %d", &base, &exp);

            printf("Resultado = %d\n", potencia(base, exp));
        }

        else if (op == 3) {

            int n;

            printf("Digite um numero: ");
            scanf("%d", &n);

            if (primo(n))
                printf("Numero primo\n");
            else
                printf("Nao eh primo\n");
        }

        else if (op == 4) {

            int n;

            printf("Digite um numero decimal: ");
            scanf("%d", &n);

            decimalBinario(n);
        }

    } while (op != 0);

    return 0;
}
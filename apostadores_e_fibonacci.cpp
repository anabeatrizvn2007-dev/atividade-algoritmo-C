#include <stdio.h>

int fibonacci(int n) {
    int a = 0, b = 1, soma = 0;

    for(int i = 0; i < n; i++) {
        soma = soma + a;

        int temp = a + b;
        a = b;
        b = temp;
    }

    return soma;
}

int primo(int n) {
    if(n < 2)
        return 0;

    for(int i = 2; i < n; i++) {
        if(n % i == 0)
            return 0;
    }

    return 1;
}

int main() {
    char nomes[5][30];
    int valores[5], resultados[5];
    int ganhou[5] = {0};

    for(int i = 0; i < 5; i++) {
        printf("\nNome: ");
        scanf("%s", nomes[i]);

        printf("Quantidade de termos: ");
        scanf("%d", &valores[i]);

        resultados[i] = fibonacci(valores[i]);
    }

    // Primeiro lugar: maior resultado primo
    int primeiro = -1;

    for(int i = 0; i < 5; i++) {
        if(primo(resultados[i])) {
            if(primeiro == -1 ||
               resultados[i] > resultados[primeiro]) {
                primeiro = i;
            }
        }
    }

    if(primeiro != -1)
        ganhou[primeiro] = 1;

    // Segundo lugar: maior resultado par
    int segundo = -1;

    for(int i = 0; i < 5; i++) {
        if(ganhou[i] == 0 && resultados[i] % 2 == 0) {
            if(segundo == -1 ||
               resultados[i] > resultados[segundo]) {
                segundo = i;
            }
        }
    }

    if(segundo != -1)
        ganhou[segundo] = 1;

    // Calcular media
    float soma = 0;

    for(int i = 0; i < 5; i++) {
        soma = soma + resultados[i];
    }

    float media = soma / 5;

    // Terceiro lugar: maior acima da media
    int terceiro = -1;

    for(int i = 0; i < 5; i++) {
        if(ganhou[i] == 0 && resultados[i] > media) {
            if(terceiro == -1 ||
               resultados[i] > resultados[terceiro]) {
                terceiro = i;
            }
        }
    }

    printf("\nVencedores:\n");

    if(primeiro != -1)
        printf("1 lugar: %s\n", nomes[primeiro]);
    else
        printf("1 lugar: Sem vencedor\n");

    if(segundo != -1)
        printf("2 lugar: %s\n", nomes[segundo]);
    else
        printf("2 lugar: Sem vencedor\n");

    if(terceiro != -1)
        printf("3 lugar: %s\n", nomes[terceiro]);
    else
        printf("3 lugar: Sem vencedor\n");

    return 0;
}

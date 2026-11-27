#include <stdio.h>
#include <string.h>

struct Apostador {
    char nome[50];
    int valor;
    long long resultado;
    int premiado;
};

long long calcularFibonacci(int n) {
    int i;
    long long a = 0, b = 1, c, soma = 0;

    for (i = 0; i < n; i++) {
        soma += a;

        c = a + b;
        a = b;
        b = c;
    }

    return soma;
}

int ehPrimo(long long n) {
    long long i;

    if (n < 2) {
        return 0;
    }

    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    struct Apostador a[5];
    int i, primeiro = -1, segundo = -1, terceiro = -1;
    long long soma = 0;
    float media;

    for (i = 0; i < 5; i++) {
        a[i].premiado = 0;

        printf("Nome do apostador: ");
        scanf(" %49[^\n]", a[i].nome);

        do {
            printf("Digite um valor positivo: ");
            scanf("%d", &a[i].valor);
        } while (a[i].valor <= 0);

        a[i].resultado = calcularFibonacci(a[i].valor);

        soma += a[i].resultado;
    }

    media = soma / 5.0;

    // Primeiro lugar: maior resultado primo.
    for (i = 0; i < 5; i++) {
        if (ehPrimo(a[i].resultado)) {
            if (primeiro == -1 ||
                a[i].resultado > a[primeiro].resultado) {
                primeiro = i;
            }
        }
    }

    if (primeiro != -1) {
        a[primeiro].premiado = 1;
    }

    // Segundo lugar: maior resultado par.
    for (i = 0; i < 5; i++) {
        if (!a[i].premiado && a[i].resultado % 2 == 0) {
            if (segundo == -1 ||
                a[i].resultado > a[segundo].resultado) {
                segundo = i;
            }
        }
    }

    if (segundo != -1) {
        a[segundo].premiado = 1;
    }

    // Terceiro lugar: maior resultado acima da media.
    for (i = 0; i < 5; i++) {
        if (!a[i].premiado && a[i].resultado > media) {
            if (terceiro == -1 ||
                a[i].resultado > a[terceiro].resultado) {
                terceiro = i;
            }
        }
    }

    printf("\n===== RESULTADO =====\n");

    if (primeiro != -1) {
        printf("1 lugar: %s\n", a[primeiro].nome);
    } else {
        printf("1 lugar: Sem vencedor\n");
    }

    if (segundo != -1) {
        printf("2 lugar: %s\n", a[segundo].nome);
    } else {
        printf("2 lugar: Sem vencedor\n");
    }

    if (terceiro != -1) {
        printf("3 lugar: %s\n", a[terceiro].nome);
    } else {
        printf("3 lugar: Sem vencedor\n");
    }

    return 0;
}

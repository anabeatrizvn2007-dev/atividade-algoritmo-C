#include <stdio.h>
#include <string.h>

#define MAX 100

struct Participante {
    char nome[50];
    int idade;
    unsigned long long id;
    double media;
};

unsigned long long fatorial(int n) {
    int i;
    unsigned long long fat = 1;

    for (i = 1; i <= n; i++) {
        fat *= i;
    }

    return fat;
}

int idRepetido(struct Participante p[], int atual,
               unsigned long long id) {
    int i;

    for (i = 0; i < atual; i++) {
        if (p[i].id == id) {
            return 1;
        }
    }

    return 0;
}

double calcularMediaPonderada(double valores[], int qtd) {
    int i;
    double soma = 0, pesos = 0;

    for (i = 0; i < qtd; i++) {
        soma += valores[i] * (i + 1);
        pesos += i + 1;
    }

    return soma / pesos;
}

int main() {
    struct Participante p[4], aux;
    double valores[4][MAX];
    double diagonal, lado1 = -1, lado2 = -1;
    int qtd, i, j, k, idade, repetir;

    for (i = 0; i < 4; i++) {
        printf("\nNome: ");
        scanf(" %49[^\n]", p[i].nome);

        printf("Idade: ");
        scanf("%d", &p[i].idade);

        p[i].id = fatorial(p[i].idade) / 2;

        repetir = 1;

        while (repetir) {
            if (!idRepetido(p, i, p[i].id)) {
                repetir = 0;
            } else {
                idade = p[i].idade / 2;
                p[i].id = fatorial(idade) / 2;

                // A atividade determina elevar o fatorial
                // a quantidade de valores capturados.
                // O cálculo definitivo será feito após a leitura.
                if (i > 0 && p[i].id == p[i - 1].id) {
                    printf("ID repetido. Informe outra idade: ");
                    scanf("%d", &p[i].idade);
                    p[i].id = fatorial(p[i].idade) / 2;
                }
            }
        }
    }

    printf("\nQuantidade de valores por participante: ");
    scanf("%d", &qtd);

    if (qtd < 1 || qtd > MAX) {
        printf("Quantidade invalida.\n");
        return 0;
    }

    for (i = 0; i < 4; i++) {
        printf("\nValores de %s:\n", p[i].nome);

        for (j = 0; j < qtd; j++) {
            printf("Valor %d: ", j + 1);
            scanf("%lf", &valores[i][j]);

            if (valores[i][j] >= 0) {
                if (lado1 == -1) {
                    lado1 = valores[i][j];
                } else if (lado2 == -1) {
                    lado2 = valores[i][j];
                }
            }
        }

        p[i].media = calcularMediaPonderada(valores[i], qtd);
    }

    // Ordenar os participantes e manter seus valores associados.
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (strcmp(p[i].nome, p[j].nome) > 0) {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;

                for (k = 0; k < qtd; k++) {
                    double temp = valores[i][k];
                    valores[i][k] = valores[j][k];
                    valores[j][k] = temp;
                }
            }
        }
    }

    printf("\n===== CLASSIFICACAO =====\n");

    if (lado1 == -1 || lado2 == -1) {
        printf("Nao foi possivel calcular a diagonal.\n");
    } else {
        // Teorema de Pitagoras.
        // Sem utilizar sqrt, a raiz sera aproximada por Newton.
        double x = lado1 * lado1 + lado2 * lado2;
        double raiz = x;

        if (x == 0) {
            raiz = 0;
        } else {
            for (i = 0; i < 50; i++) {
                raiz = (raiz + x / raiz) / 2;
            }
        }

        diagonal = raiz;

        printf("Diagonal: %.2f\n", diagonal);

        for (i = 0; i < 4; i++) {
            printf("%s - ", p[i].nome);

            if (p[i].media > diagonal) {
                printf("Acima da diagonal\n");
            } else if (p[i].media < diagonal) {
                printf("Abaixo da diagonal\n");
            } else {
                printf("Sobre a diagonal\n");
            }
        }
    }

    return 0;
}

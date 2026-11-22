
#include <stdio.h>
#include <stdlib.h>

#define N 12

typedef struct {
    char nome[50];
    float preco;
} Produto;

/* Converte letra maiuscula em minuscula */
char minuscula(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;

    return c;
}

/* Compara nomes sem diferenciar maiusculas e minusculas */
int compara(char a[], char b[]) {
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0' &&
           minuscula(a[i]) == minuscula(b[i])) {
        i++;
    }

    return minuscula(a[i]) - minuscula(b[i]);
}

int main() {

    int v[N];
    int valores[N], qtds[N];

    int *pares;
    int *impares;
    Produto *produtos;

    int nd = 0;
    int np = 0;
    int npar = 0;
    int nimpar = 0;

    int i, j, temp;
    Produto aux;

    /* Leitura dos 12 numeros */
    for (i = 0; i < N; i++) {
        printf("Digite o numero %d: ", i + 1);

        if (scanf("%d", &v[i]) != 1) {
            printf("Entrada invalida!\n");
            return 1;
        }
    }

    /* Conta quantas vezes cada numero aparece */
    for (i = 0; i < N; i++) {

        for (j = 0; j < nd; j++) {

            if (valores[j] == v[i]) {
                qtds[j]++;
                break;
            }
        }

        if (j == nd) {
            valores[nd] = v[i];
            qtds[nd] = 1;
            nd++;
        }
    }

    /* Alocacao dinamica */
    produtos = (Produto *) malloc(nd * sizeof(Produto));
    pares = (int *) malloc(nd * sizeof(int));
    impares = (int *) malloc(nd * sizeof(int));

    if (produtos == NULL || pares == NULL || impares == NULL) {
        printf("Erro ao alocar memoria!\n");

        free(produtos);
        free(pares);
        free(impares);

        return 1;
    }

    /* Separa numeros pares e impares */
    for (i = 0; i < nd; i++) {

        if (qtds[i] % 2 != 0) {

            /* Armazena numero com ocorrencia impar */
            impares[nimpar] = valores[i];
            nimpar++;

            /* Cadastro do produto */
            printf("\nCadastro do produto para o numero %d\n",
                   valores[i]);

            printf("Aparece %d vez(es)\n", qtds[i]);

            printf("Nome: ");
            scanf(" %49[^\n]", produtos[np].nome);

            printf("Preco unitario: ");

            if (scanf("%f", &produtos[np].preco) != 1) {
                printf("Preco invalido!\n");

                free(produtos);
                free(pares);
                free(impares);

                return 1;
            }

            np++;

        } else {

            /* Armazena numero com ocorrencia par */
            pares[npar] = valores[i];
            npar++;
        }
    }

    /* Ordena numeros pares em ordem decrescente */
    for (i = 0; i < npar - 1; i++) {

        for (j = 0; j < npar - 1 - i; j++) {

            if (pares[j] < pares[j + 1]) {

                temp = pares[j];
                pares[j] = pares[j + 1];
                pares[j + 1] = temp;
            }
        }
    }

    /* Ordena produtos em ordem alfabetica */
    for (i = 0; i < np - 1; i++) {

        for (j = 0; j < np - 1 - i; j++) {

            if (compara(produtos[j].nome,
                        produtos[j + 1].nome) > 0) {

                aux = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = aux;
            }
        }
    }

    /* Apresentacao dos resultados */

    printf("\n=== NUMEROS INFORMADOS ===\n");

    for (i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }

    printf("\n\n=== OCORRENCIAS DE CADA NUMERO ===\n");

    for (i = 0; i < nd; i++) {
        printf("Numero %d: %d vez(es)\n",
               valores[i], qtds[i]);
    }

    printf("\n=== NUMEROS COM OCORRENCIA IMPAR ===\n");

    for (i = 0; i < nimpar; i++) {
        printf("%d ", impares[i]);
    }

    printf("\n");

    printf("\n=== NUMEROS COM OCORRENCIA PAR (DECRESCENTE) ===\n");

    for (i = 0; i < npar; i++) {
        printf("%d ", pares[i]);
    }

    printf("\n");

    printf("\n=== PRODUTOS PARA COMPRA (ORDEM ALFABETICA) ===\n");

    for (i = 0; i < np; i++) {
        printf("%s - R$ %.2f\n",
               produtos[i].nome, produtos[i].preco);
    }

    /* Libera memoria */
    free(produtos);
    free(pares);
    free(impares);

    return 0;
}


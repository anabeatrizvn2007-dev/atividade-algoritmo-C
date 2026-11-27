#include <stdio.h>

struct Produto {
    int codigo;
    char nome[50];
    float preco;
};

int main() {
    struct Produto produtos[3];
    struct Produto p;
    FILE *arquivo;
    int i;

    for (i = 0; i < 3; i++) {
        printf("\nCodigo: ");
        scanf("%d", &produtos[i].codigo);

        printf("Nome: ");
        scanf(" %49[^\n]", produtos[i].nome);

        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
    }

    arquivo = fopen("estoque.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo.\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        fprintf(arquivo, "%d %s %.2f\n",
                produtos[i].codigo,
                produtos[i].nome,
                produtos[i].preco);
    }

    fclose(arquivo);

    arquivo = fopen("estoque.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    printf("\n===== ESTOQUE =====\n");

    while (fscanf(arquivo, "%d %49s %f",
                  &p.codigo, p.nome, &p.preco) == 3) {
        printf("\nCodigo: %d", p.codigo);
        printf("\nNome: %s", p.nome);
        printf("\nPreco: R$ %.2f\n", p.preco);
    }

    fclose(arquivo);

    return 0;
}

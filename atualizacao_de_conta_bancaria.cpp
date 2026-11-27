#include <stdio.h>

struct Cliente {
    int conta_corrente;
    char nome[50];
    float saldo;
};

int main() {
    struct Cliente cliente;
    FILE *arquivo;
    int conta, encontrado = 0;
    float valor;

    printf("Digite o numero da conta: ");
    scanf("%d", &conta);

    printf("Digite o valor (positivo para deposito e negativo para saque): ");
    scanf("%f", &valor);

    arquivo = fopen("clientes.bin", "rb+");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo clientes.bin.\n");
        return 1;
    }

    while (fread(&cliente, sizeof(struct Cliente), 1, arquivo) == 1) {

        if (cliente.conta_corrente == conta) {

            cliente.saldo += valor;

            fseek(arquivo, -(long)sizeof(struct Cliente), SEEK_CUR);

            fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);

            encontrado = 1;

            printf("\nConta atualizada!\n");
            printf("Cliente: %s\n", cliente.nome);
            printf("Novo saldo: R$ %.2f\n", cliente.saldo);

            break;
        }
    }

    if (!encontrado) {
        printf("Conta nao encontrada.\n");
    }

    fclose(arquivo);

    return 0;
}

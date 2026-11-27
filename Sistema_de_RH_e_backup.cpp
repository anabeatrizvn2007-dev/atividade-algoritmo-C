#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Funcionario {
    int id;
    char cargo[30];
    float salario;
};

int main() {
    struct Funcionario *funcionario;
    struct Funcionario *backup;
    FILE *arquivo;

    funcionario = (struct Funcionario*)
        malloc(sizeof(struct Funcionario));

    backup = (struct Funcionario*)
        malloc(sizeof(struct Funcionario));

    if (funcionario == NULL || backup == NULL) {
        printf("Erro na alocacao de memoria.\n");

        free(funcionario);
        free(backup);

        return 1;
    }

    printf("ID do funcionario: ");
    scanf("%d", &funcionario->id);

    printf("Cargo: ");
    scanf(" %29[^\n]", funcionario->cargo);

    printf("Salario: ");
    scanf("%f", &funcionario->salario);

    memcpy(backup, funcionario, sizeof(struct Funcionario));

    arquivo = fopen("backup_rh.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo.\n");

        free(funcionario);
        free(backup);

        return 1;
    }

    fwrite(backup, sizeof(struct Funcionario), 1, arquivo);

    fclose(arquivo);

    printf("\nBackup realizado com sucesso!\n");

    free(funcionario);
    free(backup);

    return 0;
}

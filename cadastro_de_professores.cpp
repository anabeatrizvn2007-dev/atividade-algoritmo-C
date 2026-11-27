#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Professor {
    int registro;
    int horas_aula;
};

int main() {
    struct Professor *professores;
    struct Professor *buffer;
    struct Professor *leitura;
    FILE *arquivo;

    int n, i;

    printf("Quantidade de professores: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    professores = (struct Professor*)
        malloc(n * sizeof(struct Professor));

    buffer = (struct Professor*)
        malloc(n * sizeof(struct Professor));

    if (professores == NULL || buffer == NULL) {
        printf("Erro na alocacao.\n");

        free(professores);
        free(buffer);

        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nRegistro do professor: ");
        scanf("%d", &professores[i].registro);

        printf("Horas de aula: ");
        scanf("%d", &professores[i].horas_aula);
    }

    memcpy(buffer, professores,
           n * sizeof(struct Professor));

    arquivo = fopen("folha.dat", "wb");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo.\n");

        free(professores);
        free(buffer);

        return 1;
    }

    fwrite(buffer, sizeof(struct Professor), n, arquivo);

    fclose(arquivo);

    // Leitura dos dados.
    leitura = (struct Professor*)
        malloc(n * sizeof(struct Professor));

    if (leitura == NULL) {
        printf("Erro na alocacao da leitura.\n");

        free(professores);
        free(buffer);

        return 1;
    }

    arquivo = fopen("folha.dat", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");

        free(professores);
        free(buffer);
        free(leitura);

        return 1;
    }

    fread(leitura, sizeof(struct Professor), n, arquivo);

    printf("\n===== PROFESSORES =====\n");

    for (i = 0; i < n; i++) {
        printf("\nRegistro: %d", leitura[i].registro);
        printf("\nHoras de aula: %d\n", leitura[i].horas_aula);
    }

    fclose(arquivo);

    free(professores);
    free(buffer);
    free(leitura);

    return 0;
}

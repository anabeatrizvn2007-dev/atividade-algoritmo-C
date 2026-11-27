#include <stdio.h>
#include <stdlib.h>

struct Eleitor {
    char titulo[12];
    int zona;
};

struct Cedula {
    struct Eleitor eleitor;
    int numero_voto;
};

int main() {
    struct Cedula *votos = NULL;
    struct Cedula *recuperados;
    struct Cedula *temp;

    FILE *arquivo;

    int quantidade = 0;
    int i;
    long tamanho;
    int total;

    char continuar;

    do {
        temp = (struct Cedula*)
            realloc(votos, (quantidade + 1) * sizeof(struct Cedula));

        if (temp == NULL) {
            printf("Erro ao alocar memoria.\n");
            free(votos);
            return 1;
        }

        votos = temp;

        printf("\nTitulo de eleitor: ");
        scanf(" %11s", votos[quantidade].eleitor.titulo);

        printf("Zona eleitoral: ");
        scanf("%d", &votos[quantidade].eleitor.zona);

        printf("Numero do voto: ");
        scanf("%d", &votos[quantidade].numero_voto);

        quantidade++;

        printf("\nDeseja cadastrar outro voto? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    // Gravar os votos.
    arquivo = fopen("urnas.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao criar arquivo.\n");
        free(votos);
        return 1;
    }

    fwrite(votos, sizeof(struct Cedula), quantidade, arquivo);

    fclose(arquivo);

    // Recuperar os registros.
    arquivo = fopen("urnas.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        free(votos);
        return 1;
    }

    fseek(arquivo, 0, SEEK_END);

    tamanho = ftell(arquivo);

    rewind(arquivo);

    total = tamanho / sizeof(struct Cedula);

    recuperados = (struct Cedula*)
        malloc(tamanho);

    if (recuperados == NULL && tamanho > 0) {
        printf("Erro na alocacao.\n");

        fclose(arquivo);
        free(votos);

        return 1;
    }

    fread(recuperados, sizeof(struct Cedula), total, arquivo);

    printf("\n===== VOTOS REGISTRADOS =====\n");

    for (i = 0; i < total; i++) {
        printf("\nTitulo: %s", recuperados[i].eleitor.titulo);
        printf("\nZona: %d", recuperados[i].eleitor.zona);
        printf("\nNumero do voto: %d\n",
               recuperados[i].numero_voto);
    }

    fclose(arquivo);

    free(votos);
    free(recuperados);

    return 0;
}

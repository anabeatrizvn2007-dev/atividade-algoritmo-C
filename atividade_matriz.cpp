
#include <stdio.h>

int main() {
    float notas[3][4];
    int i, j;

    // Leitura das notas dos 3 alunos
    for (i = 0; i < 3; i++) {
        printf("\nAluno %d\n", i + 1);

        for (j = 0; j < 3; j++) {
            printf("Digite a nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }

        // Calculo da media
        notas[i][3] = (notas[i][0] +
                       notas[i][1] +
                       notas[i][2]) / 3;
    }

    // Exibicao da tabela
    printf("\nAluno\tNota1\tNota2\tNota3\tMedia\n");

    for (i = 0; i < 3; i++) {
        printf("%d\t", i + 1);

        for (j = 0; j < 4; j++) {
            printf("%.1f\t", notas[i][j]);
        }

        printf("\n");
    }

    return 0;
}


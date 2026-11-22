#include <stdio.h>
#include <string.h>


using namespace std;

long long fatorial(int n) {
    long long fat = 1;

    for(int i = 1; i <= n; i++) {
        fat = fat * i;
    }

    return fat;
}

double diagonal(double a, double b) {
    double resultado = a * a + b * b;

    // Aproximacao da raiz quadrada
    double x = resultado;

    for(int i = 0; i < 20; i++) {
        x = (x + resultado / x) / 2;
    }

    return x;
}

int main() {
    char nome[4][30];
    int idade[4];
    long long id[4];

    double valores[4][100];
    int qtd[4];

    double media[4];
    char classificacao[4][30];

    // Cadastro
    for(int i = 0; i < 4; i++) {
        printf("\nParticipante %d\n", i + 1);

        printf("Nome: ");
        scanf("%s", nome[i]);

        printf("Idade: ");
        scanf("%d", &idade[i]);

        printf("Quantidade de valores (maximo 100): ");
        scanf("%d", &qtd[i]);

        if(qtd[i] > 100)
            qtd[i] = 100;

        if(qtd[i] < 1)
            qtd[i] = 1;

        // ID inicial
        id[i] = fatorial(idade[i]) / 2;

        // Verificar IDs repetidos
        for(int j = 0; j < i; j++) {
            if(id[i] == id[j]) {
                id[i] = fatorial(idade[i] / 2);

                for(int k = 0; k < qtd[i]; k++) {
                    id[i] = id[i] * fatorial(idade[i] / 2);
                }

                // Se ainda repetir, incrementar
                while(1) {
                    int repetido = 0;

                    for(int k = 0; k < i; k++) {
                        if(id[i] == id[k])
                            repetido = 1;
                    }

                    if(repetido == 0)
                        break;

                    id[i]++;
                }
            }
        }

        // Captura dos valores
        for(int j = 0; j < qtd[i]; j++) {
            printf("Valor %d: ", j + 1);
            scanf("%lf", &valores[i][j]);
        }

        // Media ponderada
        double soma = 0, pesos = 0;

        for(int j = 0; j < qtd[i]; j++) {
            soma = soma + valores[i][j] * (j + 1);
            pesos = pesos + (j + 1);
        }

        media[i] = soma / pesos;
    }

    // Ordenar participantes por nome
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 4; j++) {
            if(strcmp(nome[i], nome[j]) > 0) {
                char tempNome[30];
                strcpy(tempNome, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], tempNome);

                int tempIdade = idade[i];
                idade[i] = idade[j];
                idade[j] = tempIdade;

                long long tempID = id[i];
                id[i] = id[j];
                id[j] = tempID;

                double tempMedia = media[i];
                media[i] = media[j];
                media[j] = tempMedia;

                int tempQtd = qtd[i];
                qtd[i] = qtd[j];
                qtd[j] = tempQtd;

                for(int k = 0; k < 100; k++) {
                    double temp = valores[i][k];
                    valores[i][k] = valores[j][k];
                    valores[j][k] = temp;
                }
            }
        }
    }

    // Encontrar dois valores nao negativos
    double lado1 = 0, lado2 = 0;
    int encontrados = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < qtd[i]; j++) {
            if(valores[i][j] >= 0 && encontrados < 2) {
                if(encontrados == 0)
                    lado1 = valores[i][j];
                else
                    lado2 = valores[i][j];

                encontrados++;
            }
        }
    }

    double d = 0;

    if(encontrados == 2) {
        d = diagonal(lado1, lado2);
        printf("\nDiagonal: %.2lf\n", d);
    }
    else {
        printf("\nNao foi possivel calcular a diagonal.\n");
    }

    // Classificacao
    for(int i = 0; i < 4; i++) {
        if(encontrados < 2) {
            strcpy(classificacao[i], "Sem classificacao");
        }
        else if(media[i] > d) {
            strcpy(classificacao[i], "Acima");
        }
        else if(media[i] < d) {
            strcpy(classificacao[i], "Abaixo");
        }
        else {
            strcpy(classificacao[i], "Sobre");
        }
    }

    // Resultado
    printf("\nClassificacao final:\n");

    for(int i = 0; i < 4; i++) {
        printf("%s - %s\n", nome[i], classificacao[i]);
    }

    return 0;
}

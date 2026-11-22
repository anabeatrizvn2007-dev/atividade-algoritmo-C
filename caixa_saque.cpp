#include <stdio.h>

int main()
{
    int saque;
    int n200, n100, n50, n20, n10, n5;
    int q200, q100, q50, q20, q10, q5;
    int restante;
    int totalCedulas;

    printf("Quantidade de notas de R$ 200: ");
    scanf("%d", &n200);

    printf("Quantidade de notas de R$ 100: ");
    scanf("%d", &n100);

    printf("Quantidade de notas de R$ 50: ");
    scanf("%d", &n50);

    printf("Quantidade de notas de R$ 20: ");
    scanf("%d", &n20);

    printf("Quantidade de notas de R$ 10: ");
    scanf("%d", &n10);

    printf("Quantidade de notas de R$ 5: ");
    scanf("%d", &n5);

    printf("\nDigite o valor do saque: R$ ");
    scanf("%d", &saque);

    if(saque <= 0)
    {
        printf("\nValor de saque invalido.\n");
    }
    else if(saque % 5 != 0)
    {
        printf("\nNao e possivel realizar o saque.\n");
        printf("O valor deve ser multiplo de R$ 5.\n");
    }
    else
    {
        restante = saque;

        // Comeca usando as maiores notas
        q200 = 0;
        q100 = 0;
        q50 = 0;
        q20 = 0;
        q10 = 0;
        q5 = 0;

        while(restante >= 200 && n200 > 1)
        {
            q200++;
            n200--;
            restante -= 200;
        }

        while(restante >= 100 && n100 > 1)
        {
            q100++;
            n100--;
            restante -= 100;
        }

        while(restante >= 50 && n50 > 1)
        {
            q50++;
            n50--;
            restante -= 50;
        }

        while(restante >= 20 && n20 > 1)
        {
            q20++;
            n20--;
            restante -= 20;
        }

        while(restante >= 10 && n10 > 1)
        {
            q10++;
            n10--;
            restante -= 10;
        }

        while(restante >= 5 && n5 > 1)
        {
            q5++;
            n5--;
            restante -= 5;
        }

        if(restante != 0)
        {
            printf("\nNao e possivel realizar o saque.\n");
            printf("O caixa nao consegue realizar o saque sem violar a regra.\n");
        }
        else
        {
            totalCedulas = q200 + q100 + q50 + q20 + q10 + q5;

            printf("\n=== SAQUE REALIZADO ===\n");

            printf("Notas de R$ 200: %d\n", q200);
            printf("Notas de R$ 100: %d\n", q100);
            printf("Notas de R$ 50: %d\n", q50);
            printf("Notas de R$ 20: %d\n", q20);
            printf("Notas de R$ 10: %d\n", q10);
            printf("Notas de R$ 5: %d\n", q5);

            printf("Quantidade total de cedulas: %d\n", totalCedulas);
        }
    }

    return 0;
}

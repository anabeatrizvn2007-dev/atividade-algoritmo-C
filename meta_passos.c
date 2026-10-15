#include <stdio.h>

int main ()
{
    int passos, total = 0, horas = 0;

    while (total < 10000)
    {
        printf("Digite os passos da hora %d: ", horas + 1);

        if (scanf("%d", &passos) != 1)
        {
            printf("Entrada invalida.\n");
            return 1;
        }

        if (passos < 0)
        {
            printf("A quantidade de passos nao pode ser negativa.\n\n");
        }
        else
        {
            total += passos;
            horas++;
        }
    }

    printf("\nMeta atingida!\n");
    printf("Total de passos: %d\n", total);
    printf("Horas necessarias: %d\n", horas);

    return 0;
}

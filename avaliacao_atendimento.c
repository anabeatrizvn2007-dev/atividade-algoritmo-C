#include <stdio.h>

int main ()
{
    int cliente;
    float nota, soma = 0, media;

    for (cliente = 1; cliente <= 10; cliente++)
    {
        printf("Digite a nota do cliente %d (0 a 10): ", cliente);

        if (scanf("%f", &nota) != 1)
        {
            printf("Entrada invalida.\n");
            return 1;
        }

        if (nota < 0 || nota > 10)
        {
            printf("Nota invalida. Digite um valor de 0 a 10.\n\n");
            cliente--;
        }
        else
        {
            soma += nota;
        }
    }

    media = soma / 10;

    printf("\nMedia geral do atendimento: %.2f\n", media);

    if (media < 7)
    {
        printf("ALERTA: o atendimento precisa melhorar!\n");
    }

    return 0;
}

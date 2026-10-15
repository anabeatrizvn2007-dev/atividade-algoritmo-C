#include <stdio.h>

int main()
{
    int morador;
    float consumo, soma = 0, media;

    for (morador = 1; morador <= 5; morador++)
    {
        printf("Consumo do morador %d (em m3): ", morador);

        if (scanf("%f", &consumo) != 1 || consumo < 0)
        {
            printf("Consumo invalido.\n");
            return 1;
        }

        soma += consumo;

        if (consumo <= 20)
        {
            printf("Morador %d: dentro da media.\n\n", morador);
        }
        else
        {
            printf("Morador %d: acima da media.\n\n", morador);
        }
    }

    media = soma / 5;

    printf("Consumo medio geral: %.2f m3\n", media);

    return 0;
}

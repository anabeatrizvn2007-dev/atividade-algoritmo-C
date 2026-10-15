#include <stdio.h>

int main()
{
    int a, b, c;
    int temp;

    printf("Digite o primeiro lado: ");
    scanf("%d", &a);

    printf("Digite o segundo lado: ");
    scanf("%d", &b);

    printf("Digite o terceiro lado: ");
    scanf("%d", &c);

    // Verificar se os lados formam um triangulo
    if (a <= 0 || b <= 0 || c <= 0 ||
        a + b <= c || a + c <= b || b + c <= a)
    {
        printf("nos valores nao formam um triangulo.\n");
    }
    else
    {
        // Classificacao quanto aos lados
        if (a == b && b == c)
        {
            printf("Triangulo equilatero.\n");
        }
        else if (a == b || a == c || b == c)
        {
            printf("Triangulo isosceles.\n");
        }
        else
        {
            printf("Triangulo escaleno.\n");
        }

        // Classificacao quanto aos angulos
        if (a * a + b * b > c * c)
        {
            printf("Triangulo acutangulo.\n");
        }
        else if (a * a + b * b == c * c)
        {
            printf("Triangulo retangulo.\n");
        }
        else
        {
            printf("Triangulo obtusangulo.\n");
        }
    }

    return 0;
}

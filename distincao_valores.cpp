#include <stdio.h>

int main()
{
    int A, B, C;
    int maior, menor, intermediario;

    printf("Digite o valor de A: ");
    scanf("%d", &A);

    printf("Digite o valor de B: ");
    scanf("%d", &B);

    printf("Digite o valor de C: ");
    scanf("%d", &C);

    // Encontrar o maior valor
    if(A >= B && A >= C)
    {
        maior = A;
    }
    else if(B >= A && B >= C)
    {
        maior = B;
    }
    else
    {
        maior = C;
    }

    // Encontrar o menor valor
    if(A <= B && A <= C)
    {
        menor = A;
    }
    else if(B <= A && B <= C)
    {
        menor = B;
    }
    else
    {
        menor = C;
    }

    // Encontrar o valor intermediario
    if((A >= B && A <= C) || (A <= B && A >= C))
    {
        intermediario = A;
    }
    else if((B >= A && B <= C) || (B <= A && B >= C))
    {
        intermediario = B;
    }
    else
    {
        intermediario = C;
    }

    printf("\nMaior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Valor intermediario: %d\n", intermediario);

    // Verificar valores repetidos
    if(A == B || A == C || B == C)
    {
        printf("Existem valores repetidos.\n");
    }
    else
    {
        printf("Nao existem valores repetidos.\n");
    }

    // Verificar se os tres sao iguais
    if(A == B && B == C)
    {
        printf("Os tres valores sao iguais.\n");
    }
    else
    {
        printf("Os tres valores nao sao iguais.\n");
    }

    // Verificar ordem crescente
    if(A < B && B < C)
    {
        printf("Estao em ordem crescente.\n");
    }
    else
    {
        printf("Nao estao em ordem crescente.\n");
    }

    // Verificar ordem decrescente
    if(A > B && B > C)
    {
        printf("Estao em ordem decrescente.\n");
    }
    else
    {
        printf("Nao estao em ordem decrescente.\n");
    }
    
}

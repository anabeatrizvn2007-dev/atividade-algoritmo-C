#include <stdio.h>

int main() {
    int num[10];
    int par[10], impar[10];
    int qp = 0, qi = 0;

    printf("Digite 10 numeros:\n");

    for(int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);

        if(num[i] > 0 && num[i] % 2 == 0) {
            par[qp] = num[i];
            qp++;
        }

        if(num[i] < 0 && num[i] % 2 != 0) {
            impar[qi] = num[i];
            qi++;
        }
    }

    // Ordenar positivos pares
    for(int i = 0; i < qp; i++) {
        for(int j = i + 1; j < qp; j++) {
            if(par[i] > par[j]) {
                int temp = par[i];
                par[i] = par[j];
                par[j] = temp;
            }
        }
    }

    // Ordenar negativos impares
    for(int i = 0; i < qi; i++) {
        for(int j = i + 1; j < qi; j++) {
            if(impar[i] > impar[j]) {
                int temp = impar[i];
                impar[i] = impar[j];
                impar[j] = temp;
            }
        }
    }

    printf("\nPositivos e pares:\n");

    for(int i = 0; i < qp; i++) {
        printf("%d ", par[i]);
    }

    printf("\nNegativos e impares:\n");

    for(int i = 0; i < qi; i++) {
        printf("%d ", impar[i]);
    }

    return 0;
}

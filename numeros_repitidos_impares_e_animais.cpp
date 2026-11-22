#include <stdio.h>

int main() {
    int num[15], cont[15], ver[15] = {0};
    char animais[15][30];

    printf("Digite 15 numeros:\n");

    for(int i = 0; i < 15; i++) {
        scanf("%d", &num[i]);
    }

    printf("\nCadastre 15 animais:\n");

    for(int i = 0; i < 15; i++) {
        printf("Animal %d: ", i + 1);
        scanf("%s", animais[i]);
    }

    printf("\nCorrespondencias:\n");

    for(int i = 0; i < 15; i++) {
        if(ver[i] == 0) {
            cont[i] = 0;

            for(int j = 0; j < 15; j++) {
                if(num[i] == num[j]) {
                    cont[i]++;
                    ver[j] = 1;
                }
            }

            if(cont[i] > 1) {
                printf("\nNumero %d aparece %d vezes\n",
                       num[i], cont[i]);

                // Verificar se e primo
                int primo = 1;

                if(num[i] < 2)
                    primo = 0;

                for(int j = 2; j < num[i]; j++) {
                    if(num[i] % j == 0)
                        primo = 0;
                }

                if(primo == 1 && cont[i] % 2 != 0) {
                    int soma = num[i] * cont[i];

                    printf("Soma: %d\n", soma);

                    if(soma >= 1 && soma <= 15)
                        printf("Animal: %s\n", animais[soma - 1]);
                    else
                        printf("Nao existe correspondencia\n");
                }
                else if(cont[i] % 2 == 0) {
                    printf("Animal: %s\n", animais[i]);
                }
            }
        }
    }

    return 0;
}

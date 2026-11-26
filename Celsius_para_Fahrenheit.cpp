#include <stdio.h>

float celsiusParaFahrenheit(float c) {
    return (9 * c) / 5 + 32;
}

int main() {
    float celsius, fahrenheit;

    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = celsiusParaFahrenheit(celsius);

    printf("Temperatura em Fahrenheit: %.2f\n", fahrenheit);

    return 0;
}

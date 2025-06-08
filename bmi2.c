#include <stdio.h>

int main() {
    float peso, altura, imc;
    int categoria;

    printf("Ingrese su peso en kilogramos: ");
    scanf("%f", &peso);

    printf("Ingrese su altura en metros: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);
    printf("\nSu Índice de Masa Corporal (IMC) es: %.2f\n", imc);

    printf("\nTabla de referencia del IMC:\n");
    printf("-------------------------------\n");
    printf("| Clasificación | Rango IMC   |\n");
    printf("-------------------------------\n");
    printf("| Bajo peso     | < 18.5      |\n");
    printf("| Normal        | 18.5–24.9   |\n");
    printf("| Sobrepeso     | 25.0–29.9   |\n");
    printf("| Obesidad      | >= 30.0     |\n");
    printf("-------------------------------\n");

    int imc10 = (int)(imc * 10);

    categoria = (imc10 < 185) * 0 +
                (imc10 >= 185 && imc10 <= 249) * 1 +
                (imc10 >= 250 && imc10 <= 299) * 2 +
                (imc10 >= 300) * 3;

    printf("\nUsted se encuentra en la categoría: ");
    switch (categoria) {
        case 0:
            printf("Bajo peso\n");
            break;
        case 1:
            printf("Normal\n");
            break;
        case 2:
            printf("Sobrepeso\n");
            break;
        case 3:
            printf("Obesidad\n");
            break;
        default:
            printf("Error en la clasificación\n");
            break;
    }
    return 0;
}

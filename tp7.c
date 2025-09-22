#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(void) {
    int codigos[TAM];
    float precios[TAM];
    int i;

    for (i = 0; i < TAM; i++) {
        do {
            printf("Ingrese codigo de barra del producto %d (1-999999999): ", i + 1);
            scanf("%d", &codigos[i]);
        } while (codigos[i] <= 0 || codigos[i] > 999999999);

        do {
            printf("Ingrese precio del producto %d: ", i + 1);
            scanf("%f", &precios[i]);
        } while (precios[i] < 0);
    }

    printf("\nLista de productos:\n");
    for (i = 0; i < TAM; i++) {
        printf("Codigo: %d\tPrecio: %.2f\n", codigos[i], precios[i]);
    }

    float maxPrecio = precios[0], minPrecio = precios[0];
    int codigoMax = codigos[0], codigoMin = codigos[0];

    for (i = 1; i < TAM; i++) {
        if (precios[i] > maxPrecio) {
            maxPrecio = precios[i];
            codigoMax = codigos[i];
        }
        if (precios[i] < minPrecio) {
            minPrecio = precios[i];
            codigoMin = codigos[i];
        }
    }

    printf("\nMayor precio: %.2f  Codigo: %d\n", maxPrecio, codigoMax);
    printf("Menor precio: %.2f  Codigo: %d\n", minPrecio, codigoMin);

    return 0;
}


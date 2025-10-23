#include <stdio.h>
#include <stdlib.h>
#define TAM 20

int cuantas_piezas(int);
int rectificable(float, float);
int rechazada(float, float);
void cargar_piezas(float *, int);
int contar(int (*)(float, float), float, float *, int);
float* reservar_memoria(int);
void segregar(int (*)(float, float), float, float *, int, float *);
void mostrar_piezas(char *, float *, int);

int main(void) {
    float diametros[TAM] = {0};
    int n;
    float max = 12;
    float min = 10;

    n = cuantas_piezas(TAM);
    cargar_piezas(diametros, n);

    int n_rectificar = contar(rectificable, max, diametros, n);
    float *p_rectificables = reservar_memoria(n_rectificar);
    segregar(rectificable, max, diametros, n, p_rectificables);

    int n_rechazar = contar(rechazada, min, diametros, n);
    float *p_rechazadas = reservar_memoria(n_rechazar);
    segregar(rechazada, min, diametros, n, p_rechazadas);

    mostrar_piezas("rectificables", p_rectificables, n_rectificar);
    mostrar_piezas("rechazadas", p_rechazadas, n_rechazar);

    free(p_rectificables);
    free(p_rechazadas);

    return 0;
}

int cuantas_piezas(int max) {
    int n;
    do {
        printf("¿Cuántas piezas ingresará? ");
        scanf("%d", &n);
    } while (n < 0 || n > max);
    return n;
}

int rectificable(float diametro, float valor) {
    return diametro > valor ? 1 : 0;
}

int rechazada(float diametro, float valor) {
    return diametro < valor ? 1 : 0;
}

void cargar_piezas(float *p, int n) {
    float valor;
    for (int i = 0; i < n; i++) {
        printf("Ingrese el diámetro de la pieza %d: ", i + 1);
        scanf("%f", &valor);
        *(p + i) = valor;
    }
}

int contar(int (*criterio)(float, float), float valor, float *p, int n) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (criterio(*(p + i), valor)) {
            contador++;
        }
    }
    return contador;
}

float* reservar_memoria(int cantidad) {
    float *p = (float *)malloc(cantidad * sizeof(float));
    if (p == NULL) {
        printf("Error al reservar memoria.\n");
        exit(1);
    }
    return p;
}

void segregar(int (*criterio)(float, float), float valor, float *origen, int n, float *destino) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (criterio(*(origen + i), valor)) {
            *(destino + j) = *(origen + i);
            j++;
        }
    }
}

void mostrar_piezas(char *etiqueta, float *p, int n) {
    printf("\nPiezas %s:\n", etiqueta);
    if (n == 0) {
        printf("  (ninguna)\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("  %.2f mm\n", *(p + i));
        }
    }
}

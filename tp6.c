/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h> 
#include <math.h> 
#define pi 3.14159
 float calcularAreaRectangulo (int a, int b) {
    float producto;
    
    producto = a * b;
    
    return producto;
}
 float calcularPerimetroRectangulo(int a, int b) {
     float suma;
    
    suma = 2*a + 2*b;
    
    return suma;
}
 float cularDiagonalRectangulo(int a, int b) {
     float diag;
     
    diag = sqrt(pow(a,2) + pow(b, 2));
   
    return diag;
    
 }
 float calcularAreaCirculo(int a) {
    float area;
     
    area = pi * pow(a, 2);
    
    return area;
 }
 float calcularPerimetroCirculo(int a) {
     float perimetro;
     
    perimetro = 2 * pi * a;
   
    return perimetro;
 }
 void imprimirResultados(float perimetro, float area) {
 
    printf("\nel perimetro es: %.2f", perimetro);
    printf("\n\nel area es: %.2f", area);
    
    
   
 }
int main()
{int a;
int b;
float perimetro;
float suma;
float area;
float diag;
float producto;
int op;
do{
   printf("Ingrese la figura que desea calcular (1: rectángulo, 2: círculo): ");

scanf ("%d", &op); 
if(op <1 || op>2)
printf("opcion invalida (1 o 2)\n\n");
}while(op <1 || op>2);


 switch (op){
  case 1: printf("Opción de rectángulo seleccionada\n\n");
  printf("ingrese altura: ");
    scanf("%d", &a);
    printf("ingrese longitud: ");
    scanf("%d", &b);
    producto = calcularAreaRectangulo (a,b);
    suma = calcularPerimetroRectangulo (a,b);
    diag = cularDiagonalRectangulo (a,b);
    imprimirResultados(suma, producto);
    break;
  case 2: printf("Opción de circulo seleccionada\n\n");
    printf("ingrese radio: ");
    scanf("%d", &a);
    perimetro = calcularPerimetroCirculo (a);
    area = calcularAreaCirculo (a);
    imprimirResultados(perimetro, area);
  break;
  
  
  
 }
 


    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_TAMANO 100  

int main() {
    srand((unsigned int)time(0));  

    int TAMANO;
    printf("De que tamano quieres tus matrices? (maximo %d):  ", MAX_TAMANO);
    scanf("%d", &TAMANO);

    if (TAMANO > MAX_TAMANO || TAMANO <= 0) {
        printf("Error: Tamano excede el maximo permitido o es negativo.\n");
        return 1;  
    }

    int matrizA[MAX_TAMANO][MAX_TAMANO]; 
    int matrizB[MAX_TAMANO][MAX_TAMANO];
    int resultado[MAX_TAMANO][MAX_TAMANO];

    int i, j;

    for(i = 0; i < TAMANO; i++)
        for(j = 0; j < TAMANO; j++)
            matrizA[i][j] = rand() % 10;

    for(i = 0; i < TAMANO; i++)
        for(j = 0; j < TAMANO; j++)
            matrizB[i][j] = rand() % 10;
            
	int suma_triangulo = 0;
    int opcion = 0;
    int suma_diagonal = 0;
    int k=0;
    do {
        printf("\nMenu de opciones:\n");
        printf("1. Sumar triangulo superior de matriz A\n");
        printf("2. Sumar los numeros de dos matrices\n");
        printf("3. Restar los numeros de dos matrices\n");
        printf("4. Sumar la diagonal de la matriz A\n");
        printf("5. Multiplicar los numeros de dos matrices\n");
        printf("6. Salir del programa");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("\nMatriz A generada:\n");
                for(i = 0; i < TAMANO; i++) {
                    for(j = 0; j < TAMANO; j++)
                        printf("%d ", matrizA[i][j]);
                    printf("\n");
                }

                for(i = 0; i < TAMANO; i++)
                    for(j = i+1; j < TAMANO; j++)
                        suma_triangulo += matrizA[i][j];

                printf("\nSuma de elementos del triangulo superior: %d\n", suma_triangulo);
                break;

            case 2:
                printf("\nSuma de Matriz A + Matriz B:\n");
                for(i = 0; i < TAMANO; i++) {
                    for(j = 0; j < TAMANO; j++) {
                        resultado[i][j] = matrizA[i][j] + matrizB[i][j];
                        printf("%d ", resultado[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("\nResta de Matriz A - Matriz B:\n");
                for(i = 0; i < TAMANO; i++) {
                    for(j = 0; j < TAMANO; j++) {
                        resultado[i][j] = matrizA[i][j] - matrizB[i][j];
                        printf("%d ", resultado[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("\nMatriz A generada:\n");
                for(i = 0; i < TAMANO; i++) {
                    for(j = 0; j < TAMANO; j++)
                        printf("%d ", matrizA[i][j]);
                    printf("\n");
                }

              
                for(i = 0; i < TAMANO; i++)
                    suma_diagonal += matrizA[i][i];

                printf("\nSuma de elementos de la diagonal: %d\n", suma_diagonal);
                break;

            case 5:
                printf("\nMultiplicacion de Matriz A * Matriz B:\n");
                for(i = 0; i < TAMANO; i++) {
                    for(j = 0; j < TAMANO; j++) {
                        resultado[i][j] = 0;
                        for(k = 0; k < TAMANO; k++) {
                            resultado[i][j] += matrizA[i][k] * matrizB[k][j];
                        }
                        printf("%d ", resultado[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 6:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida, intente de nuevo.\n");
        }
    } while(opcion != 6);

    return 0;
}

// LUISA LIZETH ZEREGA SOTO 
// MAT:356491
// FECHA: 03-OCT-2023
// DESCRIP: Menu de vectores y matrices.
// ZSL_ACT8.CPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 10
#define MATRIX_SIZE 4

void fillVectorManually(int vector[], int size, int start, int end) {
    printf("Ingrese los valores del vector:\n");
    for (int i = 0; i < size; i++) {
        printf("Ingrese el valor para la posición %d: ", i + 1);
        scanf("%d", &vector[i]);
        if (vector[i] < start || vector[i] > end) {
            printf("El valor ingresado está fuera del rango permitido. Intente nuevamente.\n");
            i--;
        }
    }
}

void fillVectorRandomly(int vector[], int size, int start, int end) {
    srand(time(NULL)); 

    printf("Vector aleatorio\n");
    int numbers[end - start + 1];
    for (int i = start; i <= end; i++) {
        numbers[i - start] = i;
    }

    for (int i = 0; i < size; i++) {
        int index = rand() % (end - start + 1);
        vector[i] = numbers[index];
        numbers[index] = numbers[end - start];
        end--;
    }
}

void fillVectorFromArrays(int vector[], int size, int array1[], int array2[], int arraySize) {
    printf("Vector con los datos de los arreglos...\n");
    for (int i = 0; i < size; i++) {
        if (i < arraySize) {
            vector[i] = array1[i];
        } else {
            vector[i] = array2[i - arraySize];
        }
    }
}

void printVector(int vector[], int size) {
    printf("Vector 3: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void fillMatrixFromVectors(int matrix[][MATRIX_SIZE], int vector1[], int vector2[]) {
    printf("La matriz con los datos de los vectores...\n");
    int index = 0;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (index < VECTOR_SIZE) {
                matrix[i][j] = vector1[index];
            } else {
                matrix[i][j] = vector2[index - VECTOR_SIZE];
            }
            index++;
        }
    }
}

void printMatrix(int matrix[][MATRIX_SIZE]) {
    printf("Matriz:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vector1[VECTOR_SIZE];
    int vector2[VECTOR_SIZE];
    int vector3[VECTOR_SIZE * 2];
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int option;

    do {
        printf("MENÚ\n");
        printf("1.- LLENAR VECTOR 1 (MANUALMENTE)\n");
        printf("2.- LLENAR VECTOR 2 ALEATORIAMENTE\n");
        printf("3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)\n");
        printf("4.- IMPRIMIR VECTORES\n");
        printf("5.- LLENAR MATRIZ 4 X 4\n");
        printf("6.- IMPRIMIR MATRIZ\n");
        printf("0.- SALIR\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                fillVectorManually(vector1, VECTOR_SIZE, 30, 70);
                printf("Vector 1 llenado .\n");
                break;
            case 2:
                fillVectorRandomly(vector2, VECTOR_SIZE, 1, 20);
                printf("Vector 2 llenado .\n");
                break;
            case 3:
                fillVectorFromArrays(vector3, VECTOR_SIZE * 2, vector1, vector2, VECTOR_SIZE);
                printf("Vector 3 llenado .\n");
                break;
            case 4:
                printf("Imprimiendo vectores:\n");
                printVector(vector1, VECTOR_SIZE);
                printVector(vector2, VECTOR_SIZE);
                printVector(vector3, VECTOR_SIZE * 2);
                break;
            case 5:
                fillMatrixFromVectors(matrix, vector1, vector2);
                printf("Matriz llenada .\n");
                break;
            case 6:
                printf("Imprimiendo matriz:\n");
                printMatrix(matrix);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }

        printf("\n");
    } while (option != 0);

    return 0;
}

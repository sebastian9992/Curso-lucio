#include <stdio.h>

#define MAX_SIZE 10

void mostrarArray(int a[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}


void llenarArray(int a[], int n) {
    printf("\n--- Ingreso de enteros ---\n");
    for (int i = 0; i < n; i++) {
        int temp;
        do {
            printf("Ingrese el numero #%d  (positivo): ", i + 1);
            scanf("%d", &temp);
            if (temp <= 0) {
                printf("Error: El numero debe ser positivo. Intente de nuevo.\n");
            }
        } while (temp <= 0);
        a[i] = temp;
    }
}


void ordenarSelectionAscendente(int a[], int n) {
    printf("\n--- Proceso de Selection Sort Ascendente ---\n");
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }

        
        if (min_idx != i) {
            int temp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = temp;
            printf("Intercambio #%d: ", i + 1);
            mostrarArray(a, n);
        }
    }
}


void ordenarInsertionDescendente(int a[], int n) {
    printf("\n--- Proceso de Insertion Sort Descendente ---\n");
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
        printf("Insercion #%d: ", i);
        mostrarArray(a, n);
    }
}

int main() {
    int tiemposOriginales[MAX_SIZE];
    int tiemposTrabajo[MAX_SIZE];
    int opcion;
    int datosCargados = 0;

    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Registrar los enteros \n");
        printf("2. Ver el arreglo original\n");
        printf("3. Ordenar (Selection Sort Ascendente) \n");
        printf("4. Ordenar (Insertion Sort Descendente) \n");
        printf("5. Salir \n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

    
        int i;
        switch (opcion) {
            case 1:
                llenarArray(tiemposOriginales, MAX_SIZE);
                datosCargados = 1;
                break;
            case 2:
                if (datosCargados) {
                    printf("\nArreglo Original:\n");
                    mostrarArray(tiemposOriginales, MAX_SIZE);
                } else {
                    printf("\nPrimero ingresa los datos (Opcion 1).\n");
                }
                break;
            case 3:
                if (datosCargados) {
                    for (i = 0; i < MAX_SIZE; i++) {
                        tiemposTrabajo[i] = tiemposOriginales[i];
                    }
                    ordenarSelectionAscendente(tiemposTrabajo, MAX_SIZE);
                    printf("\nFinal del ordenamiento con Selection Sort:\n");
                    mostrarArray(tiemposTrabajo, MAX_SIZE);
                } else {
                    printf("\nPrimero ingresa los datos (Opcion 1).\n");
                }
                break;
            case 4:
                if (datosCargados) {
                    for (i = 0; i < MAX_SIZE; i++) {
                        tiemposTrabajo[i] = tiemposOriginales[i];
                    }
                    ordenarInsertionDescendente(tiemposTrabajo, MAX_SIZE);
                    printf("\nFinal del ordenamiento con Insertion Sort:\n");
                    mostrarArray(tiemposTrabajo, MAX_SIZE);
                } else {
                    printf("\nPrimero ingresa los datos (Opcion 1).\n");
                }
                break;
            case 5:
                printf("\n¡Gracias por usar el programa! Nos vemos pronto.\n");
                break;
            default:
                printf("\nOpcion no valida. ¡Intenta de nuevo!\n");
        }
    } while (opcion != 5);

    return 0;
}
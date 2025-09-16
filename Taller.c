#include <stdio.h>
#include <stdlib.h> // Se agrega para la funcion system()

// Estructura para almacenar los datos de un estudiante.
typedef struct {
    int codigo;
    float nota;
} Estudiante;

// Prototipos de funciones recursivas y auxiliares.
float encontrarNotaMaxima_recursivo(Estudiante estudiantes[], int tamano);
float calcularSuma_recursivo(Estudiante estudiantes[], int tamano);
void selectionSort_recursivo(Estudiante estudiantes[], int tamano, int indice_actual);
void intercambiar(Estudiante* a, Estudiante* b);
void mostrarMenu();

// --- Función principal del programa ---
int main() {
    // Datos de los estudiantes predefinidos.
    Estudiante lista_estudiantes[] = {
        {2024101, 4.5},
        {2024102, 3.2},
        {2024103, 5.0},
        {2024104, 2.8},
        {2024105, 4.0},
        {2024106, 3.5}
    };
    int num_estudiantes = sizeof(lista_estudiantes) / sizeof(Estudiante);

    int opcion;
    mostrarMenu();
    scanf("%d", &opcion);

    switch (opcion) {
        case 1: {
            float nota_max = encontrarNotaMaxima_recursivo(lista_estudiantes, num_estudiantes);
            printf("-> La nota mas alta es: %.2f\n", nota_max);
            break;
        }
        case 2: {
            float suma_notas = calcularSuma_recursivo(lista_estudiantes, num_estudiantes);
            float promedio = suma_notas / num_estudiantes;
            printf("-> El promedio del curso es: %.2f\n", promedio);
            break;
        }
        case 3: {
            Estudiante copia_estudiantes[num_estudiantes];
            for (int i = 0; i < num_estudiantes; i++) {
                copia_estudiantes[i] = lista_estudiantes[i];
            }
            selectionSort_recursivo(copia_estudiantes, num_estudiantes, 0);
            printf("-> Estudiantes ordenados por codigo:\n");
            for (int i = 0; i < num_estudiantes; i++) {
                printf("Codigo: %d, Nota: %.2f\n", copia_estudiantes[i].codigo, copia_estudiantes[i].nota);
            }
            break;
        }
        case 4:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida. El programa terminara.\n");
            break;
    }

    return 0;
}

// --- Implementación de funciones auxiliares y recursivas ---

void mostrarMenu() {
    printf("\n--- Gestion de Notas ---\n");
    printf("1. Buscar la nota mas alta\n");
    printf("2. Calcular la nota promedio\n");
    printf("3. Ordenar estudiantes por codigo\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
}

float encontrarNotaMaxima_recursivo(Estudiante estudiantes[], int tamano) {
    if (tamano == 1) {
        return estudiantes[0].nota;
    }
    float max_del_resto = encontrarNotaMaxima_recursivo(estudiantes, tamano - 1);
    return (estudiantes[tamano - 1].nota > max_del_resto) ? estudiantes[tamano - 1].nota : max_del_resto;
}

float calcularSuma_recursivo(Estudiante estudiantes[], int tamano) {
    if (tamano == 0) {
        return 0;
    }
    return estudiantes[tamano - 1].nota + calcularSuma_recursivo(estudiantes, tamano - 1);
}

void intercambiar(Estudiante* a, Estudiante* b) {
    Estudiante temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort_recursivo(Estudiante estudiantes[], int tamano, int indice_actual) {
    if (indice_actual >= tamano - 1) {
        return;
    }
    int indice_min = indice_actual;
    for (int i = indice_actual + 1; i < tamano; i++) {
        if (estudiantes[i].codigo < estudiantes[indice_min].codigo) {
            indice_min = i;
        }
    }
    intercambiar(&estudiantes[indice_actual], &estudiantes[indice_min]);
    selectionSort_recursivo(estudiantes, tamano, indice_actual + 1);
}
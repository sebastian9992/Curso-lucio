 📌 Taller de Ordenamiento en C

Este proyecto implementa un programa en **C** que permite registrar números enteros positivos y ordenarlos utilizando dos algoritmos clásicos de ordenamiento:

- **Selection Sort (Ascendente)**  
- **Insertion Sort (Descendente)**

El usuario puede interactuar con el programa a través de un **menú** en consola.

---

## ⚙️ Funcionalidades

- Registrar hasta 10 enteros positivos.
- Visualizar el arreglo original ingresado.
- Ordenar los números con **Selection Sort en orden ascendente**, mostrando paso a paso los intercambios.
- Ordenar los números con **Insertion Sort en orden descendente**, mostrando paso a paso las inserciones.
- Salir del programa.

---

## 🖥️ Menú del Programa
--- Menu Principal ---

Registrar los enteros

Ver el arreglo original

Ordenar (Selection Sort Ascendente)

Ordenar (Insertion Sort Descendente)

Salir

---

## 🚀 Compilación y Ejecución

1. Compilar el programa con `gcc`:

```bash
gcc primertaller.c -o primertaller.exe

Ejecutar:

./primertaller.exe

📊 Ejemplo de Uso

--- Menu Principal ---
1. Registrar los enteros
2. Ver el arreglo original
3. Ordenar (Selection Sort Ascendente)
4. Ordenar (Insertion Sort Descendente)
5. Salir
Elige una opcion: 1

--- Ingreso de enteros ---
Ingrese el numero #1  (positivo): 9
Ingrese el numero #2  (positivo): 3
Ingrese el numero #3  (positivo): 7
...

Intercambio #1: [ 3, 9, 7, ... ]
Intercambio #2: [ 3, 7, 9, ... ]

📚 Algoritmos Implementados

Selection Sort: Busca el valor mínimo y lo intercambia en cada pasada, logrando un ordenamiento ascendente.

Insertion Sort: Inserta los elementos en su posición correcta hacia atrás, logrando un ordenamiento descendente.

✍️ Proyecto realizado por Sebastian como práctica de algoritmos de ordenamiento en C.
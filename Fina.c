// INTEGRANTES: Wendy calzada Quintero y Juan Sebastian Murillo Bonilla
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cola {
    char destino[20];
    int cantidad;
    struct Cola *sig;
};  

struct Nodo {
    int fecha;
    int stock;
    char nombre[20];
    struct Cola *cola;
    struct Nodo *izq, *der;
};

int main() {

    struct Nodo *arbol = NULL;
    int op;

    while (1) {

        printf("\n1. Insertar producto");
        printf("\n2. Registrar pedido");
        printf("\n3. Eliminar lote");
        printf("\n4. Cancelar pedido");
        printf("\n5. Mostrar inventario");
        printf("\n6. Salir\n> ");
        scanf("%d", &op);

        /* ---------------- INSERTAR PRODUCTO ---------------- */
        if (op == 1) {

            int f, c;
            char nom[20];

            printf("Fecha AAAAMMDD: ");
            scanf("%d", &f);

            printf("Cantidad: ");
            scanf("%d", &c);

            printf("Nombre: ");
            scanf("%s", nom);

            struct Nodo *nuevo = malloc(sizeof(struct Nodo));
            nuevo->fecha = f;
            nuevo->stock = c;
            strcpy(nuevo->nombre, nom);
            nuevo->cola = NULL;
            nuevo->izq = nuevo->der = NULL;

            if (arbol == NULL) {
                arbol = nuevo;
            } else {
                struct Nodo *p = arbol, *padre = NULL;

                while (p != NULL) {
                    padre = p;
                    if (f < p->fecha) p = p->izq;
                    else if (f > p->fecha) p = p->der;
                    else {
                        printf("Fecha repetida.\n");
                        free(nuevo);
                        padre = NULL;
                        break;
                    }
                }

                if (padre != NULL) {
                    if (f < padre->fecha) padre->izq = nuevo;
                    else padre->der = nuevo;
                }
            }

            printf("Insertado.\n");
        }

        /* ---------------- REGISTRAR PEDIDO ---------------- */
        else if (op == 2) {

            if (arbol == NULL) {
                printf("No hay productos.\n");
                continue;
            }

            // buscar fecha más cercana
            struct Nodo *p = arbol;
            while (p->izq != NULL) p = p->izq;

            char dest[20];
            int cant;

            printf("Destino: ");
            scanf("%s", dest);

            printf("Cantidad: ");
            scanf("%d", &cant);

            if (cant > p->stock) {
                printf("No hay stock suficiente.\n");
                continue;
            }

            struct Cola *nuevo = malloc(sizeof(struct Cola));
            strcpy(nuevo->destino, dest);
            nuevo->cantidad = cant;
            nuevo->sig = NULL;

            if (p->cola == NULL) {
                p->cola = nuevo;
            } else {
                struct Cola *q = p->cola;
                while (q->sig != NULL) q = q->sig;
                q->sig = nuevo;
            }

            p->stock -= cant;

            printf("Pedido registrado.\n");
        }

        /* ---------------- ELIMINAR LOTE ---------------- */
        else if (op == 3) {

            int f;
            printf("Fecha a eliminar: ");
            scanf("%d", &f);

            struct Nodo *p = arbol, *padre = NULL;

            while (p != NULL && p->fecha != f) {
                padre = p;
                if (f < p->fecha) p = p->izq;
                else p = p->der;
            }

            if (p == NULL) {
                printf("No existe.\n");
                continue;
            }

            // liberar cola
            struct Cola *x = p->cola;
            while (x != NULL) {
                struct Cola *t = x;
                x = x->sig;
                free(t);
            }

            
            if (p->izq == NULL && p->der == NULL) {
                if (padre == NULL) arbol = NULL;
                else if (padre->izq == p) padre->izq = NULL;
                else padre->der = NULL;
            }
            else if (p->izq == NULL || p->der == NULL) {
                struct Nodo *hijo = (p->izq != NULL) ? p->izq : p->der;
                if (padre == NULL) arbol = hijo;
                else if (padre->izq == p) padre->izq = hijo;
                else padre->der = hijo;
            }
            else {
                struct Nodo *min = p->der, *padMin = p;
                while (min->izq != NULL) {
                    padMin = min;
                    min = min->izq;
                }

                p->fecha = min->fecha;
                p->stock = min->stock;
                strcpy(p->nombre, min->nombre);
                p->cola = min->cola;

                if (padMin->izq == min) padMin->izq = min->der;
                else padMin->der = min->der;

                free(min);
                continue;
            }

            free(p);
            printf("Lote eliminado.\n");
        }

        /* ---------------- CANCELAR PEDIDO ---------------- */
        else if (op == 4) {

            int f;
            printf("Fecha: ");
            scanf("%d", &f);

            struct Nodo *p = arbol;
            while (p != NULL && p->fecha != f) {
                if (f < p->fecha) p = p->izq;
                else p = p->der;
            }

            if (p == NULL) {
                printf("No existe.\n");
                continue;
            }

            char dest[20];
            printf("Destino pedido: ");
            scanf("%s", dest);

            struct Cola *c = p->cola, *ant = NULL;

            while (c != NULL && strcmp(c->destino, dest) != 0) {
                ant = c;
                c = c->sig;
            }

            if (c == NULL) {
                printf("No existe ese pedido.\n");
                continue;
            }

            p->stock += c->cantidad;

            if (ant == NULL) p->cola = c->sig;
            else ant->sig = c->sig;

            free(c);
            printf("Pedido cancelado.\n");
        }

        /* ---------------- MOSTRAR INORDER (CORTO) ---------------- */
        else if (op == 5) {

            struct Nodo *s[50];
            int tope = -1;

            struct Nodo *p = arbol;

            while (p != NULL || tope != -1) {

                while (p != NULL) {
                    s[++tope] = p;
                    p = p->izq;
                }

                p = s[tope--];

                printf("\nFecha: %d\nNombre: %s\nStock: %d\n",
                       p->fecha, p->nombre, p->stock);

                int cont = 0;
                struct Cola *c = p->cola;
                while (c != NULL) {
                    cont++;
                    c = c->sig;
                }
                printf("Pedidos: %d\n", cont);

                p = p->der;
            }
        }

        else if (op == 6) break;
    }

    return 0;
} 
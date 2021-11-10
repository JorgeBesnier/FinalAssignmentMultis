#include <stdio.h>

typedef struct _MatDims {size_t y, x;} MatDims;


/**
 * Imprime una matriz pequena en stdout.
 * Se recomienda para matrices de menos de 10x10 para que no se trunquen los
 * renglones en la consola.
 */
void print_matrix(MatDims *dims, double mat[dims->y][dims->x]) {
    int i, j;
    printf("[");
    for(i=0; i<dims->y; i++) {
        if(i>0) printf(",\n ");
        printf(" [");
        for(j=0; j<dims->x; j++) {
            if(j>0) printf(",\t");
            printf("%lf", mat[i][j]);
        }
        printf("]");
    }
    printf(" ]\n");
}

// Leer datos

// Realizar calculo

// Escribir resultados


int main() {
    // Datos de prueba
    MatDims dims = {2, 3};
    double matriz[2][3] = { {1, 2, 3},
                            {4, 5, 6} };

    // Llamada a leer datos
    // Llamada a realizar calculo
    // Llamada a escribir resultados

    // Imprimir la matriz
    print_matrix(&dims, matriz);

    return 0;
}

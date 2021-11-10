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

/**
 * Multiplica dos matrices bidimensionales.
 * Las dimensiones de las matrices a multiplicar y el producto deben ser validas:
 *    matA[n][m] * matB[m][o] = matC[n][o]
 */
void matrix_multiplication(
    MatDims *dimsA, double matA[dimsA->y][dimsA->x],
    MatDims *dimsB, double matB[dimsB->y][dimsB->x],
    MatDims *dimsC, double matC[dimsC->y][dimsC->x]
) {
    int i, j, k;
    for (i=0; i<dimsC->y; i++) {
        for (j=0; j<dimsC->x; j++) {
            matC[i][j] = 0.0;
            for (k=0; k<dimsA->x; k++) {
                matC[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

// Escribir resultados


int main() {
    // Datos de prueba (borrar cuando se puedan leer las matrices de un archivo)
    MatDims dimsA = {2, 3}, dimsB = {3, 1}, dimsC = {2, 1};
    double matA[2][3] = { {1, 2, 3},
                          {4, 5, 6} };
    double matB[3][1] = { {1},
                          {2},
                          {3} };
    double matC[2][1];

    // Llamada a leer datos

    // Validar dimensiones de matrices
    if (dimsA.x != dimsB.y || dimsA.y != dimsC.y || dimsB.x != dimsC.x) {
        printf("Dimensiones de matrices invalidas: A[%d][%d] x B[%d][%d] = C[%d][%d]\n", dimsA.y, dimsA.x, dimsB.y, dimsB.x, dimsC.y, dimsC.x);
        return 1;
    }

    // Obtener el producto de las matrices A y B
    matrix_multiplication(&dimsA, matA, &dimsB, matB, &dimsC, matC);

    // Llamada a escribir resultados

    // Imprimir la matriz producto (borrar cuando se puedan imprimir matrices en un archivo)
    print_matrix(&dimsC, matC);

    return 0;
}

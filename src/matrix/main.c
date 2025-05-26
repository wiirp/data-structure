// typedef int Matirx4[4][4];

#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

/* test only */

int main() {
    matrix_t *matrix;
    matrix = create(2, 2);

    matrix_t *matrix_B;
    matrix_B = create(2, 2);

    add(matrix, 0, 0, 1);
    add(matrix, 0, 1, 2);
    add(matrix, 1, 0, 3);
    add(matrix, 1, 1, 4);
   
    add(matrix_B, 0, 0, 1);
    add(matrix_B, 0, 1, 2);
    add(matrix_B, 1, 0, 3);
    add(matrix_B, 1, 1, 4);

    printf("%d\n", equals(matrix, matrix_B));

    free_matrix(matrix);
    free_matrix(matrix_B);

    return 0;
}

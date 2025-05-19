#include <stdlib.h>
#include <stdio.h>
#include "matrixpointers.h"

/* test only */

int main() {
    matrix_t *matrix;

    matrix = create(2, 2);
    add(matrix, 0 ,0, 1);
    printf("%d\n", access(matrix, 0, 0));

    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include "matrixpointers.h"

typedef struct matrix
{
    int lin;
    int col;
    int **v;
} matrix_t;

matrix_t *create(int lin, int col) {
    matrix_t *matrix;

    matrix = (matrix_t*) malloc(sizeof(matrix_t));
    matrix->lin = lin;
    matrix->col = col;
    matrix->v = (int**) malloc(lin*sizeof(int*));

    for (int i = 0; i < lin; i++) {
        matrix->v[i] = (int*) malloc(col*sizeof(int*));
    }

    return matrix;
}

void free_matrix(matrix_t *matrix) {
    for (int i = 0 ; i < matrix->lin; i++) {
        free(matrix->v[i]);
    }

    free(matrix->v);
    free(matrix);
}

int access(matrix_t *matrix, int lin, int col) {
    if (lin < 0 || lin >= matrix->lin || col < 0 || col >= matrix->col) {
        printf("Error access");
        exit(EXIT_FAILURE);
    }
    
    return matrix->v[lin][col];
}

void add(matrix_t *matrix, int lin, int col, int value) {
    if (lin < 0 || lin >= matrix->lin || col < 0 || col >= matrix->col) {
        printf("Error line or col");
        exit(EXIT_FAILURE);
    }

    matrix->v[lin][col] = value;
}

int search(matrix_t *matrix, int length, int target) {
    int start = 0;
    int end = matrix->lin - 1;
    int row = -1;

    while (start <= end) {
        int middle = (end + start) / 2;

        if (target >= matrix->v[middle][0] && target <= matrix->v[middle][matrix->col - 1]) {
            row = middle;
            break;
        }

        if (target > matrix->v[middle][0]) start = middle + 1;
        else if (target < matrix->v[middle][0]) end = middle - 1;
    }

    if (row != -1) {
        for (int i = 0; i < matrix->col; i++) {
            if (target == matrix->v[row][i]) return i;
        }
    }

    return -1;
}
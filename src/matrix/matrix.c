#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

typedef struct matrix
{
    int lin; // lines
    int col; // collums
    int *v;
} matrix_t;

matrix_t *create(int lin, int col) {
    matrix_t *matrix;

    matrix = (matrix_t*) malloc(sizeof(matrix_t));
    matrix->lin = lin;
    matrix->col = col;
    matrix->v = (int*) malloc(lin*col*sizeof(int*));

    return matrix;
}

int access(matrix_t *matrix, int lin, int col) {
    int k;

    if (lin < 0 || lin >= matrix->lin || col < 0 || col >= matrix->col) {
        printf("Error access");
        exit(EXIT_FAILURE);
    }

    k = lin * matrix->col + col;
    return matrix->v[k];
}

void add(matrix_t *matrix, int lin, int col, int value) {
    int k;

    if (lin < 0 || lin >= matrix->lin || col < 0 || col >= matrix->col) {
        printf("Error line or collum");
        exit(EXIT_FAILURE);
    }

    k = lin * matrix->col + col;
    matrix->v[k] = value;
}

int is_symmetrical(matrix_t *matrix) {
    int isSymmetrical = 1;
    int j = 3;

    if (matrix->col != matrix->lin) {
        printf("It is not possible to prove whether a non-square matrix is symmetric");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < matrix->col; i++) {
        int temp = matrix->v[i];
        int temp2 = matrix->v[j];

        if (temp != temp2) {
            isSymmetrical = 0;
            break;
        }

        j+= 3;
    }

    return isSymmetrical;
}

matrix_t *transpose(matrix_t *matrix) {
    matrix_t *new_matrix;

    new_matrix = (matrix_t*) malloc(sizeof(matrix_t));
    new_matrix->col = matrix->lin;
    new_matrix->lin = matrix->col;
    new_matrix->v = (int*) malloc(matrix->col*matrix->lin*sizeof(int*));

    for (int i = 0; i < matrix->lin; i++) {
        for (int j = 0; j < matrix->lin; j++) {
            int k = i * matrix->col + j;
            int h = j * matrix->col + i;
            new_matrix->v[h] = matrix->v[k];    
        }
    }

    return new_matrix;
}

int search(matrix_t *matrix, int length, int target) {
    int start = 0, end = length;

    while (start <= end) {
        int middle = (start + end) / 2;

        if (target == matrix->v[middle]) return middle;
        else if (target > matrix->v[middle]) start = middle + 1;
        else end = middle - 1;
    }

    return -1;
}

void free_matrix(matrix_t *matrix) {
    free(matrix->v);
    free(matrix);
}

int is_square(matrix_t *matrix) {
    if (matrix->col == matrix->lin) return 1;

    return 0;
}

void print_matrix(matrix_t *matrix) {

    for (int i = 0; i < matrix->lin * matrix->col; i++) {
        printf("%d\n", matrix->v[i]);
    }
}

void replace_number(matrix_t *matrix, int lin, int col, int new_number) {
     int k;

    if (lin < 0 || lin >= matrix->lin || col < 0 || col >= matrix->col) {
        printf("Error line or collum");
        exit(EXIT_FAILURE);
    }

    k = lin * matrix->col + col;
    matrix->v[k] = new_number;
}

int equals(matrix_t *matrix_A, matrix_t *matrix_B) {

    if (matrix_A->col != matrix_B->col || matrix_A->lin != matrix_B->lin) return 0;

    if (!matrix_A || !matrix_B || !matrix_A->v || !matrix_B->v) return 0;

    for (int i = 0; i < matrix_A->col * matrix_A->lin; i++) {
        if (matrix_A->v[i] != matrix_B->v[i]) return 0;
    }
    
    return 1;
}

int is_identity(matrix_t *matrix) {
    int is_identity = 1;

    if (matrix->col != matrix->lin) {
        printf("It is not possible to prove whether a non-square matrix is identity");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < matrix->lin; i++) {
        int k = i * matrix->lin + i;

        if (matrix->v[k] != 1) {
            return 0;
        }
    }

    for (int i = 0; i < matrix->lin; i++) {
        for (int j = 0; j < matrix->lin; j++) {
            if (i != j) {
                int k = i * matrix->lin + j;
                if (matrix->v[k] != 0) return 0;
            }
        }
    }
    
    return 1;
}

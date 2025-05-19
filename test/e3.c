// typedef int Matirx4[4][4];

#include <stdlib.h>
#include <stdio.h>

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

int symmetrical(matrix_t *matrix) {
    int isSymmetrical = 0;
    int j = 3;

    if (matrix->col != matrix->lin) {
        printf("It is not possible to prove whether a non-square matrix is symmetric");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < matrix->col; i++) {
        int temp = matrix->v[i];
        int temp2 = matrix->v[j];

        if (temp != temp2) {
            isSymmetrical = 1;
            break;
        }

        j+= 3;
    }

    return isSymmetrical;
}

void free_matrix(matrix_t *matrix) {
    free(matrix->v);
    free(matrix);
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

int main() {
    matrix_t *matrix;
    matrix = create(3, 3);

    add(matrix, 0, 0, 1);
    add(matrix, 0, 1, 2);
    add(matrix, 0, 2, 3);
    add(matrix, 1, 0, 4);
    add(matrix, 1, 1, 5);
    add(matrix, 1, 2, 6);
    add(matrix, 2, 0, 7);
    add(matrix, 2, 1, 8);
    add(matrix, 2, 2, 9);

    // 1 2 3
    // 4 5 6
    // 7 8 9

    // 1 4 7
    // 2 5 8
    // 3 6 9

    matrix_t *new_matrix;
    new_matrix = transpose(matrix);

    printf("%d\n", access(new_matrix, 0, 0));
    printf("%d\n", access(new_matrix, 0, 1));
    printf("%d\n", access(new_matrix, 0, 2));
    printf("%d\n", access(new_matrix, 1, 0));
    printf("%d\n", access(new_matrix, 1, 1));
    printf("%d\n", access(new_matrix, 1, 2));
    printf("%d\n", access(new_matrix, 2, 0));
    printf("%d\n", access(new_matrix, 2, 1));
    printf("%d\n", access(new_matrix, 2, 2));

    free_matrix(matrix);
    free_matrix(new_matrix);

    return 0;
}
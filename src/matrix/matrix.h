#ifndef MATRIX_HEADER
#define MATRIX_HEADER

typedef struct matrix matrix_t;

matrix_t *create(int lin, int col);
int access(matrix_t *matrix, int lin, int col);
void add(matrix_t *matrix, int lin, int col, int value);
int symmetrical(matrix_t *matrix);
matrix_t *transpose(matrix_t *matrix);
void free_matrix(matrix_t *matrix);

#endif
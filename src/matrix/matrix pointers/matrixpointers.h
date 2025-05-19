#ifndef MATRIXPOINTERS_HEADER
#define MATRIXPOINTERS_HEADER

typedef struct matrix matrix_t;

matrix_t *create(int lin, int col);
void free_matrix(matrix_t *matrix);
int access(matrix_t *matrix, int lin, int col);
void add(matrix_t *matrix, int lin, int col, int value);

#endif
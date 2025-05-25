#ifndef MATRIX_HEADER
#define MATRIX_HEADER

typedef struct matrix matrix_t;

matrix_t *create(int lin, int col);
matrix_t *transpose(matrix_t *matrix);

int access(matrix_t *matrix, int lin, int col);
int symmetrical(matrix_t *matrix);
int search(matrix_t *matrix, int length, int target);
int is_square(matrix_t *matrix);

void free_matrix(matrix_t *matrix);
void add(matrix_t *matrix, int lin, int col, int value);

#endif
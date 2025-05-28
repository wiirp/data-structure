#ifndef MATRIXPOINTERS_HEADER
#define MATRIXPOINTERS_HEADER

typedef struct matrix matrix_t;

matrix_t *create(int lin, int col);

int access(matrix_t *matrix, int lin, int col);
int search(matrix_t *matrix, int length, int target);
int equals(matrix_t *matrix_A, matrix_t *matrix_B);

void add(matrix_t *matrix, int lin, int col, int value);
void free_matrix(matrix_t *matrix);
void print_matrix(matrix_t *matrix);

#endif
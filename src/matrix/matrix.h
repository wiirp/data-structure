#ifndef MATRIX_HEADER
#define MATRIX_HEADER

typedef struct matrix matrix_t;

matrix_t *create(int lin, int col);
matrix_t *transpose(matrix_t *matrix);

int access(matrix_t *matrix, int lin, int col);
int is_symmetrical(matrix_t *matrix);
int search(matrix_t *matrix, int length, int target);
int is_square(matrix_t *matrix);
int equals(matrix_t *matrix_A, matrix_t *matrix_B);
int is_identity(matrix_t *matrix);

void free_matrix(matrix_t *matrix);
void add(matrix_t *matrix, int lin, int col, int value);
void print_matrix(matrix_t *matrix);
void replace_number(matrix_t *matrix, int lin, int col, int new_number);
void fill_matrix_random(matrix_t *matrix, int range, unsigned int seed);
void fill_matrix(matrix_t *matrix, int number);

#endif
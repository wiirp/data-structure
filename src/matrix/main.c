// typedef int Matirx4[4][4];

#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

/* test only */

int main() {
    // int m[4][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}} -- 4 lines 3 collums

    /* or */
    /*  int m[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12}; */

    //  5.0   10.0  15.0 
    //  20.0  25.0  30.0
    //  35.0  40.0  45.0
    //  50.0  55.0  60.0

    // void f (..., float (*m)[3], ...) 

    // int m[3][3] = {1,2,3,4,5,6,7,8,9};

    // printf("%d\n", m[1][1]); = 5

    matrix_t *matrix;
    matrix = create(2, 2);

    add(matrix, 0, 0, 1);
    add(matrix, 0, 1, 2);
    add(matrix, 1, 0, 3);
    add(matrix, 1, 1, 4);
    
    // 1 2 
    // 3 4
        
    // printf("%d\n", access(matrix, 0, 0));
    // printf("%d\n", access(matrix, 0, 1));
    // printf("%d\n", access(matrix, 1, 0));
    // printf("%d\n", access(matrix, 1, 1));

    // int m[2][2] = {1,2,3,4};

    // for (int i = 0 ; i < 4; i++) printf("%d\n", m[0][i]);
    // for (int i = 0 ; i < 4; i++) printf("%d\n", m[i][i]);

    // printf("%d\n", m[0][4]);

    printf("%d\n", search(matrix, 4, 4));
    
    printf("%d\n", is_square(matrix));

    free_matrix(matrix);

    return 0;
}
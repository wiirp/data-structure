#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* test only */

int main() {
    stack_t *stack;
    stack = init();
    
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    getAll(stack);

    pop(stack);
    
    printf("\n");
    
    getAll(stack);

    free_stack(stack);

    return 0;
}
#ifndef STACK_HEADER
#define STACK_HEADER

#define MAX 6

typedef struct stack stack_t;

stack_t *init();
void push(stack_t *stack, int value);
void pop(stack_t *stack);
int peek(stack_t *stack);
void getAll(stack_t *stack);
void free_stack(stack_t *stack);

#endif
#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#define MAX 6

typedef struct queue queue_t;

queue_t *init();
void push(queue_t *queue, int value);
void pop(queue_t *queue);
void getAll(queue_t *queue);
void free_queue(queue_t *queue);

#endif
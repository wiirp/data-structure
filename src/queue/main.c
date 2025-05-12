#include <stdio.h>
#include "queue.h"

/* test only */

int main(int argc, char *argv[]) {
    queue_t *queue;
    queue = init();

    push(queue, 10);
    push(queue, 20);
    push(queue, 30);

    getAll(queue);

    pop(queue);

    printf("\n");

    getAll(queue);

    return 0;
}
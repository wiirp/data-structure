#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

typedef struct node node_t;

typedef struct list list_t;

list_t *init();
node_t *create_node(int value);
void add(list_t *list, int value);
void print(list_t *list);

#endif
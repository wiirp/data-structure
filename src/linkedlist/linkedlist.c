#include "linkedlist.h"

typedef struct node
{
    int value;
    node_t *next;
} node_t ;

typedef struct list
{
    node_t *head;
    node_t *last;
    size_t size;
} list_t ;

list_t *init() {
    list_t *list;
    list = (*list_t) malloc(sizeof(list_t));

    if (list == NULL) exit(EXIT_FAILURE);

    list->head = NULL;
    list->last = NULL;
    list->size = 0;
    return list; 
}

static node_t *create_node(int value) {
    node_t *new_node;
    new_node = malloc(sizeof(node_t));

    if (new_node == NULL) exit(EXIT_FAILURE); 

    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

enum status add(list_t *list, int value) {
    if (list == NULL) return LK_ERR_NULL_LIST;

    if (list->size == MAX) return LK_ERR_MAX_LIST_LIMIT;

    node_t *current;
    if (list->head == NULL) {
        node_t *node_head = create_node(value);
        list->head = node_head;
        list->last = node_head;

        return LK_OK;
    } else {
        current = list->head;
        while(current->next != NULL) {
            current = current->next;
        }

        current->next = create_node(value);
        list->last = current->next;
    }

    list->size = list->size + 1;
    return LK_OK;
}

enum status get_first(list_t *list) {
    if (list->head == NULL) return LK_ERR_NULL_LIST;
    
    return LK_OK;
}

enum status get_last(list_t *list) {
    if (list->last == NULL) return LK_ERR_NULL_LIST;

    return LK_OK;
}

int get_first_value(list_t *list) {
    if (list->head == NULL) return LK_ERR_NULL_LIST;

    return list->head->value;
}

int get_last_value(list_t *list) {
    if (list->last == NULL) return LK_ERR_NULL_LIST;

    return list->last->value;
}

size_t get_size(list *list) {
    if (list->head == NULL) return LK_ERR_NULL_LIST;

    return list->size;
}

void free_all(list *list) {
    node_t *current;

    current = list->head;
    for (int i = 0 ; i < list->size; i++) {
        current = current->next;

        free(current->next);
    }

    free(list);
}

void print_all(list_t *list) {
    node_t *current = list->head;

    while(current->next != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
    printf("%d\n", current->value); /* print the last one */
}

enum status remove_first(list_t *list) {
    if (list->head == NULL) return LK_ERR_NULL_LIST;
    // VERIFY(list->head, ...);

    if (list->size == 1) return LK_ERR_HEAD_AS_LAST;

    node_t *current = list->head;
    list->head = current->next;

    return LK_OK;
}

enum status remove_last(list_t *list) {
    if (list->head == NULL && list->last == NULL) return LK_ERR_NULL_LIST;

    if (list->size == 1 && list->head == NULL) {
        list->head = NULL;
        list->last = NULL;
        list->size = 0;
    } else list->last = NULL;

    return LK_OK;
}

int get_value(list_t *list, int index) {
    node_t *current;
    int value = 0;

    
}

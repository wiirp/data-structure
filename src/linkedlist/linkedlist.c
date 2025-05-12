#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct node
{
    int value;
    node_t *next;
};

struct list
{
    node_t *head;
};

list_t *init() {
    list_t *list;
    list = malloc(sizeof(list_t));

    if (list == NULL) exit(EXIT_FAILURE);

    list->head = NULL;
    return list; 
}

node_t *create_node(int value) {
    node_t *new_node;
    new_node = malloc(sizeof(node_t));

    if (new_node == NULL) exit(EXIT_FAILURE); 

    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

void add(list_t *list, int value) {
    node_t *current;
    if (list->head == NULL) {
        list->head = create_node(value);
    } else {
        current = list->head;
        while(current->next != NULL) {
            current = current->next;
        }

        current->next = create_node(value);
    }
}

void delete(list_t *list, int value) {
    if (list->head == NULL) exit(EXIT_FAILURE);

    node_t *current = list->head;
    node_t *previous = NULL;

    while (current->value != value) {
        
    }
}

void print(list_t *list) {
    node_t *current = list->head;

    while(current->next != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
    printf("%d\n", current->value); /* print the last one */
}
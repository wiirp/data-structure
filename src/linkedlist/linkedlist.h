#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define DEBUG 1
#define VERIFY_HEAD(a, b) if (a == NULL && b == NULL) return LK_ERR_NULL_LIST

typedef struct node node_t;
typedef struct list list_t;

enum status {
    LK_OK                 = 0,
    LK_ERR_MAX_LIST_LIMIT = 1,
    LK_ERR_NULL_NODE      = 2,
    LK_ERR_NULL_LIST      = 3,
    LK_ERR_HEAD_IS_LAST   = 4;
};

list_t         *init           (void);
static node_t  *create_node    (int value);

enum status    add             (list_t *list, int value);
enum status    get_first       (list_t *list);
enum status    get_last        (list_t *list);
enum status    remove_first    (list_t *list);
enum status    remove_last     (list_t *list);

int            get_first_value (list_t *list);
int            get_last_value  (list_t *list);
int            get_value       (list_t *list, int index);

int * 

size_t         get_size        (list_t, *list);

void           free_all        (list_t, *list);
void           print_all       (list_t *list);

#endif
#include "linkedlist.h"

/* test only */

int main(int argc, char *argv[]) {
    list_t *list;
    list = init();

    add(list, 10);
    add(list, 20);
    add(list, 30);
    add(list, 40);
    print(list);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[30];
    int quantity;
} item_t;

item_t *create(char *name, int quantity) {
    item_t *item = malloc(sizeof(item_t));

    if (item != NULL) {
        memcpy(item->name, name, strlen(name) + 1);
        item->quantity = quantity;
    } else exit(EXIT_FAILURE);

    return item;
}

int main(void) {
    item_t **array = NULL;
    char name[30];
    int quantity;
    int count = 0;

    while (1) {
        printf("Enter item name (exit to break)");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) break;

        printf("quantity");
        scanf("%d", &count);

        item_t **temp = realloc(array, (count + 1) * sizeof(item_t));
        array = temp;
        array[count] = create(name, quantity);
        count++;
    }

    return 0;
}
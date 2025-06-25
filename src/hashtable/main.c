#include "hashtable.h"

int main() {
    #if DEBUG == 1
        generic_function();
        int *array[MAXDEBUG];

        for (int i = 0; i < MAXDEBUG; i++) array[i] = NULL;

        p_t *p;
        p = init("Teste", 20);

        insert(p, array);
        printf("%d\n", get(p, array));

        printf("Array size: %d\n", size(array));

        p_t *new_p;
        new_p = clone(p);
        
        free(p);
        free(new_p);
        for (int i = 0; i < MAXDEBUG; i++) free(array[i]);
    #else if
        printf("Debug off");
    #endif

    // ...

    return 0;
}

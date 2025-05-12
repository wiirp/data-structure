#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *array;
    int *ptr;
    int input;
    int length = 0;

    array = malloc(sizeof(int));

    while (input > 0) {
        printf("Enter a number (to stop digit -1)");
        scanf("%d", &input);
        length++;

        ptr = realloc(array, length * sizeof(int));
        array = ptr;
        array[length - 1] = input;
        
    }

    for(int i = 0; i < sizeof(ptr); i++) printf("%d\n", array[i]);

    free(ptr);

    return 0;
}
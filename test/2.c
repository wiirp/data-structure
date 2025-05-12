#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[30];
    int age;

} student_t ;

student_t *create(char *name, unsigned int age) {
    student_t *student;
    student = malloc(sizeof(student_t));
    
    if (student != NULL) {
        memcpy(student->name, name, 30);
        student->age = age;
    }

    return student;
}

int main() {
    student_t **array = NULL;
    char name[30];
    int age;
    int count;

    while (1) {
        printf("Enter a name (exit to break)");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) break;

        printf("Enter age");
        scanf("%d", &age);

        student_t **temp = realloc(array, (count + 1) * sizeof(student_t));
        array = temp;
        array[count] = create(name, age);
        count++;
    }

    printf("\nLista de estudantes:\n");
    for (int i = 0; i < count; i++) {
        printf("Nome: %s, Idade: %d\n", array[i]->name, array[i]->age);
    }

    return 0;
}

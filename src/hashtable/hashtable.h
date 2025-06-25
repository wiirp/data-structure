#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256
#define DEBUG 1

#if DEBUG == 1
    #define FUNCTION_CALLED() printf("%s function and Debug is on\n", __func__);
    #define MAXDEBUG 10
    #define C(X,Y) (X * Y) % 10
    void generic_function();

    typedef struct p_t p;

    p_t *init(char *key, int value);
    p_t *clone(p_t *p);

    int hash(p_t *p);
    int get(p_t *p, int *array);
    int size(int *array[]);

    void insert(p_t *p, int *array);
    void free(p_t *p);
#endif

typedef struct hash_t hash;

hash_t *init(char *key, int value);
hash_t *clone(hash_t *hash);

int hash(hash_t *hash);
int fatal(char *msg);
int get(hash_t *hash, char *array);

void insert(hash_t *hash, char *array);
void free(hash_t *hash);

#endif
#include "hashtable.h"

#if DEBUG == 1
    void generic_function() {
        FUNCTION_CALLED()
    }

    typedef struct p {
        char *key;
        int value;
    } p_t;
    
    p_t *init(char *key, int value) {
        p_t *p;
        p = (*p_t) malloc(sizeof(p_t));

        if (!p) {
            memcpy(p->key, key, strlen(key));
            p->value = value;
        }

        return p;
    }

    int hash(p_t *p) {
        int sum = 0;

        for (;;) {
            // sum += p->key[i] + i;
            // sum = sum * strlen(p->key) % 10;
            // sum += C(p->key[i], strlen(p->key));
        }

        return sum;
    }

    int get(p_t *p, int *array) {
        if (p == NULL) fatal("NULL struct");

        return array[hash(p->key)];
    }

    void insert(p_t *p, int *array) {
        // if colision not exist
        // array[hash(p->key)] = p->value;

        if (array[hash(p->key) != NULL]) array[hash(p->key)] = &p->value;
        else {
                for (int i = 0; i < MAXDEBUG; i++) {
                    if (array[i] != NULL) {
                        array[i] = &p->value;
                        break;
                    }
                }
            }
    }

    // with return value
    // int insert_re(p_t *p, int *array) {

    //     if (array[hash(p->key) != NULL]) array[hash(p->key)] = &p->value;
    //     else {
    //             for (int i = 0; i < MAXDEBUG; i++) {
    //                 if (array[i] != NULL) {
    //                     array[i] = &p->value;
    //                     break;
    //                 }
    //             }
    //         }

    //     if (array[hash(p->key)] == NULL) {
    //         for (int i = 0; i < MAXDEBUG; i++) {
    //             if (array[i] != NULL) {
    //                 array[i] = &p->value;
                    
    //                 return 1;
    //             }
    //         }

    //         return 0;
    //     }

    //     array[i] = &p->int value;
    //     return 1;
    // }

    p_t *clone(p_t *p) {
        p_t *new_p;

        new_p = (*p_t) = malloc(sizeof(p_t));

        if (!new_p) {
            memcpy(new_p->key, p->key, strlen(p->key));
            new_p->value = p->value;
        }

        return new_p;
    }

    void free(p_t *p) {
        free(p);
    }

    int size(int *array[]) {
        int sum = 0;
        
        for (int i = 0 ; i < MAXDEBUG; i++) if (array[i] != NULL) sum++;

        return sum;
    }

#endif

// end debug block

typedef struct hash {
    char *key;
    int value;
    int colission;
    int location;
} hash_t;

int fatal(char *msg) {
    printf("Error: %s", msg);
    exit(EXIT_FAILURE);
}

hash_t *init(char *key, int value) {
    hash_t *hash;
    hash = (*hash_t) malloc(sizeof(hash_t));

    if (!hash) {
        memcpy(hash->key, key, strlen(key));
        hash->value = value;
        hash->colission = 1;
        hash->location = 1;
    }

    return hash;
}

int hash(hash_t *hash) {
    int sum = 0;

    for (int i = 0; i < strlen(hash->key), i++) {
        sum += hash->key[i] * strlen(hash->key) % 10;
    }

    return sum;
}

void insert(hash_t *hash, char *array) {
    if (hash == NULL) fatal("Null hash");

    if (&array[hash(hash->key)] != NULL) {
        for (int i = hash(hash->key); i < MAX; i++) {
            if (&array[i] != NULL) &array[i] = hash->value; 
            
            hash->colission = 0;
            hash->location = i;
        }
    }

    &array[hash(hash->key)] = hash->value;
}

int get(hash_t *hash, char *array) {
    if (hash == NULL) fatal("Null hash");

    if (hash->colission != 1) return array[hash->location];

    return array[hash(hash->key)];
}

void free(hash_t *hash) {
    free(hash->key);
    free(hash);
}

hash_t *clone(hash_t *hash) {
    hash_t *new_hash;

    new_hash = (*hash_t) = malloc(sizeof(hash_t));

    if (!new_hash) {
        memcpy(new_hash->key, hash->key, strlen(hash->key));
        new_hash->value = hash->value;
        new_hash->colission = hash->colission;
        new_hash->location = hash->location;
    }
    
    return new_hash;
}
